#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Q1.h"
#include "Q2.h"

LInt newLInt(int val, LInt rest){
    LInt new = malloc(sizeof(struct lligada));

    if(new){
        new->valor = val;
        new->prox = rest;
    }

    return new;
}

ABin newABin(int val, ABin left, ABin right){
    ABin new = malloc(sizeof(struct nodo));

    if(new){
        new->valor = val;
        new->esq = left;
        new->dir = right;
    }

    return new;
}

int main(int argc, char **argv){
    LInt l = newLInt(1, newLInt(2, newLInt(3, newLInt(4, newLInt(5, NULL)))));

    LInt clone = cloneL(l);
    init(&l);

    imprimeL(l);
    imprimeL(clone);

    freeL(l);
    freeL(clone);

    return 0;
}