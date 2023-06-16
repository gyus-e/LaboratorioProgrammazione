#include <stdio.h>
#include <stdlib.h>
#include "esercizio1.h"

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

//setVoto restituisce 0 se il file non viene modificato, 
//1 se viene modificato con successo, 
//-1 se le modifiche non sono corrette (il numero di studenti viene incrementato senza aggiungere matricola e voto del nuovo studente)
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
    else {
        numStudenti++;
        fprintf(registro, " %u", numStudenti);
    }

    while (feof(registro)==0){
        if (fscanf (registro, " %u %u", &matricola, &voto)==0){
            fprintf(stderr, "Errore nella lettura dei dati dal file.");
            return -1;
        }
        else if (matricola==newMatricola){
            fprintf(stderr, "Lo studente ha gia' sostenuto l'esame.\n");
            return -1;
        }
    }

    fprintf(registro, "\n%u %u", newMatricola, newVoto);
    
    if (fclose (registro)!=0){
        fprintf(stderr, "Errore nella chiusura del file '%s'\n", nomeFile);
        return 0;
    }
    else 
        return 1;
}

//decreaseNumStudenti viene chiamata se setVoto restituisce -1
//(cioé se il numero di studenti è stato incrementato senza aggiungere i dati di un nuovo studente)
//restituisce -1 se il file non viene modificato, 
//0 se viene modificato con successo ma ci sono problemi alla chiusura,
//1 per una corretta esecuzione.
int decreaseNumStudenti (const char * nomeFile){
    FILE * registro = fopen (nomeFile, "r+");
    if (registro == NULL){
        fprintf(stderr, "Problema nell'apertura del file '%s'\n", nomeFile);
        return -1;
    }
    unsigned int numStudenti = 0;
    if (fscanf(registro, " %u", &numStudenti)==0){
        fprintf(stderr, "Errore nella lettura dei dati dal file.");
        return -1;
    }
    else {
        numStudenti--;
        fprintf(registro, " %u", numStudenti);
    }

    if (fclose (registro)!=0){
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
        return 1;
    }

    unsigned int matricola=0, voto=0, numStudenti=0;

    if (fscanf (registro, " %u", &numStudenti)==0){
        fprintf(stderr, "Errore nella lettura dei dati dal file.");
        return 1;
    }
    printf("ci sono %u studenti.\n", numStudenti);

    while (feof(registro)==0){
        if (fscanf(registro, " %u %u", &matricola, &voto) == 0){
            fprintf(stderr, "Errore nella lettura dei dati dal file.");
            return 1;
        }
        else {
            printf("La matricola %u ha voto %u\n", matricola, voto);
        }
    }

    if (fclose (registro)==0){
        return 0;
    }
    else {
        fprintf(stderr, "Errore nella chiusura del file '%s'\n", nomeFile);
        return 2;
    }
}