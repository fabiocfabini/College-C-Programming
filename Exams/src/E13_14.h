#ifndef __E1314__
#define __E1314__

typedef struct spares {
    int x, y;
    struct spares *prox;
} Par, *LPares;

typedef struct slist {
    int valor;
    struct slist *prox;
}*LInt;

typedef struct no {
    int value;
    struct no *esq,*dir,*pai;
}*Tree;

// Helpfull functions
void freePar(LPares z);
void freeLInt(LInt z);
void freeTree(Tree t);
void printLPares(LPares z);
void printLInt(LInt z);
LInt newLInt(int x, LInt rest);
LPares newPar(int x, int y, LPares rest);
Tree newTree(int val, Tree e, Tree d, Tree parent);

// Exam Questions
LPares zip (LInt a, LInt b, int *c);
void calculaPais(Tree t);
Tree next(Tree t);

#endif