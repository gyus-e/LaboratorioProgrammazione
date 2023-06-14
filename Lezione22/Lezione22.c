#include <stdio.h>
#include <stdlib.h>
#include "lezione22.h"

/*
Opzione ‘media’: il programma deve fornire il voto medio degli
studenti promossi (indicato con una sola cifra dopo la virgola).
*/
float getMedia (const char* nomeFile){
    FILE * registro = fopen (nomeFile, "r");
    if (registro == NULL){
        fprintf(stderr, "Problema nell'apertura del file '%s'\n", nomeFile);
        return 0;
    }

    unsigned int matricola=0, voto=0, sommaVoti=0, numStudenti=0;

    if (fscanf (registro, " %u", &numStudenti)==0){
        fprintf(stderr, "Errore nella lettura dei dati dal file.");
        return 0;
    }

    while (feof(registro)==0){
        if (fscanf(registro, " %u %u", &matricola, &voto) == 0){
            fprintf(stderr, "Errore nella lettura dei dati dal file.");
            return 0;
        }
        else {
            sommaVoti+=voto;
        }
        
    }

    if (fclose (registro)==0){
        return (float) sommaVoti/numStudenti;
    }
    else {
        fprintf(stderr, "Errore nella chiusura del file '%s'\n", nomeFile);
        return 0;
    }
}

/*
Opzione ‘voto’: in questo caso, l’utente inserisce da tastiera un
numero di matricola e il voto conseguito dallo studente. Il
programma deve aggiornare il file inserendo i nuovi dati,
segnalando però un errore nel caso in cui lo studente abbia già
superato l’esame.
*/
int setVoto (const char * nomeFile, unsigned int newMatricola, unsigned int newVoto){
    FILE * registro = fopen (nomeFile, "r+");
    if (registro == NULL){
        fprintf(stderr, "Problema nell'apertura del file '%s'\n", nomeFile);
        return 0;
    }
    unsigned int matricola=0, voto=0, numStudenti=0;
    
    if (fscanf(registro, " %u", &numStudenti)==0){
        fprintf(stderr, "Errore nella lettura dei dati dal file.");
        return 0;
    }

    while (feof(registro)==0){
        if (fscanf (registro, " %u %u", &matricola, &voto)==0){
            fprintf(stderr, "Errore nella lettura dei dati dal file.");
            return 0;
        }
        else if (matricola==newMatricola){
            fprintf(stderr, "Lo studente ha gia' sostenuto l'esame.\n");
            return 0;
        }
    }

    fprintf(registro, "\n%u %u", newMatricola, newVoto);
    numStudenti++;
    
    if (fclose (registro)!=0){
        fprintf(stderr, "Errore nella chiusura del file '%s'\n", nomeFile);
        return 0;
    }

    FILE * posNumStudenti = fopen (nomeFile, "r+");
    fprintf(posNumStudenti, "%u", numStudenti);
    if (fclose (posNumStudenti)!=0){
        fprintf(stderr, "Errore nella chiusura del file '%s'\n", nomeFile);
        return 0;
    }
    else 
        return 1;
}


//Altro
int printFile (const char* nomeFile){
    FILE * registro = fopen (nomeFile, "r");
    if (registro == NULL){
        fprintf(stderr, "Problema nell'apertura del file '%s'\n", nomeFile);
        return 0;
    }

    unsigned int matricola=0, voto=0, numStudenti=0;

    if (fscanf (registro, " %u", &numStudenti)==0){
        fprintf(stderr, "Errore nella lettura dei dati dal file.");
        return 0;
    }
    printf("ci sono %u studenti.\n", numStudenti);

    while (feof(registro)==0){
        if (fscanf(registro, " %u %u", &matricola, &voto) == 0){
            fprintf(stderr, "Errore nella lettura dei dati dal file.");
            return 0;
        }
        else {
            printf("La matricola %u ha voto %u\n", matricola, voto);
        }
    }

    if (fclose (registro)==0){
        return 1;
    }
    else {
        fprintf(stderr, "Errore nella chiusura del file '%s'\n", nomeFile);
        return 0;
    }
}