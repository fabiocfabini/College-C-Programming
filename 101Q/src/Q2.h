#ifndef __Q2__
#define __Q2__

typedef struct lligada {
    int valor;
    struct lligada *prox;
}*LInt;

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
}*ABin;

/* 1 */ int length (LInt);
/* 2 */ void freeL (LInt l);
/* 3 */ void imprimeL (LInt l);
/* 4 */ LInt reverseL (LInt l);
/* 5 */ void insertOrd (LInt *l, int x);
/* 6 */ void insertOrd (LInt *l, int x);
/* 7 */ int removeOneOrd (LInt *l, int x);
/* 8 */ void mergeL (LInt *r, LInt a, LInt b);
/* 9 */ void splitQS (LInt l, int x, LInt *mx, LInt *Mx);
/* 10*/ LInt parteAmeio (LInt *l);
/* 11*/ int removeAll (LInt *l, int x);
/* 12*/ int removeDups (LInt *);
/* 13*/ int removeMaiorL (LInt *);
        void removeFirstOc(LInt *l, int x);
        int LIntMax(LInt l);
/* 14*/ void init (LInt *l);
/* 15*/ void appendL (LInt *l, int x);
/* 16*/ void concatL (LInt *a, LInt b);
/* 17*/ LInt cloneL (LInt l);
/* 18*/ LInt cloneRev (LInt l);
/* 19*/ int take (int n, LInt *l);
/* 20*/ int drop (int n, LInt *l);
/* 21*/ LInt Nforward (LInt l, int N);
/* 22*/ int listToArray (LInt l, int v[], int N);
/* 23*/ LInt arrayToList (int v[], int N);
/* 24*/ LInt somasAcL (LInt l);
/* 25*/ void remreps (LInt l);
/* 26*/ LInt rotateL (LInt l);
/* 27*/ LInt parte (LInt l);
/* 28*/ int altura (ABin a);
        int max(int a, int b);
/* 29*/ ABin cloneAB (ABin a);
/* 30*/ void mirror (ABin * a);
/* 31*/ void inorder (ABin a, LInt *l);
        void inorderAux(ABin a, LInt *l);
/* 32*/ void preorder (ABin a, LInt *l);
        void preorderAux (ABin a, LInt *l);
/* 33*/ void posorder (ABin a, LInt *l);
        void posorderAux(ABin a, LInt *l);
/* 34*/ int depth (ABin a, int x);
/* 35*/ int freeAB (ABin a);
/* 36*/ int pruneAB (ABin *a, int l);
/* 37*/ int iguaisAB (ABin a, ABin b);
/* 38*/ LInt nivelL (ABin a, int n);
        void nivelLAux(ABin a, LInt *l, int n);
/* 39*/ int nivelV (ABin a, int n, int v[]);
/* 40*/ int dumpAbin (ABin a, int v[], int N);
/* 41*/ ABin somasAcA (ABin a);
/* 42*/ int contaFolhas (ABin a);
/* 43*/ ABin cloneMirror (ABin a);
/* 44*/ int addOrd (ABin *a, int x);
/* 45*/ int lookupAB (ABin a, int x);
/* 46*/ int depthOrd (ABin a, int x);
/* 47*/ int maiorAB (ABin a);
/* 48*/ void removeMaiorA (ABin *a);
/* 49*/ int quantosMaiores (ABin a, int x);
/* 50*/ void listToBTree (LInt l, ABin *a);
        void LTBTAux(LInt l, ABin *a);
/* 51*/ int deProcura (ABin a);
        int allMore (ABin a, int x);
        int allLess (ABin a, int x);

#endif