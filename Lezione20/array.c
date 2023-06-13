#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int * creaArray (const unsigned int SIZE){
    if (SIZE ==0) return NULL;
    int * ptr = malloc (SIZE * sizeof(int));
    return ptr;
}

void distruggiArray (int * ptr){
    free (ptr);
    return;
}

void inizializzaArrayRandom (int * ptr, const unsigned int SIZE, const unsigned int I){
    srand(I);
    for (int i=0;i<SIZE;i++){
        ptr[i]=rand() % (HIGH + 1 - LOW) + LOW;
    }
    return;
}

void inizializzaArraySeq (int * ptr, const unsigned int SIZE){
    for (int i=0;i<SIZE;i++){
        ptr[i]=i;
    }
    return;
}

void stampaArray (int * const ptr, const unsigned int SIZE){
    for (int i=0;i<SIZE;i++){
        printf("%d ", ptr[i]);
    }
    return;
}

int ** creaMatrice (const unsigned int SIZE){
    if (SIZE==0) return NULL;
    int ** matrice = malloc (SIZE * (sizeof(int*)));
    for (int i=0;i<SIZE;i++){
        matrice[i] = creaArray(SIZE);
    }
    return matrice;
}

void distruggiMatrice (int ** mat, const unsigned int SIZE){
    for (int i=0;i<SIZE;i++){
        distruggiArray(mat[i]);
    }
    free (mat);
    return;
}

int ** creaMatriceContigua (const unsigned int SIZE){
    if (SIZE==0) return NULL;
    int * vector = malloc (SIZE * SIZE * sizeof(int));
    int ** matrice = malloc (SIZE * (sizeof(int*)));
    for (int i=0;i<SIZE;i++){
        matrice[i] = &vector[i];
    }
    return matrice;
}

void distruggiMatriceContigua (int ** mat){
    free (mat[0]);
    free (mat);
    return;
}

void stampaMatrice (int ** mat, const unsigned int SIZE){
    for (int i=0;i<SIZE;i++){
        stampaArray(mat[i], SIZE);
        printf("\n");
    }
    return;
}

void inizializzaMatrice (int ** ptr, const unsigned int SIZE){
    for (int i=0;i<SIZE;i++){
        inizializzaArrayRandom(ptr[i], SIZE, i);
        //inizializzaArraySeq(ptr[i], SIZE);        //per testare la funzione verifica
    }
    return;
}

const unsigned int scanMatrice (const int x, int ** const M, const unsigned int SIZE) {
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            if (M[i][j]==x){
                return 1;
            }
        }
    }
    return 0;
}