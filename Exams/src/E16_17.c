#include <stdio.h>
#include <stdlib.h>
#include "../includes/E16_17.h"

// Helpfull Functions
void initStackC(StackC *s, CList c){
    s->sp = 0;
    s->valores = c;
}

void printStackC(StackC s){
    printf("(");
    for(int i = 0; i < s.sp; i++){
        printf("%d, ",s.valores->vs[i]);
    } printf(") -> ");

    if(s.valores) s.valores = s.valores->prox;
    while(s.valores){
        printf("(");
        for(int i = 0; i < MAXc; i++){
            printf("%d, ",s.valores->vs[i]);
        } printf(") -> ");

        s.valores = s.valores->prox;
    } printf("NULL\n");
}

CList newCList(CList rest){
    CList new = malloc(sizeof(struct chunk));

    if(new) new->prox = rest;

    return new;
}

void freeCList(CList c){
    while(c){
        CList temp = c->prox;
        free(c);
        c = temp;
    }
}


// Exam Questions
int push (StackC *s, int x){
    // if current array is full
    if(s->sp == MAXc){
        // create new chunk
        s->sp = 0;
        CList new = malloc(sizeof(struct chunk));
        new->prox = s->valores;
        s->valores = new;
    }
    // if current Stack is NULL
    if(!s->valores) s->valores = newCList(NULL); // allocate new chunk
    // push value
    s->valores->vs[s->sp++] = x;
    return 0;
}


int pop (StackC *s, int *x){
    // if current array is empty
    if(s->sp == 0) return 1;

    // pop value
    *x = s->valores->vs[--s->sp];

    // if current array is empty
    if(s->sp == 0){
        // free current chunk
        CList temp = s->valores->prox;
        free(s->valores);
        s->valores = temp;
        // if current chunk exists
        if(s->valores) s->sp = MAXc;
    }

    return 0;
}


int size(StackC s){
    // set size to current array size
    int size = s.sp;

    // if current array is not empty
    if(s.valores) s.valores = s.valores->prox;
    while(s.valores){
        size += MAXc;
        s.valores = s.valores->prox;
    }

    return size;
}


void Libreverse (StackC *s){
    // get StackC size
    int N = size(*s);
    // create new aux array
    int vals[N];

    // copy values to aux array
    for(int i = 0; i < N; i++){
        pop(s,vals+i);
    }

    // push values to StackC
    for (int i = 0; i < N; i++){
        push(s, vals[i]);
    }
}


void reverse (StackC *s){
    // get StackC size
    int N = size(*s), i;
    // create new aux array
    int vals[N];

    CList aux = s->valores;

    // copy values to aux array
    for(int j  = s->sp-1; j > -1; j--){
        vals[i++] = aux->vs[j];
    }
    if(aux) aux = aux->prox;
    while(aux){
        for(int j = MAXc-1; j > -1; j--){
            vals[i++] = aux->vs[j];
        }
        aux = aux->prox;
    }

    aux = s->valores;
    // push values to StackC
    for(int j = s->sp-1; j > -1; j--){
        aux->vs[j] = vals[--i];
    }
    if(aux) aux = aux->prox;
    while(aux){
        for(int j = MAXc-1; j > -1; j--){
            aux->vs[j] = vals[--i];
        }
        aux = aux->prox;
    }
}

