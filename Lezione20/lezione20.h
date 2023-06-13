#include "array.h"
#include "liste_conc.h"

#ifndef LEZIONE20_H_
#define LEZIONE20_H_

//esercizi su matrici
//Es. 1
int * elaboraArray (int **, const unsigned int); 
//Es. 2
const unsigned int verifica (int ** const M, const unsigned int SIZE, const unsigned int k); 

//esercizi su liste concatenate
//Es. 6
lista numPrimi (lista); 
int numeroPrimo (int);
//Es. 7
lista mergeList(lista, lista);
//Es. 8
lista middleNode (lista);
lista mergeSort (lista);

#endif