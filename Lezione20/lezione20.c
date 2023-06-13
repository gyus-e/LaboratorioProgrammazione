#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "liste_conc.h"
#include "lezione20.h"

//ESERCIZI SU MATRICI

/*
1. Scrivere una funzione elaboraArray che prende in input una
matrice quadrata M di interi N×N dove N è dispari, e restituisce un
vettore V (array monodimensionale) di interi contenente gli
elementi situati nelle 4 sottomatrici quadrate (lette per righe) che si
ottengono da M escludendo la riga e la colonna centrale (si veda
l’esempio sottostante).
*/

int * elaboraArray (int ** M, const unsigned int N){
    if (N % 2 == 0) {
        return NULL;
    }
    
    unsigned int size = (N*N)-(2*N-1);
    int * Array = creaArray(size);
    
    int medio = ((N-1)/2);

    int i=0, j=0, pos=0;
    while (i<N){
        if (i==medio){
            i++;
        }
        while (j<N){
            if (j==medio){
                j++;
            }
                Array[pos]=M[i][j];
                pos++;
                j++;
            }
        j=0;
        i++;
    }
    return Array;
}

/*
2. Implementare una funzione verifica che riceve in input una matrice
di interi M e un intero k positivo e restituisce true (valore 1) se M
contiene tutti gli interi da 1 a k, altrimenti restituisce false (valore
0).
*/

const unsigned int verifica (int ** const M, const unsigned int N, const unsigned int k){
    for (int count=0;count<k;count++) {
        if (scanMatrice(count, M, N)!=1){
            return 0;
        }
    }
    return 1;
}


/*
3. Implementare una funzione elaboraMatrice che riceve in input una
matrice quadrata di interi M e restituisce una matrice A ottenuta da
M eliminando gli elementi che appartengono alla diagonale
principale.
*/

/*
4. Implementare una funzione stampaSottoMatrici che riceve in
input una matrice di interi M e stampa a video tutte le sottomatrici
quadrate di M la cui somma di elementi è maggiore o uguale a zero.
*/

/*
5. Implementare una funzione che prenda in input due matrici quadrate
delle stesse dimensioni e restituisca il prodotto righe per colonne
delle due matrici.
*/

//--------------------------------------------------------------------------------------------------------------------------

//ESERCIZI SU LISTE CONCATENATE

/*
6. Scrivere una funzione che prenda in input una lista concatenata di
interi e restituisca una nuova lista contenente tutti e solo gli
elementi della prima lista che sono numeri primi.
*/

lista numPrimi (lista l){
    if (l==NULL){
        printf("La lista e` vuota.\n");
        return l;
    }
        else {
        lista lPrimi = NULL;
        while (l!=NULL){
            if (numeroPrimo(l->dati)==1){
                lPrimi = InserimentoOrdinato(l->dati, lPrimi);
            }
            l=l->nextElem;
        }
        if (lPrimi==NULL){
            printf("La lista non contiene numeri primi.\n");
        } 
        return lPrimi;
    }
}

int numeroPrimo (int n){
    if (n<=0){
        return 0;
    }
    else if (n==1){
        return 1;
    }
    else {
        for (int i=2;i<n-1;i++){
            if (n%i==0){
                return 0;
            }
        }
        return 1;
    }
}

/*
7. Scrivere una funzione che prenda in input due liste di interi
ordinate per valori crescenti e costruisca e restituisca una nuova
lista di interi ottenuta mediante la “fusione” delle prime due.
*/

lista mergeList (lista A, lista B){
    if (A==NULL){
        return B;
    }
    else if (B==NULL){
        return A;
    }
    else {
        lista merged = NULL;
        int temp = 0;
        while (A!=NULL){
            temp=A->dati;
            merged = InserimentoOrdinato(temp, merged);
            A=A->nextElem;
        }
        while (B!=NULL){
            temp=B->dati;
            merged = InserimentoOrdinato(temp, merged);
            B=B->nextElem;
        }
        return merged;
    }
}

/*
8. Scrivere una funzione che prenda in input una lista di interi e la
riordini per valori crescenti utilizzando in modo ricorsivo
l’algoritmo di ordinamento MergeSort
*/

lista middleNode (lista l){
    lista slow = l, fast = l->nextElem;
    while (fast!=NULL){
        fast=fast->nextElem;
        if (fast!=NULL){
            slow=slow->nextElem;
            fast=fast->nextElem;
        }
    }
    return slow;
}

lista mergeSort (lista l){ //crasha su liste con piú di 4 elementi
    if (l==NULL || l->nextElem==NULL){
        return l;
    }

    lista A = l;
    lista B = middleNode(l)->nextElem;
    middleNode(A)->nextElem=NULL;

    A=mergeSort(A);
    B=mergeSort(B);

    l=mergeList(A, B);
    return l;
}