#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "storage.h"


//? 1
void libertaLista (Palavras l){
    Palavras temp;

    while(l){
        temp = l->prox;
        free(l->palavra);
        free(l);
        l = temp;
    }
}

//? 2
int quantasP (Palavras l){
    Palavras aux;
    int count = 0;

    for(aux = l; aux; aux = aux->prox) count++;

    return count;
}

//? 3
void listaPal (Palavras l){
    Palavras aux;

    for(aux = l; aux; aux = aux->prox){
        printf("\t\tOcorr: %d\tPalavra: %s\n", aux->ocorr, aux->palavra);
    }
}

//? 4
char* ultima (Palavras l){
    Palavras aux;
    if(!l) return NULL;
    else if(!l->prox) return l->palavra;
    else{
        for (aux = l; aux->prox; aux = aux->prox);
        return aux->palavra;
    }
}

//? 5
Palavras acrescentaInicio (Palavras l, char *p){
    Palavras new = (Palavras) malloc(sizeof(struct celula));
    new->ocorr = 1;
    new->palavra = strdup(p);
    new->prox = l;
    return new;
}

//? 6
Palavras acrescentaFim (Palavras l, char *p){
    Palavras aux;
    Palavras new = (Palavras) malloc(sizeof(struct celula));
    new->ocorr = 1;
    new->palavra = strdup(p);

    if(!l) l = new;
    else if(!l->prox){
        l->prox = new;
    }else{
        for (aux = l; aux; aux = aux->prox);
        aux->prox = new;
    }
    return l;
}

//? 7
Palavras acrescenta (Palavras l, char *p){
    int found = 0;
    Palavras aux;

    for(aux = l; aux; aux = aux->prox){
        if(strcmp(aux->palavra,p) == 0){
            found = 1;
            aux->ocorr++;
        }
    }
    if(!found) l = acrescentaInicio(l,p);
    return l;
}

//? 8
struct celula* maisFreq (Palavras l){
    struct celula* max = l;
    Palavras aux;

    for(aux = l; aux; aux = aux->prox){
        if(aux->ocorr > max->ocorr) max = aux;
    }

    return max;
}