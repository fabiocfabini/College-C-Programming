#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "storage.h"


//* Helpfull Functions
ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc (sizeof(struct nodo));
    if (a!=NULL) {
        a->valor = r; a->esq = e; a->dir = d;
    }
    return a;
}
ABin RandArvFromArray (int v[], int N) {
    ABin a = NULL;
    int m;
    if (N > 0){
        m = rand() % N;
        a = newABin (v[m], RandArvFromArray (v,m), RandArvFromArray (v+m+1,N-m-1));
    }
    return a;	
}
void print2DUtil(ABin a, int space)
{
    // Base case
    if (a == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(a->dir, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", a->valor);

    // Process left child
    print2DUtil(a->esq, space);
}
void print2D(ABin a){
   // Pass initial space count as 0
    print2DUtil(a, 0);
}
void freeABin(ABin a){
    if(a){
        freeABin(a->dir);
        freeABin(a->esq);
        free(a);
    }
}

//? 1
int altura (ABin a){
    if(!a) return 0;
    else if(!a->dir && !a->esq) return 1;
    else return 1 + max(altura(a->dir), altura(a->esq));
}

//? 2
int nFolhas (ABin a){
    if(!a) return 0;
    else if(!a->dir && !a->esq) return 1;
    else return nFolhas(a->dir) + nFolhas(a->esq);
}

//? 3
ABin maisEsquerda (ABin a){
    if(!a) return NULL;
    else if(!a->esq) return a;
    else return maisEsquerda(a->esq);
}

//? 4
void imprimeNivel (ABin a, int l){
    if(a && l >= 0){
        if(l == 0) printf("%d ", a->valor);
        else{
            imprimeNivel(a->esq,l-1);
            imprimeNivel(a->dir,l-1);
        }
    }
}

//? 5
int procuraE (ABin a, int x){
    if(!a) return 0;
    else return a->valor == x || procuraE(a->dir,x) || procuraE(a->esq,x);
}

//? 6
struct nodo* procura (ABin a, int x){
    if(!a) return NULL;
    else if(a->valor == x) return a;
    else if(a->valor >= x) return procura(a->esq,x);
    else return procura(a->dir,x);
}

//? 7
int nivel (ABin a, int x){
    if(!a) return -1;
    else if(a->valor == x) return 0;
    else if(a->valor >= x){
        int e = nivel(a->esq,x);
        return (e == -1)? -1 : (e + 1);
    }
    else{
        int d = nivel(a->dir,x);
        return (d == -1)? -1 : (d + 1);
    }
}

//? 8
void imprimeAte (ABin a, int x){
    if(a){
        imprimeAte(a->esq,x);
        if(a->valor < x){
            printf("%d ", a->valor);
            imprimeAte(a->dir,x);
        }
    }
}