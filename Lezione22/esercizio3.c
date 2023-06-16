/*
Sia dato un file di testo ‘agenda.txt’ contenente gli appuntamenti di una persona ordinati per data e orario. 
Le informazioni sono così strutturate:
ciascuna riga contiene una data (gg/mm) seguita dal numero N di appuntamenti per quella data.
Seguono esattamente N coppie ognuna contenente un orario (hh) e una descrizione (in forma di stringa senza spazi di al più 30 caratteri).
Scrivere un programma che dati in input due interi (rappresentati la data) e due interi (rappresentanti un orario iniziale e uno finale)
restituisca in output la descrizione degli appuntamenti per quella data nell’intervallo di tempo specificato.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "esercizio3.h"

/*
Scrivere un programma che dati in input due interi (rappresentati la data) e due interi (rappresentanti un orario iniziale e uno finale)
restituisca in output la descrizione degli appuntamenti per quella data nell’intervallo di tempo specificato.
*/

struct descrizioni * creaNodo (const char * descript){
    struct descrizioni * nuovo = malloc (sizeof(struct descrizioni));
    if (nuovo==NULL){
        fprintf(stderr, "Errore nell'allocazione della memoria.\n");
    }
    else {
        strcpy(nuovo->descrizione,descript);
        nuovo->next=NULL;
    }
    return nuovo;
}

void stampaLista (struct descrizioni * list){
    while (list!=NULL){
        printf("%s", list->descrizione);
        list=list->next;
    }
    return;
}

void distruggiLista (struct descrizioni * list){
    struct descrizioni * prec=NULL;
    while (list!=NULL){
        prec=list;
        list=list->next;
        free(prec);
    }
    return;
}

FILE * apriFile (const char * nomeFile){
    FILE * f = fopen (nomeFile, "r");
    if (f==NULL){
        fprintf(stderr, "Errore nell'apertura del file.\n");
        return NULL;
    }
    else return f;
}

int chiudiFile (FILE * f){
    if (fclose(f)!=0){
        fprintf(stderr, "Errore nella chiusura del file.\n");
        return 0;
    }
    else return 1;
}

struct descrizioni * controllaAppuntamenti (const unsigned int giorno, const unsigned int mese, const unsigned int t0, const unsigned int t1){
    const char * nomeFile = NOME_FILE;
    FILE * agenda = apriFile(nomeFile);
    if (agenda==NULL){
        return NULL;
    }

    struct descrizioni * risultato = NULL;
    struct descrizioni * temp = risultato;

    struct data D;
    unsigned int numAppuntamenti=0;
    
    while (feof(agenda)==0){
        if (fscanf(agenda, " %u", &D.gg) && 
        fscanf(agenda, " %c") && 
        fscanf(agenda, " %u", &D.mm) && 
        fscanf(agenda, " %u", &numAppuntamenti) != 1){
            fprintf(stderr, "Errore nella lettura del file: data.\n");
            chiudiFile(agenda);
            return NULL;
        }

        //printf("Appuntamenti del %u/%u: %u\n", D.gg, D.mm, numAppuntamenti);

        if (D.gg==giorno && D.mm==mese){
            // printf("Giorno e mese corrispondenti trovati.\n");
            struct appuntamento * A = malloc (sizeof(struct appuntamento)*numAppuntamenti);
            if (A==NULL){
                fprintf(stderr, "Errore nell'allocazione della memoria.\n");
                chiudiFile(agenda);
                return NULL;
            }

            for (int i=0;i<numAppuntamenti;i++){
                if (fscanf(agenda, " %u", &A[i].hh) != 1) {
                    fprintf(stderr, "Errore nella lettura del file: ora.\n");
                    chiudiFile(agenda);
                    return NULL;
                    }
                

                //printf("ore %u:00 - ", A[i].hh);

                if (fscanf(agenda, " %s", &A[i].descrizione)!=1){
                    fprintf(stderr, "Errore nella lettura del file: descrizione.\n");
                    chiudiFile(agenda);
                    return NULL;
                }

                //printf("%s\n", A[i].descrizione);

                if (A[i].hh>=t0 && A[i].hh<=t1){
                    temp=creaNodo(A[i].descrizione);
                    if (temp!=NULL){
                        printf("%s. " ,temp->descrizione);
                        temp=temp->next;
                    }
                    else {
                        distruggiLista(risultato);
                        chiudiFile(agenda);
                        free(A);
                        fprintf(stderr, "Errore nell'allocazione della memoria.\n");
                        return NULL;
                    }
                }
            }
            
            free(A);
            chiudiFile(agenda);
            
            return risultato;
        }

        else {
            //printf("Giorno e mese non corrispondenti.\n");
                 
            for (int i=0;i<numAppuntamenti;i++){
                unsigned int ora_temp=0;
                char descrizione_temp [MAX_SIZE_DESCRIPTION];
                
                if (fscanf(agenda, " %u", &ora_temp) && fscanf(agenda, " %s", &descrizione_temp) !=1){
                    fprintf(stderr, "Errore nella lettura del file.\n");
                    chiudiFile(agenda);
                }   
            }    
        }
    }
    return NULL;
}



//-----------------------------------------------------------------------------------
//ALTRO
int stampaAgenda (const char * nomeFile){
    FILE * agenda = fopen (nomeFile, "r");
    if (agenda==NULL){
        fprintf(stderr, "Errore nell'apertura del file.");
        return 1;
    }

    struct data D;
    unsigned int numAppuntamenti=0;
    struct appuntamento * A = NULL;

    while (feof(agenda)==0){
        if (fscanf(agenda, " %u", &D.gg) &&
            fscanf(agenda, " %c") &&
            fscanf(agenda, " %u", &D.mm) &&
            fscanf(agenda, " %u", &numAppuntamenti) != 1){
            fprintf(stderr, "Errore nella lettura del file.");
            return 1;
        }
        else {
            printf("%u/%u, %u appuntamenti: ", D.gg, D.mm, numAppuntamenti);
            A = malloc (numAppuntamenti * sizeof(struct appuntamento));
            if (A==NULL){
                fprintf(stderr, "Errore nell'allocazione della memoria.");
                return 1;
            }
            for (int i=0; i<numAppuntamenti; i++){
                if (fscanf(agenda, " %u", &A[i].hh) &&
                    fscanf(agenda, " %s", &A[i].descrizione) != 1){
                    free(A);
                    fprintf(stderr, "Errore nella lettura del file.");
                    return 1;
                }
                else {
                    printf("%u:00 %s; ", A[i].hh, A[i].descrizione);
                }
            }
            free(A);
            printf("\n");
        }
    }

    if (fclose(agenda)==0){
        return 0;
    }
    else {
        fprintf(stderr, "Errore nella chiusura del file.");
        return 1;
    }
}