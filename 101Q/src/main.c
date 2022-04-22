#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Q1.h"
#include "Q2.h"

int min(int a, int b){
    return (a < b) ? a : b;
}

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
    LInt l = newLInt(1, newLInt(2, newLInt(3, newLInt(4, newLInt(5, newLInt(6, newLInt(7, NULL)))))));

    ABin a; ABin* A = &a;

    listToBTree(l, A);

    freeAB(a);

    return 0;
}