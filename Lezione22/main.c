/*
Gestione registro esame. Un registro degli esami è memorizzato in
un file di testo con nome ‘‘registro.txt’’ dove sulla prima riga è
riportato il numero N degli studenti. Ogni altra riga contiene il dato
relativo ad un singolo studente, indicando il numero di matricola
dello studente (numero intero compreso 1 e 999999), il voto
conseguito (numero intero con valore tra 18 e 30). Scrivere un
programma che consenta all’utente di scegliere tre opzioni:
• Opzione ‘media’: il programma deve fornire il voto medio degli
studenti promossi (indicato con una sola cifra dopo la virgola).
• Opzione ‘voto’: in questo caso, l’utente inserisce da tastiera un
numero di matricola e il voto conseguito dallo studente. Il
programma deve aggiornare il file inserendo i nuovi dati,
segnalando però un errore nel caso in cui lo studente abbia già
superato l’esame.
• Uscita dal programma
*/

#include <stdio.h>
#include <stdlib.h>
#include "esercizio1.c"
#include "esercizio3.c"

int Esercizio1();
int Esercizio3();

int main (){
    int Esercizio = 0;
    printf("Digitare il numero dell'esercizio da svolgere: ");
    if (scanf (" %d", &Esercizio)!=1){
        fprintf(stderr, "Errore di input.\n");
        return 1;
    }
    switch (Esercizio) {
        
        case 1:
        return Esercizio1();
        break;

        case 3:
        return Esercizio3();
        break;

        default:
        printf("L'esercizio non esiste o non e' stato svolto.\n");
        return 0;
        break;
    }
}

int Esercizio1 (){
    const char* nomeFile = "registro.txt";

    unsigned int opzioni = 0;
    while (opzioni == 0 || opzioni == 1 || opzioni == 2){
        printf("\nDigitare 0 per visualizzare i voti di ogni studente.\n"
            "Digitare 1 per visualizzare la media dei voti.\n"
            "Digitare 2 per inserire matricola e voto di un nuovo studente.\n"
            "Digitare qualsiasi altro numero per uscire.\n");
        if (scanf(" %u", &opzioni)!=1){
            fprintf(stderr, "Errore di input.\n");
            return 1;
        }

        switch (opzioni){
            case 0:
                printFile(nomeFile);
                break;

            case 1:
                printf("La media dei voti e': %.1f\n", getMedia(nomeFile));
                break;

            case 2:
            
                unsigned int matricola, voto;
                printf("Inserire matricola e voto:\n");
                if (scanf(" %u %u", &matricola, &voto)==0){
                    fprintf(stderr, "Errore in lettura.\n");
                    return 1;
                }
                else if (voto>30 || voto<18){
                    fprintf(stderr, "Errore: il voto deve essere compreso tra 18 e 30.\n");
                    return 1;
                }
                else if (matricola<1 || matricola > 999999){
                    fprintf(stderr, "Errore: matricola non valida.\n");
                    return 1;
                }
            
                setVoto(nomeFile, matricola, voto);
                break;

            default:
                return 0;
        }
    }
}




int Esercizio3 (){
    unsigned int giorno=0, mese=0, t0=0, t1=0;

    printf("Inserire giorno e mese: ");
    if (scanf (" %u", &giorno) && scanf (" %u", &mese)!=1){
        fprintf(stderr, "Errore di input.\n");
        return 1;
    }
    if (giorno<=0 || giorno > 31 || mese <= 0 || mese > 12){
        fprintf(stderr, "Errore: inserire una data valida.\n");
        return 1;
    }

    printf("Inserire fascia oraria: ");
    if (scanf (" %u", &t0) && scanf (" %u", &t1) !=1){
        fprintf (stderr, "Errore di input.\n");
        return 1;
    }
    if (t1 < t0){
        fprintf (stderr, "Errore: inserire gli orari in ordine cronologico.\n");
        return 1;
    }
    if ((t1 < 0) || (t0 > 24) || (t1 < 0) || (t1 > 24)){
        fprintf (stderr, "Errore: inserire un orario valido.\n");
        return 1;
    }

    struct descrizioni * appointments = controllaAppuntamenti(giorno, mese, t0, t1);
    
    stampaLista(appointments);
    distruggiLista(appointments);
    return 0;
}