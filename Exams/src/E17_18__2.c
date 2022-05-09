#include <stdio.h>
#include <stdlib.h>
#include "../includes/E17_18__2.h"

int minheapOK (MinHeap a){
    int r = 1;
    if(a){
        if(a->esq && a->dir){
            r = a->valor < a->esq->valor && a->valor < a->dir->valor && minheapOK(a->esq) && minheapOK(a->dir);
        }else if(a->esq){
            r = a->valor < a->esq->valor && minheapOK(a->esq);
        }else if(a->dir){
            r = a->valor < a->dir->valor && minheapOK(a->dir);
        }
    }
    return r;
}

int maxHeap (MinHeap a){
    if(!a->esq && !a->dir) return a->valor;
    else if(!a->esq) return maxHeap(a->dir);
    else if(!a->dir) return maxHeap(a->esq);
    else{
        int max_e = maxHeap(a->esq);
        int max_d = maxHeap(a->dir);
        return max_d > max_e ? max_d : max_e;
    } 
}

MinHeap removeMax(MinHeap *a, int target){
    if(!*a) return NULL;
    if((*a)->valor == target){
        MinHeap r = *a;
        free(*a); *a = NULL;
        return r;
    }
    MinHeap r_e = removeMax(&(*a)->esq, target);
    MinHeap r_d = removeMax(&(*a)->dir, target);
    return r_e ? r_e : r_d;
}

void bubbleDown(MinHeap *a){
    if(*a){
        if((*a)->esq && (*a)->dir){
            if((*a)->esq->valor > (*a)->dir->valor){
                MinHeap temp_e = (*a)->esq;
                MinHeap root = (*a)->dir;
                (*a)->esq = (*a)->dir->esq;
                (*a)->dir = (*a)->dir->dir;
                root->esq = temp_e; root->dir = *a;
                *a = root;
                bubbleDown(&(*a)->dir);
            }else{
                MinHeap temp_d = (*a)->dir;
                MinHeap root = (*a)->esq;
                (*a)->dir = (*a)->esq->dir;
                (*a)->esq = (*a)->esq->esq;
                root->dir = temp_d; root->esq = *a;
                *a = root;
                bubbleDown(&(*a)->esq);
            }
        }else if((*a)->esq){
            MinHeap temp_d = (*a)->dir;
            MinHeap root = (*a)->esq;
            (*a)->dir = (*a)->esq->dir;
            (*a)->esq = (*a)->esq->esq;
            root->dir = temp_d; root->esq = *a;
            *a = root;
            bubbleDown(&(*a)->esq);
        }else if((*a)->dir){
            MinHeap temp_d = (*a)->dir;
            MinHeap root = (*a)->esq;
            (*a)->dir = (*a)->esq->dir;
            (*a)->esq = (*a)->esq->esq;
            root->dir = temp_d; root->esq = *a;
            *a = root;
            bubbleDown(&(*a)->dir);
        }
    }
}

void removeMin (MinHeap *a){
    MinHeap max = removeMax(a, maxHeap(*a));

    max->esq = (*a)->esq; max->dir = (*a)->dir;
    free(*a); *a = max;

    bubbleDown(a);
}

void add (MinHeap*a, int x){
    
}

void heapSort (int v[], int N){
    MinHeap a = NULL;
    for(int i = 0; i < N; i++){
        add(&a, v[i]);
    }

    for(int i = 0; i < N; i++){
        v[i] = a->valor;
        removeMin(&a);
    }
}

int kMaior (int v[], int N, int k){
    MinHeap a = NULL;
    for(int i = 0; i < k; i++){
        add(&a, v[i]);
    }

    for(int i = k ; i < N; i++){
        if(v[i] > a->valor){
            removeMin(&a);
            add(&a, v[i]);
        }
    }

    return a->valor;
}
