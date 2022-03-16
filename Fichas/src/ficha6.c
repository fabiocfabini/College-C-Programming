#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "storage.h"



//! Stacks

//? 1a
void SinitStack(SStack s){
    s->sp = 0;
}

//? 1b
int SisEmpty (SStack s){
    return s->sp == 0;
}

//? 1c
int Spush (SStack s, int x){
    if(s->sp < Max){
        s->values[s->sp++] = x;
        return 0;
    }return 1;
}

//? 1d
int Spop (SStack s, int *x){
    if(!SisEmpty(s)){
        *x = s->values[--s->sp];
        return 0;
    }return 1;
}

//? 1e
int Stop (SStack s, int *x){
    if(!SisEmpty(s)){
        *x = s->values[s->sp-1];
        return 0;
    }return 1;
}


//! Queues

//? 1a
void SinitQueue (SQueue q){
    q->length = 0;
    q->front = 0;
}

//? 1b
int SisEmptyQ (SQueue q){
    return q->length == q->front;
}

//? 1c
int Senqueue (SQueue q, int x){
    if(q->length < Max){
        q->values[q->length++] = x;
        return 0;
    }return 1;
}

//? 1d
int Sdequeue (SQueue q, int *x){
    if(!SisEmptyQ(q)){
        *x = q->values[q->front++];
        return 0;
    }return 1;
}

//? 1e
int Sfront (SQueue q, int *x){
    if(!SisEmptyQ(q)){
        *x = q->values[q->front];
        return 0;
    }return 1;
}


//! DStack

//? 3a1
void DinitStack(DStack s){
    s->size = Max;
    s->sp = 0;
    s->values = (int*) malloc(sizeof(int)*Max);
}

//? 3a2
int DisEmpty (DStack s){
    return s->sp == 0;
}

//? 3a3
int Dpush (DStack s, int x){
    if(s->sp == s->size){
        printf("\t\t\t[Resizing Stack ...]\n");
        int* new_values = (int*) malloc(sizeof(int)*s->size*2);
        for (int i = 0; i < s->size; i++){
            new_values[i] = s->values[i];
        }
        free(s->values);
        s->values = new_values;
        s->values[s->sp++] = x;
        s->size *= 2;
    }else{
        s->values[s->sp++] = x;
    }
    return 0;
}

//? 3a4
int Dpop (DStack s, int *x){
    if(!DisEmpty(s)){
        *x = s->values[--s->sp];
        return 0;
    }return 1;
}

//? 3a5
int Dtop (DStack s, int *x){
    if(!DisEmpty(s)){
        *x = s->values[s->sp-1];
        return 0;
    }return 1;
}


//! DQueues

//? 3b1
void DinitQueue (DQueue q){
    q->size = Max;
    q->front = 0;
    q->length = 0;
    q->values = (int*) malloc(sizeof(int)*Max);
}

//? 3b2
int DisEmptyQ (DQueue q){
    return q->front == q->length;
}

//? 3b3
int Denqueue (DQueue q, int x){
    if(q->length == q->size){
        printf("\t\t\t[Resizing Queue ...]\n");
        int* new_values = (int *) malloc(sizeof(int)*q->size*2);
        for (int i = 0; i < q->size; i++){
            new_values[i] = q->values[i];
        }
        free(q->values);
        q->values = new_values;
        q->values[q->length++] = x;
        q->size *= 2;
    }else{
        q->values[q->length++] = x;
    }
    return 0;
}

//? 3b4
int Ddequeue (DQueue q, int *x){
    if(!DisEmptyQ(q)){
        *x = q->values[q->front++];
        return 0;
    }return 1;
}

//? 3b5
int Dfront (DQueue q, int *x){
    if(!DisEmptyQ(q)){
        *x = q->values[q->front];
        return 0;
    }return 1;
}