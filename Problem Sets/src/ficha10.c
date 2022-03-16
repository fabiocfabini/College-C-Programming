#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "storage.h"


//* Helpfull Functions
void rodaEsquerda(ABin *a){
    ABin b = (*a)->dir;
    (*a)->dir = b->esq;
    b->esq = *a;
    *a = b;
}
void rodaDireita(ABin *a){
    ABin b = (*a)->esq;
    (*a)->esq = b->dir;
    b->dir = *a;
    *a = b;
}
int Balenced(ABin a){
    if(!a) return 0;
    if(!a->esq && !a->dir) return 1;

    int e = Balenced(a->esq);
    int d = Balenced(a->dir);

    return (e != -1 && d != -1 && e-d <= 1 && d-e <= 1)? (1+e+d):-1;
}


//? 1
ABin removeMenor (ABin *a){
    if(!(*a)) return NULL;
    ABin *last, *curr, out;
    last = curr = a;

    while((*curr)->esq){
        last = curr;
        curr = &(*curr)->esq;
    }

    if(last == curr){
        out = *curr;
        *curr = NULL;
    }else if(!(*curr)->esq && !(*curr)->dir){
        out = *curr;
        (*last)->esq = NULL;
    }else{
        out = *curr;
        (*last)->esq = (*curr)->dir;
    }
    return out;
}

//? 2
void removeRaiz (ABin *a){
    if(*a){
        if(!(*a)->dir){
            ABin e = (*a)->esq;
            free(*a);
            *a = e;
        }else{
            ABin root = removeMenorMelhor(&(*a)->dir);
            ABin e = (*a)->esq;
            ABin d = (*a)->dir;
            free(*a);
            *a = root;
            (*a)->dir = d;
            (*a)->esq = e;
        }
    }
}

//? 3
int removeElem (ABin *a, int x){
    if(!(*a)) return 1;
    else if((*a)->valor == x){
        removeRaiz(a);
        return 0;
    }else if((*a)->valor >= x) return removeElem(&(*a)->esq,x);
    else return removeElem(&(*a)->dir,x);
}

//? 4
void promoveMenor (ABin *a){
    if(*a && (*a)->esq){
        promoveMenor(&(*a)->esq);
        rodaDireita(a);
    }
}

//? 5
void promoveMaior (ABin *a){
    if(*a && (*a)->dir){
        promoveMaior(&(*a)->dir);
        rodaEsquerda(a);
    }
}

//? 6
ABin removeMenorMelhor (ABin *a){
    if(!(*a)) return NULL;
    promoveMenor(a);
    ABin d = (*a)->dir;
    ABin out = *a;
    *a = d;
    return out;
}

//? 7
int constroiEspinha (ABin *a){
    if(!(*a)) return 0;
    else{
        promoveMenor(a);
        return 1 + constroiEspinha(&(*a)->dir);
    }
}

//? 8
ABin equilibraEspinha (ABin *a, int n){
    if(n > 2){
        int m = n/2;
        if((*a)->esq){
            for(int i = 0; i < m; i++){
                rodaDireita(a);
            }
            (*a)->esq = equilibraEspinha(&(*a)->esq,n-1-m);
            (*a)->dir = equilibraEspinha(&(*a)->dir,m);
        }else{
            for(int i = 0; i < m; i++){
                rodaEsquerda(a);
            }
            (*a)->esq = equilibraEspinha(&(*a)->esq,m);
            (*a)->dir = equilibraEspinha(&(*a)->dir,n-1-m);
        }
    }
    return *a;
}

//? 9
void equilibra (ABin *a) {
    int n = constroiEspinha(a);
    *a = equilibraEspinha(a,n);
}