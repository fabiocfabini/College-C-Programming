#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "storage.h"

//* Helpfull functions
void showStack(STACK s){
    for (int i = 0; i < s.sp; i++){
        printf("%d ", s.values[i]);
    }
    printf("\t[CURRENT STACK SIZE] %d\n", s.sp);
}
void showQueue(QUEUE q){
    for(int i = 0; i < q.length; i++){
        printf("%d ", q.values[(q.front + i) % Max]);
    }
    printf("\t[CURRENT QUEUE SIZE] %d\n", q.length);
}
void showDStack(struct dinStack s){
    for(int i = 0; i < s.sp; i++){
        printf("%d ", s.values[i]);
    }
    printf("\t[CURRENT STACK SIZE] %d\n", s.size);
}
void showDQueue(struct dinQueue q){
    for(int i = 0; i < q.length; i++){
        printf("%d ", q.values[(q.front + i) % q.size]);
    }
    printf("\t[CURRENT QUEUE SIZE] %d\n", q.size);
}

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

//? 2a
void SinitQueue(SQueue q){
    q->front = 0;
    q->length = 0;
}

//? 2b
int SisEmptyQ (SQueue q){
    return q->length == 0;
}

//? 2c
int Senqueue (SQueue q, int x){
    if(q->length >= Max) return 1;
    q->values[(q->front + q->length) % Max] = x;
    q->length++;
    return 0;
}

//? 3c
int Sdequeue (SQueue q, int *x){
    if(SisEmptyQ (q)) return 1;
    *x = q->values[q->front];
    q->front = (q->front + 1) % Max;
    q->length--;
    return 0;
}

//? 4c
int Sfront(SQueue q, int *x){
    if(SisEmptyQ (q)) return 1;
    *x = q->values[q->front];
    return 0;
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
    q->values = malloc(q->size*sizeof(int));
}

//? 3b2
int DisEmptyQ (DQueue q){
    return q->length == 0;
}

//? 3b3
int Denqueue (DQueue q, int x){
    if(q->length == q->size){
        int* new_value = malloc(2*q->size*sizeof(int));
        for(int i = 0; i < q->length; i++){
            new_value[i] = q->values[(q->front + i) % q->length];
        }
        free(q->values); q->values = new_value;
        q->size *= 2; q->front = 0;
    }
    q->values[(q->front + q->length) % q->size] = x;
    q->length++;
    return 0;
}

//? 3b4
int Ddequeue (DQueue q, int *x){
    // if(q->length == q->size / 4){
    //     int* new_values = malloc(q->size/2 * sizeof(int));
    //     for(int i = 0; i < q->length; i++){
    //         new_values[i] = q->values[(q->front + i) % q->size];
    //     }
    //     free(q->values); q->values = new_values;
    //     q->size /= 2; q->front = 0;
    // }
    if(DisEmptyQ(q)) return 1;
    *x = q->values[q->front]; q->front = (q->front + 1) % q->size;
    q->length--;
    return 0;
}


int Dfront (DQueue q, int *x){
    if(DisEmptyQ(q)) return 1;
    *x = q->values[q->front];
    return 0;
}