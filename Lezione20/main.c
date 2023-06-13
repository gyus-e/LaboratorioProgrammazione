/*
Testare nel main le funzioni da implementare nei seguenti esercizi (1-5)
utilizzando funzioni ausiliarie per l’allocazione dinamica di array e
matrici e l’inizializzazione con valori da -100 a 100 scelti in modo
random.

Testare nel main le funzioni da implementare nei seguenti esercizi (6-8)
utilizzando funzioni per l’inserimento di dati da tastiera e la stampa di
liste concatenate.
*/

#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "liste_conc.h"
#include "lezione20.h"


int main (){

    unsigned int esercizio = 1;
    
    while (esercizio == 1 || esercizio == 2){

        printf("\nDigitare 1 per svolgere gli esercizi sugli array.\nDigitare 2 per svolgere gli esercizi sulle liste concatenate.\n");
        
        if (scanf(" %u", &esercizio) !=1){
            printf("errore.\n");
            return 1;
        }

        printf("\n");

        switch (esercizio) {
            case 1: //Esercizi su array

                //creazione Matrice
                unsigned int N = 0;
                printf ("Inserire dimensione array (dispari per esercizio 1): ");
                if (scanf(" %u", &N)!=1 || N == 0){
                    return 1;
                }

                int** matrix = creaMatriceContigua(N);  //Allocazione contigua
                //int** matrix = creaMatrice(N); //Allocazione non-contigua
                inizializzaMatrice(matrix, N);
                stampaMatrice(matrix, N);

                printf("\n");

                //Esercizio 1
                int * arrayElaborato = elaboraArray(matrix, N);

                if (arrayElaborato != NULL)
                    stampaArray(arrayElaborato, (N*N)-(2*N-1));
            
                printf("\n");

                //Esercizio 2
                unsigned int K=0;
                printf("Verificare se la matrice contiene tutti gli interi positivi fino a: ");
                if (scanf(" %u", &K)!=1 || K==0){
                    printf ("errore.\n");
                    //deallocazione memoria
                    distruggiArray(arrayElaborato);
                    distruggiMatriceContigua(matrix);   //Allocazione contigua 
                    //distruggiMatrice(matrix, N); //Allocazione non-contigua
                    return 1;
                }

                if (verifica(matrix, N, K)==1)
                    printf("La matrice contiene tutti gli interi positivi fino a %u\n", K);
                else 
                    printf("La matrice non contiene tutti gli interi positivi fino a %u\n", K);
                


                //deallocazione memoria
                distruggiArray(arrayElaborato);
                distruggiMatriceContigua(matrix);   //Allocazione contigua 
                //distruggiMatrice(matrix, N); //Allocazione non-contigua

                break;

            case 2: //Esercizi su liste concatenate
                
                lista L = NULL;
                int dati=0;

                printf("inserire dati. Digitare 0 per terminare.\n");                
                while (scanf(" %d", &dati)==1 && dati!=0){
                    L = InserimentoInCoda (dati, L);
                }

                printf("Lista inserita:\n");
                stampaLista(L);
                printf("\n");

                //Esercizio 6
                lista primi = numPrimi(L);
                if (primi!=NULL){
                    printf("La lista contiene i seguenti numeri primi:\n");
                    stampaLista(primi);
                }
                else {
                    printf("Non ci sono numeri primi nella lista.\n");
                }
                
                distruggiLista(primi);

                printf("\n");            

                //Esercizio 8
                L=mergeSort(L);
                printf("La lista ordinata e`:\n");
                stampaLista(L);

                printf("\n");

                //Esercizio 7
                lista toMerge = NULL;
                printf("Inserire elementi di un'altra lista.\n");
                while (scanf(" %d", &dati)==1 && dati!=0){
                    toMerge = InserimentoOrdinato (dati, toMerge);
                }

                lista merged = mergeList(L, toMerge);
                printf("La fusione delle due liste e`:\n");
                stampaLista(merged);
                printf("\n");

                distruggiLista(toMerge);
                distruggiLista(merged);


                distruggiLista(L);          
                break;
        }
    }

    return 0;
}
