#include <stdio.h>
#include <stdlib.h>
#include "E13_14.h"

// Helper functions
LPares newPar(int x, int y, LPares rest)
{
    LPares new = malloc(sizeof(Par));

    if (new)
    {
        new->x = x;
        new->y = y;
        new->prox = rest;
    }

    return new;
}

LInt newLInt(int x, LInt rest)
{
    LInt new = malloc(sizeof(struct slist));

    if (new)
    {
        new->valor = x;
        new->prox = rest;
    }

    return new;
}

Tree newTree(int val, Tree e, Tree d, Tree parent)
{
    Tree new = malloc(sizeof(struct no));

    if (new)
    {
        new->value = val;
        new->esq = e;
        new->dir = d;
        new->pai = parent;
    }

    return new;
}

void freePar(LPares z)
{
    while (z)
    {
        LPares temp = z->prox;
        free(z);
        z = temp;
    }
}

void freeLInt(LInt z)
{
    while (z)
    {
        LInt temp = z->prox;
        free(z);
        z = temp;
    }
}

void freeTree(Tree t)
{
    if (t)
    {
        Tree e = t->esq;
        Tree d = t->dir;
        free(t);
        freeTree(e);
        freeTree(d);
    }
}

void printLPares(LPares z)
{
    while (z)
    {
        printf("(%d, %d) ->", z->x, z->y);
        z = z->prox;
    }
    printf("NULL\n");
}

void printLInt(LInt z)
{
    while (z)
    {
        printf("%d ->", z->valor);
        z = z->prox;
    }
    printf("NULL\n");
}

// Exam Questions
LPares zip(LInt a, LInt b, int *c)
{
    *c = 0;
    LPares z = NULL;
    LPares *ad = &z;

    while (a && b)
    {
        *ad = newPar(a->valor, b->valor, *ad);
        ad = &(*ad)->prox;
        a = a->prox;
        b = b->prox;
        (*c)++;
    }

    return z;
}

void cPaux(Tree t, Tree parent)
{
    if (t)
    {
        t->pai = parent;
        cPaux(t->esq, t);
        cPaux(t->dir, t);
    }
}

void calculaPais(Tree t)
{
    cPaux(t, NULL);
}

Tree next(Tree t)
{
    // ???
    return NULL;
}
