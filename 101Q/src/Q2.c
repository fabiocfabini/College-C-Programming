#include <stdio.h>
#include <stdlib.h>
#include "Q2.h"

//? 1
int length (LInt l){
    LInt aux = l;
    int count = 0;
    for(; aux; aux = aux->prox) count++;
    return count;
}

//? 2
void freeL (LInt l){
    LInt temp;
    while(l){
        temp = l->prox;
        free(l);
        l = temp;
    }
}

//? 3
void imprimeL (LInt l){
    for(; l; l = l->prox){
        printf("%d -> ", l->valor);
    }printf("NULL\n");
}

//? 4
LInt reverseL (LInt l){
    LInt ant = NULL;
    while(l){
        LInt temp = l->prox;
        l->prox = ant;
        ant = l;
        l = temp;
    }
    l = ant;
    return l;
}

//? 5
void insertOrd (LInt *l, int x){
    while(*l && (*l)->valor < x){
        l = &((*l)->prox);
    }
    LInt new = newLInt(x, *l);
    *l = new;
}

//? 6
int removeOneOrd (LInt *l, int x){
    while(*l && (*l)->valor != x){
        l = &((*l)->prox);
    }
    if(!(*l)) return 1;
    LInt temp = (*l)->prox;
    free(*l);
    *l = temp;
    return 0;
}

//? 7
void mergeL (LInt *r, LInt l1, LInt l2){
    while(l1 && l2){
        if(l1->valor <= l2->valor){
            *r = l1;
            l1 = l1->prox;
        }else{
            *r = l2;
            l2 = l2->prox;
        }
        r = &((*r)->prox);
    }
    
    if(l1) *r = l1;
    else *r = l2;
}

//? 8
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    *mx = NULL; *Mx = NULL;
    
    while(l){
        if(l->valor < x){
            *mx = l;
            mx = &((*mx)->prox);
        }else{
            *Mx = l;
            Mx = &((*Mx)->prox);
        }
        l = l->prox;
    }
    
    *mx = NULL; *Mx = NULL;
}

//? 9
LInt parteAmeio (LInt *l){
    int mid = length(*l)/2;
    LInt y = *l; LInt* curr = &y;
    
    while(mid > 0){
        curr = &((*curr)->prox);
        mid--;
    }
    
    *l = *curr;
    *curr = NULL;
    return y;
}

//? 10
int removeAll (LInt *l, int x){
    int c = 0;
    while(*l){
        if((*l)->valor == x){
            LInt temp = (*l)->prox;
            free(*l);
            *l = temp;
            c++;
        }else{
            l = &((*l)->prox);
        }
    }
    return c;
}

//? 11
int removeDups (LInt *l){
    int c = 0;
    
    for(; *l; l = &((*l)->prox)){
        c += removeAll(&(*l)->prox, (*l)->valor);
    }
    
    return c;
}

//? 12
int removeMaiorL (LInt *l){
    int max = LIntmax(l);
    
    while((*l)->valor != max) l = &(*l)->prox;
    
    LInt temp = (*l)->prox;
    free(*l);
    *l = temp;
    
    return max;
}

//? 13
void init (LInt *l) {
    while((*l)->prox) l = &(*l)->prox;
    free(*l);
    *l = NULL;
}

//? 14
void appendL (LInt *l, int x){
    while(*l) l = &(*l)->prox;
    LInt new = newLInt(x, *l);
    *l = new;
}

//? 15
void concatL (LInt *a, LInt b){
    while(*a) a = &(*a)->prox;
    *a = b;
}

//? 16
LInt cloneL (LInt l){
    LInt new = NULL;
    LInt* newAd = &new;
    while (l){
        *newAd = malloc(sizeof(struct lligada));
        (*newAd)->valor = l->valor;
        (*newAd)->prox = NULL;
        newAd = &(*newAd)->prox;
        l = l->prox;
    }
    return new;
}

//? 17
LInt cloneRev (LInt l){
    LInt clone = NULL;
    if(l){
        LInt aux = l;
        for(; aux; aux = aux->prox){
            LInt new = malloc(sizeof(struct lligada));
            new->valor = aux->valor;
            new->prox = clone;
            clone = new;
        }
    }
    return clone;
}

//? 18
int LIntmax(LInt* l){
    int max = (*l)->valor;
    l = &(*l)->prox;
    
    while(*l){
        if(max < (*l)->valor) max = (*l)->valor;
        l = &(*l)->prox;
    }
    
    return max;
}

//? 19
int take (int n, LInt *l){
    int c = 0;
    while(*l && n > 0) {
        l = &(*l)->prox;
        n--; c++;
    }
    freeL(*l);
    *l = NULL;
    return c;
}

//? 20
int drop (int n, LInt *l){
    int c = 0;
    while(*l && n > 0){
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
        c++; n--;
    }
    return c;
}

//? 21
LInt Nforward (LInt l, int N){
    while(N > 0){
        l = l->prox;
        N--;
    }
    return l;
}

//? 22
int listToArray (LInt l, int v[], int N){
    int i = 0;
    
    for(; i < N && l; i++, l = l->prox){
        v[i] = l->valor;
    }
    
    return i;
}

//? 23
LInt arrayToList (int v[], int N){
    int i = 0;
    LInt new = NULL;
    LInt* newAd = &new;
    
    for(; i < N; i++, newAd = &(*newAd)->prox){
        *newAd = malloc(sizeof(struct lligada));
        (*newAd)->valor = v[i];
        (*newAd)->prox = NULL;
    }
    
    return new;
}

//? 24
LInt somasAcL (LInt l){
    LInt new = NULL;
    LInt* newAd = &new;
    
    if(l){
        int ac = l->valor;
        l = l->prox;
        *newAd = newLInt(ac, NULL);
        newAd = &(*newAd)->prox;
        
        while(l){
            ac += l->valor;
            *newAd = newLInt(ac, NULL);
            newAd = &(*newAd)->prox;
            l = l->prox;
        }
    }
    return new;
}

//? 25
void remreps (LInt l){
    if(l){
        int current = l->valor;
        LInt* lAd = &l->prox;
        while(*lAd){
            if((*lAd)->valor == current){
                LInt temp = (*lAd)->prox;
                free(*lAd);
                *lAd = temp;
            }else{
                current = (*lAd)->valor;
                lAd = &(*lAd)->prox;
            }
        }
    }
}

//? 26
LInt rotateL (LInt l){
    if(l && l->prox){
        LInt* ad = &l;
        
        while(*ad) ad = &(*ad)->prox;
        
        LInt snd = l->prox;
        l->prox = NULL;
        *ad = l;
        l = snd;
    }
    return l;
}

//? 27
LInt parte (LInt l){
    LInt y = NULL; LInt* yad = &y;
    LInt L = l;    LInt* Lad = &l;
    
    if(l){
        int i = 1;
        Lad = &(*Lad)->prox;
        l = l->prox;
        
        while(l){
            if(i % 2 == 0){
                *Lad = l;
                Lad = &(*Lad)->prox;
            }else{
                *yad = l;
                yad = &(*yad)->prox;
            }
            l = l->prox;
            i++;
        }
        *Lad = *yad = NULL;
    }
    return y;
}

//? 28
int max(int a, int b){
    return (a>b)? a:b;
}
int altura (ABin a){
    if(!a) return 0;
    return 1 + max(altura(a->dir), altura(a->esq));
}

//? 29
ABin cloneAB (ABin a){
    ABin new = NULL;
    if(a){
        new = malloc(sizeof(struct nodo));
        new->valor = a->valor;
        new->esq = cloneAB(a->esq);
        new->dir = cloneAB(a->dir);
    }
    return new;
}

//? 30
void mirror (ABin * a){
    if(*a){
        ABin temp = (*a)->dir;
        (*a)->dir = (*a)->esq;
        (*a)->esq = temp;
        mirror(&(*a)->dir);
        mirror(&(*a)->esq);
    }
}

//? 31
void inorderAux(ABin a, LInt *l){
    if(a){
        inorderAux(a->dir,l);
        LInt new = (LInt) malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = *l;
        *l = new;
        inorderAux(a->esq,l);
    }
}
void inorder (ABin a, LInt *l){
    *l = NULL;
    inorderAux(a,l);
}

//? 32
void preorderAux (ABin a, LInt *l){
    if(a){
        preorderAux(a->dir,l);
        preorderAux(a->esq,l);
        LInt new = (LInt) malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = *l;
        *l = new;
    }
}
void preorder (ABin a, LInt *l){
    *l = NULL;
    preorderAux(a,l);
}

//? 33
void posorderAux(ABin a, LInt *l){
    if(a){
        LInt new = (LInt) malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = *l;
        *l = new;
        posorderAux(a->dir,l);
        posorderAux(a->esq,l);
    }
}
void posorder (ABin a, LInt *l){
    *l = NULL;
    posorderAux(a,l);
}

//? 34
int depth (ABin a, int x){
    if(!a) return -1;
    if(a->valor == x) return 1;
    
    int e = depth(a->esq,x);
    int d = depth(a->dir,x);
    
    if(e == -1 && d == -1) return -1;
    if(e == -1) return 1 + d; 
    if(d == -1) return 1 + e; 
    else return 1 + min(e,d);
}

//? 35
int freeAB (ABin a){
    if(a){
        ABin e = a->esq;
        ABin d = a->dir;
        free(a);
        return 1 + freeAB(e) + freeAB(d);
    }
    return 0;
}

//? 36
int pruneAB (ABin *a, int l){
    if(!*a) return 0;
    if(l == 0){
        int c = freeAB(*a); *a = NULL; return c;
    }
    if(l == 1){
        ABin e = (*a)->esq;
        ABin d = (*a)->dir;
        (*a)->dir = (*a)->esq = NULL;
        return freeAB(e) + freeAB(d);
    }
    int e = pruneAB(&(*a)->esq, l-1);
    int d = pruneAB(&(*a)->dir, l-1);
    return e + d;
}

//? 37 
int iguaisAB (ABin a, ABin b){
return  (!a && !b)               || 
        ((a && b)                &&
        (a->valor == b->valor)   &&
        iguaisAB(a->esq, b->esq) && 
        iguaisAB(a->dir,b->dir));
}

//? 38
void nivelLAux(ABin a, LInt *l, int n){
    if(a && n > 0){
        if(n == 1){
            LInt new = malloc(sizeof(struct lligada));
            new->valor = a->valor;
            new->prox = *l;
            *l = new;
        }
        nivelLAux(a->dir, l, n-1);
        nivelLAux(a->esq, l, n-1);
    }
}
LInt nivelL (ABin a, int n){
    LInt l = NULL;
    if(n > 0) nivelLAux(a,&l,n);
    return l;
}

//? 39
int nivelV (ABin a, int n, int v[]){
    if(!a || n < 1) return 0;
    if(n == 1){
        *v = a->valor;
        return 1;
    }

    int e = nivelV(a->esq, n-1, v);
    int d = nivelV(a->dir, n-1, v+e);

    return e+d;
}

//? 40
int dumpAbin (ABin a, int v[], int N){
    if(!a || N < 1) return 0;

    int e = dumpAbin(a->esq, v, N);
    if(e < N){
        v[e] = a->valor;
        return 1 + e + dumpAbin(a->dir, v+e+1, N-e-1);
    }
    return N;
}

//? 41
ABin somasAcA (ABin a){
    if(!a) return NULL;
    if(!a->dir && !a->esq){
        ABin new = malloc(sizeof(struct nodo));
        new->dir = new->esq = NULL;
        new->valor = a->valor;
        return new;
    }

    ABin new = malloc(sizeof(struct nodo));
    new->esq = somasAcA(a->esq);
    new->dir = somasAcA(a->dir);

    if(new->esq && new->dir) new->valor = a->valor + new->esq->valor + new->dir->valor;
    else if(new->dir) new->valor = a->valor + new->dir->valor;
    else if(new->esq) new->valor = a->valor + new->esq->valor;

    return new;
}

//? 42
int contaFolhas (ABin a){
    if(!a) return 0;
    if(!a->dir && !a->esq) return 1;
    return contaFolhas(a->dir) + contaFolhas(a->esq);
}

//? 43
ABin cloneMirror (ABin a){
    if(!a) return NULL;
    
    ABin new = malloc(sizeof(struct nodo));
    new->valor = a->valor;
    
    new->esq = cloneMirror(a->dir);
    new->dir = cloneMirror(a->esq);

    return new;
}

//? 44
int addOrd (ABin *a, int x){
    if(!*a){
        *a = malloc(sizeof(struct nodo));
        (*a)->valor = x;
        (*a)->esq = (*a)->dir = NULL;
        return 0;
    }
    if((*a)->valor == x) return 1;
    if((*a)->valor > x){
        if((*a)->esq) return addOrd(&(*a)->esq, x);
        else{
            ABin new = malloc(sizeof(struct nodo));
            new->valor = x;
            new->dir = new->esq = NULL;
            (*a)->esq = new;
            return 0;
        }
    }else{
        if((*a)->dir) return addOrd(&(*a)->dir, x);
        else{
            ABin new = malloc(sizeof(struct nodo));
            new->valor = x;
            new->esq = new->dir = NULL;
            (*a)->dir = new;
            return 0;
        }
    }
}

//? 45
int lookupAB (ABin a, int x){
    return (a != NULL) && ((a->valor == x) || lookupAB(a->esq,x) || lookupAB(a->dir,x));
}

//? 46
int depthOrd (ABin a, int x){
    if(!a) return -1;
    if(a->valor == x) return 1;
    
    int res;
    if( x < a->valor) res = depthOrd(a->esq, x);
    else res = depthOrd(a->dir, x);
    
    return (res == -1)? -1: 1 + res;
}

//? 47
int maiorAB (ABin a){
    if(!a->dir) return a->valor;
    return maiorAB(a->dir);
}

//? 48
void removeMaiorA (ABin *a){
    if(*a){
        if(!(*a)->dir){
            free(*a);
            *a = (*a)->esq;
        }else if(!(*a)->dir->dir){
            ABin temp = (*a)->dir->esq;
            free((*a)->dir);
            (*a)->dir = temp;
        }else{
            removeMaiorA(&(*a)->dir);
        }
    }
}

//? 49
int quantosMaiores (ABin a, int x){
    if(!a) return 0;
    return (a->valor > x) + quantosMaiores(a->esq,x) + quantosMaiores(a->dir,x); 
}

//? 50
void LTBTAux(LInt l, ABin *a){
    if(l){
        LInt e = parteAmeio(&l);
        
        *a = malloc(sizeof(struct nodo));
        (*a)->valor = l->valor;
        (*a)->esq = (*a)->dir = NULL;
        
        LInt temp = l->prox; free(l); l = temp;
        
        LTBTAux(e, &(*a)->esq);
        LTBTAux(l, &(*a)->dir);
    }
}
void listToBTree (LInt l, ABin *a){
    *a = NULL;
    LTBTAux(l, a);
}

//? 51
int allLess (ABin a, int x){
    if(!a) return 1;
    return (x < a->valor) && allLess(a->dir,x) && allLess(a->esq,x);
}
int allMore (ABin a, int x){
    if(!a) return 1;
    return (x > a->valor) && allMore(a->dir,x) && allMore(a->esq,x);
}
int deProcura (ABin a){
    if(!a) return 1;
    return allMore(a->esq,a->valor) && allLess(a->dir,a->valor) && deProcura(a->dir) && deProcura(a->esq);
}