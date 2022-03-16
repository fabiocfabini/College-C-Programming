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
    LInt aux = l;
    for(; aux; aux = aux->prox){
        printf("%d -> ", aux->valor);
    }printf("NULL\n");
}

//? 4
LInt reverseL (LInt l){
    if(!l) return NULL;
    if(!l->prox) return l;

    LInt prev = l;
    LInt curr = l->prox;
    prev->prox = NULL;

    while(curr){
        LInt next = curr->prox;
        curr->prox = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

//? 5
void insertOrd (LInt *l, int x){
    LInt new = (LInt) malloc(sizeof(struct lligada));
    new->valor = x;
    if(!*l){
        new->prox = NULL;
        *l = new;
    }else if((*l)->valor >= x){
        new->prox = *l;
        *l = new;
    }else{
        LInt prev = *l;
        LInt curr = (*l)->prox;
        for(; curr && curr->valor < x; curr = curr->prox) prev = curr;
        if(curr){
            new->prox = curr;
            prev->prox = new;
        }else{
            new->prox = NULL;
            prev->prox = new;
        }
    }
}

//? 6
int removeOneOrd (LInt *l, int x){
    if(!(*l)) return 1;
    if(!(*l)->prox){
        if((*l)->valor == x){free(*l); *l = NULL; return 0;}
        else return 1;
    }

    LInt prev = *l;
    LInt curr = (*l)->prox;

    for(; curr && curr->valor < x ; curr = curr->prox) prev = curr;

    if(curr && curr->valor == x){
        prev->prox = curr->prox;
        free(curr);
        return 0;
    }return 1;
}

//? 7
void mergeL (LInt *r, LInt a, LInt b){
    *r = malloc(sizeof(struct lligada));
    LInt aDup = a;
    LInt bDup = b;

    while(aDup && bDup){
        if(aDup->valor <= bDup->valor){
            (*r)->valor = aDup->valor;
            aDup = aDup->prox;
        }else{
            (*r)->valor = bDup->valor;
            bDup = bDup->prox;
        }
        (*r)->prox = malloc(sizeof(struct lligada));
        r = &(*r)->prox;
    }
    while(aDup){
        (*r)->valor = aDup->valor;
        aDup = aDup->prox;
        (*r)->prox = malloc(sizeof(struct lligada));
        r = &(*r)->prox;
    }
    while(bDup){
        (*r)->valor = bDup->valor;
        bDup = bDup->prox;
        (*r)->prox = malloc(sizeof(struct lligada));
        r = &(*r)->prox;
    }
    *r = NULL;
}

//? 8
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    /*
    while (l)
    {
        if (l->valor < x)
        {
            *mx = l;
            mx = &(*mx)->prox;
            *Mx = NULL;
        }else
        {
            *Mx = l;
            Mx = &(*Mx)->prox;
            *mx = NULL;
        }
        l = l->prox;
    }
    */
    *mx = NULL;
    *Mx = NULL;
    LInt temp;
    while(l){
        if(l->valor < x){
            temp = l->prox;
            l->prox = *mx;
            *mx = l;
            l = temp;
        }else{
            temp = l->prox;
            l->prox = *Mx;
            *Mx = l;
            l = temp;
        }
    }
}

//? 9
LInt parteAmeio (LInt *l){
    if(!(*l) || !(*l)->prox) return NULL;
    int mid = length(*l) / 2;

    LInt out = *l;
    for(; mid > 1; mid--, *l = (*l)->prox);
    LInt temp = (*l)->prox;

    (*l)->prox = NULL;
    *l = temp;
    return out;
}

//? 10
int removeAll (LInt *l, int x){
    int count = 0;
    if(*l){
        while(*l && (*l)->valor == x){
            count++;
            LInt temp = (*l)->prox;
            free(*l); *l = temp;
        }
        if(*l){
            LInt aux = *l;
            for(; aux && aux->prox; aux = aux->prox){
                while(aux->prox && aux->prox->valor == x){
                    LInt temp = aux->prox->prox;
                    free(aux->prox);
                    aux->prox = temp;
                    count++;
                }
            }
        }
    }
    return count;
}

//? 11
int removeDups (LInt *l){
    int count = 0;
    if(*l && (*l)->prox){
        LInt aux = *l;
        for(;aux && aux->prox;aux = aux->prox){
            count += removeAll(&aux->prox, aux->valor);
        }
    }
    return count;
}

//? 12
void removeFirstOc(LInt *l, int x){
    if(*l){
        if((*l)->valor == x){
            LInt temp = (*l)->prox;
            free(*l); *l = temp;
        }else{
            LInt aux = *l;
            for(; aux->prox; aux = aux->prox){
                if(aux->prox->valor == x){
                    LInt temp = aux->prox->prox;
                    free(aux->prox); aux->prox = temp;
                    break;
                }
            }
        }
    }
}
int removeMaiorL (LInt *l){
    int res = LIntMax(*l);
    removeFirstOc(l,res);
    return res;
}

//? 13
void init (LInt *l) {
    if(*l){
        if(!(*l)->prox){
            free(*l); *l = NULL;
        }else{
            LInt prev = (*l);
            LInt curr = (*l)->prox;
            for(; curr->prox; curr = curr->prox) prev = curr;
            free(curr); prev->prox = NULL;
        }
    } 
}

//? 14
void appendL (LInt *l, int x){
    LInt new = (LInt) malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    if(!*l) *l = new;
    else{
        LInt aux = *l;
        for(; aux->prox; aux = aux->prox);
        aux->prox = new;
    }
}

//? 15
void concatL (LInt *a, LInt b){
    if(!*a) *a = b;
    else{
        LInt aux = *a;
        for(; aux->prox; aux = aux->prox);
        aux->prox = b;
    }
}

//? 16
LInt cloneL (LInt l){
    LInt clone = NULL;
    if(l){
        clone = (LInt) malloc(sizeof(struct lligada));
        clone->valor = l->valor;
        clone->prox = NULL;

        LInt auxClone = clone;
        LInt auxL = l->prox;
        for(;auxL; auxL = auxL->prox){
            auxClone->prox = (LInt) malloc(sizeof(struct lligada));
            auxClone->prox->valor = auxL->valor;
            auxClone = auxClone->prox;
            auxClone->prox = NULL;
        }
    }
    return clone;
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
int LIntMax(LInt l){
    LInt aux;
    int Max = l->valor;

    for(aux = l->prox; aux; aux = aux->prox){
        if(aux->valor > Max) Max = aux->valor;
    }
    return Max;
}

//? 19
int take (int n, LInt *l){
    if(n == 0){
        freeL(*l);
        *l = NULL;
        return 0;
    }
    int count = 0;
    LInt aux = *l;
    for(; aux && n > 1; aux = aux->prox){count++; n--;}
    if(aux){
        freeL(aux->prox);
        aux->prox = NULL;
        return count+1;
    }else{
        return count;
    }
}

//? 20
int drop (int n, LInt *l){
    int count = 0;

    for(; *l && n > 0;){
        LInt temp = (*l)->prox;
        free(*l); *l = temp;
        count++; n--;
    }

    return count;
}

//? 21
LInt Nforward (LInt l, int N){
    LInt aux = l;
    for(; N > 0; aux = aux->prox, N--);
    return aux;
}

//? 22
int listToArray (LInt l, int v[], int N){
    LInt aux = l;
    int i = 0;
    for(; aux && i < N; aux = aux->prox){
        v[i++] = aux->valor;
    }
    return i;
}

//? 23
LInt arrayToList (int v[], int N){
    LInt new = NULL;
    int i = 0;
    if(N > 0){
        new = (LInt) malloc(sizeof(struct lligada));
        LInt aux = new;
        for(; i < N-1; i++, aux = aux->prox){
            aux->valor = v[i];
            aux->prox = (LInt) malloc(sizeof(struct lligada));
        }
        aux->valor = v[i];
        aux->prox = NULL;
    }
    return new;
}

//? 24
LInt somasAcL (LInt l){
    LInt Ac = NULL;
    if(l){
        Ac = (LInt) malloc(sizeof(struct lligada));
        Ac->valor = l->valor;
        LInt auxL = l->prox;
        LInt auxAc = Ac;
        for(; auxL; auxL = auxL->prox, auxAc = auxAc->prox){
            auxAc->prox = (LInt) malloc(sizeof(struct lligada));
            auxAc->prox->valor = auxAc->valor + auxL->valor;
        }
        auxAc->prox = NULL;
    }
    return Ac;
}

//? 25
void remreps (LInt l){
    LInt aux = l;
    while(aux){
        while(aux && aux->prox && aux->valor == aux->prox->valor){
            LInt temp = aux->prox->prox;
            free(aux->prox); aux->prox = temp;
        }
        aux = aux->prox;
    }
}

//? 26
LInt rotateL (LInt l){
    if(!l || !l->prox) return l;
    LInt head = l; l = l->prox;
    LInt aux = l;
    for(; aux->prox; aux = aux->prox);
    aux->prox = head;
    head->prox = NULL;
    return l;
}

//? 27
LInt parte (LInt l){
    if(!l || !l->prox) return NULL;
    int i = 3;
    LInt newL = l; LInt y = l->prox;
    LInt auxNewL = newL; LInt auxY = y;
    l = l->prox->prox  ; LInt aux = l;

    while(aux){
        if(i % 2 == 0){
            auxY->prox = aux;
            auxY = auxY->prox;
        }else{
            auxNewL->prox = aux;
            auxNewL = auxNewL->prox;
        }
        aux = aux->prox; i++;
    }
    auxNewL->prox = NULL;
    auxY ->prox = NULL;

    l = newL;
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
    if(!a) return NULL;
    ABin new = (ABin) malloc(sizeof(struct nodo));
    new->valor = a->valor;
    new->dir = cloneAB(a->dir);
    new->esq = cloneAB(a->esq);
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
    if(a->valor == x) return 0;
    int e = depth(a->esq,x);
    int d = depth(a->dir,x);
    if(e == -1 && d == -1) return -1;
    else return 1 + max(e,d);
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
    if(!a && !b) return 1;
    if(!a || !b) return 0;

    return (a->valor == b->valor) && iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir);
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

    if(a->valor > x){
        int e = depthOrd(a->esq,x);
        return (e == -1)? -1: e+1;
    }else{
        int d = depthOrd(a->dir,x);
        return (d == -1)? -1: d+1;
    }
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
    LInt y = parteAmeio(&l);
    if(!l) *a = NULL;
    if(l){
        (*a)->valor = l->valor;

        if(!y){
            (*a)->dir = (*a)->esq = NULL;
        }else{
            LInt temp = l->prox;
            free(l); l = temp;

            (*a)->dir = malloc(sizeof(struct nodo));
            (*a)->esq = malloc(sizeof(struct nodo));
            LTBTAux(y,&(*a)->esq);
            LTBTAux(l,&(*a)->dir);
        }
    }
}
void listToBTree (LInt l, ABin *a){
    *a = NULL;
    if(l){
        *a = malloc(sizeof(struct nodo));
        LTBTAux(l,a);
    }
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