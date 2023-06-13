#ifndef LISTE_CONC_H_
#define LISTE_CONC_H_

struct nodo {
    int dati;
    struct nodo * nextElem;
};
typedef struct nodo * lista;

lista creaNodo (int);
lista InserimentoOrdinato (int, lista);
lista InserimentoInCoda (int, lista);
lista InserimentoInTesta (int, lista);
void stampaLista (lista);
void distruggiLista (lista);

#endif