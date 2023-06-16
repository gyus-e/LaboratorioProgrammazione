#include <stdio.h>
#include <stdlib.h>
#include "liste_conc.h"

lista creaNodo (int n){
    lista l = (lista) malloc (sizeof(lista));
    if (l!=NULL){
        l->dati=n;
        l->nextElem=NULL;
    }
    return l;
}

lista InserimentoOrdinato (int n, lista l){
    lista nuovo = creaNodo(n);

    if (l!=NULL && nuovo != NULL) {
        lista prec = NULL;
        lista curr = l;

        while (curr!=NULL && curr->dati <= n){
            prec = curr;
            curr = curr->nextElem;
        }
        nuovo->nextElem=curr;
        
        if (curr == l){
            return nuovo;
        }
        else {
            prec->nextElem=nuovo;
            return l;
        }
    }
    else {
        return nuovo;
    }
}

lista InserimentoInCoda(int n, lista l){
    lista nuovo = creaNodo(n);
    if (l!=NULL){
        lista temp = l;
        while (l->nextElem != NULL){
            l=l->nextElem;
        }
        l->nextElem=nuovo;
        return temp;
    }
    else {
        return nuovo;
    }
}

lista InserimentoInTesta (int n, lista l){
    lista nuovo = creaNodo(n);
    nuovo->nextElem=l;
    return nuovo;
}

void stampaLista (lista l){
    if (l==NULL){
        printf("La lista e` vuota.\n");
        return;
    }
    else {
        while (l!=NULL){
            printf("%d ", l->dati);
            l=l->nextElem;
        }
        return;
    }
}

void distruggiLista (lista l){
    if (l!=NULL){
        lista temp = NULL;
        while (l!=NULL){
            temp = l;
            l=l->nextElem;
            free(temp);
        }
    }
    return;
}