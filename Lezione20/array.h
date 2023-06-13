#ifndef ARRAY_H_
#define ARRAY_H_

#define HIGH 100
#define LOW -100

int * creaArray (const unsigned int);
void distruggiArray (int *);
void inizializzaArrayRandom (int *, const unsigned int, const unsigned int);
void inizializzaArraySeq (int *, const unsigned int);
void stampaArray (int * const, const unsigned int);
int ** creaMatrice (const unsigned int);
void distruggiMatrice (int **, const unsigned int);
int ** creaMatriceContigua (const unsigned int);
void distruggiMatriceContigua (int **);
void stampaMatrice (int **, const unsigned int);
void inizializzaMatrice (int **, const unsigned int);
const unsigned int scanMatrice (const int, int ** const, const unsigned int);

#endif