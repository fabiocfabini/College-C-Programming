#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "storage.h"


//* Helpfull functions
void printLStack(LStack s){
    LStack aux;

    printf("Stack:");
    for (aux = s; aux; aux = aux->prox){
        printf(" %d", aux->valor);
    }printf("\n");
}
void printLQueue(LQueue q){
    LInt aux;

    printf("Queue:");
    for (aux = q.inicio; aux; aux = aux->prox){
        printf(" %d", aux->valor);
    }printf("\n");
}
void printLQC(LQueueC q){
    LInt aux;
    printf("QueueC:");
    if(!LQCisEmpty(q)){
        for (aux = q.fim->prox; aux != q.fim; aux = aux->prox){
            printf(" %d", aux->valor);
        }printf(" %d",aux->valor);
    }printf("\n");
}
void printDeque(Deque d){
    DList aux;

    printf("Deque: ");
    for (aux = d.back; aux; aux = aux->prox){
        printf(" %d", aux->valor);
    }printf("\n");
}
void printDequeC(DequeC d){
    DList aux;

    printf("DequeC:");
    if(!isEmptyDequeC(d)){
        for (aux = d.front->prox; aux != d.front; aux = aux->prox){
            printf(" %d", aux->valor);
        }printf(" %d",aux->valor);
    }printf("\n");
}

//! LStack

//? 1
void LinitStack (LStack *s){
    *s = NULL;
}

//? 2
int LisEmpty (LStack s){
    return s == NULL;
}

//? 3
int Lpush (LStack *s, int x){
    LStack new = (LStack) malloc(sizeof(struct slist));
    new->valor = x;
    new->prox = *s;
    *s = new;
    return 0;
}

//? 4
int Lpop (LStack *s, int *x){
    if(!LisEmpty(*s)){
        LStack temp = (*s)->prox;
        *x = (*s)->valor;
        free(*s);
        *s = temp;
        return 0;
    }return 1;
}

//? 5
int Ltop (LStack s, int *x){
    if(!LisEmpty(s)){
        *x = s->valor;
        return 0;
    }return 1;
}

//! LQueue

//? 1
void LinitQueue (LQueue *q){
    q->inicio = NULL;
    q->fim = NULL;
}

//? 2
int LQisEmpty (LQueue q){
    return q.inicio == NULL;
}

//? 3
int Lenqueue (LQueue *q, int x){
    int wasEmpty;
    LInt new = (LInt) malloc(sizeof(struct slist));
    new->valor = x;
    new->prox = NULL;
    if(!LQisEmpty(*q)){
        q->fim->prox = new;
        q->fim = new;
        wasEmpty = 0;
    }else{
        q->inicio = q->fim = new;
        wasEmpty = 1;
    }
    return wasEmpty;
}

//? 4
int Ldequeue (LQueue *q, int *x){
    if(!LQisEmpty(*q)){
        *x = q->inicio->valor;
        LInt temp = q->inicio->prox;
        free(q->inicio);
        q->inicio = temp;
        return 0;
    }return 1;
}

//? 5 
int Lfront (LQueue q, int *x){
    if(!LQisEmpty(q)){
        *x = q.inicio->valor;
        return 0;
    }return 1;
}


//! LQueueC

//? 1
void LinitQueueC (LQueueC *q){
    q->fim = NULL;
}

//? 2
int LQCisEmpty (LQueueC q){
    return q.fim == NULL;
}

//? 3
int LenqueueC (LQueueC *q, int x){
    int wasEmpty;
    LInt new = (LInt) malloc(sizeof(struct slist));
    new->valor = x;
    if(!LQCisEmpty(*q)){
        new->prox =  q->fim->prox;
        q->fim->prox = new;
        q->fim = q->fim->prox;
        wasEmpty = 0;
    }else{
        q->fim = new;
        q->fim->prox = q->fim;
        wasEmpty = 1;
    }
    return wasEmpty;
}

//? 4
int LdequeueC (LQueueC *q, int *x){
    if(!LQCisEmpty(*q)){
        *x = q->fim->prox->valor;
        if(q->fim->prox == q->fim){
            free(q->fim); q->fim = NULL;
        }else{
            LInt temp = q->fim->prox->prox;
            free(q->fim->prox);
            q->fim->prox = temp;
            return 0;
        }
    }return 1;
}

//? 5
int LfrontC (LQueueC q, int *x){
    if(!LQCisEmpty(q)){
        *x = q.fim->prox->valor;
        return 0;
    }return 1;
}


//! Deque

//? 1
void initDeque (Deque *q){
    q->back = q->front = NULL;
}      

//? 2
int isEmptyDeque (Deque q){
    return q.back == NULL && q.front == NULL;
}      

//? 3
int pushBackDeque (Deque *q, int x){
    int wasEmpty;
    DList new = (DList) malloc(sizeof(struct dlist));
    new->valor = x;
    new->ant = NULL;
    if(!isEmptyDeque(*q)){
        new->prox = q->back;
        q->back->ant = new;
        q->back = new;
        wasEmpty = 0;
    }else{
        new->prox = NULL;
        q->back = q->front = new;
        wasEmpty = 1;
    }
    return wasEmpty;
} 

//? 4
int pushFrontDeque (Deque *q, int x){
    int wasEmpty;
    DList new = (DList) malloc(sizeof(struct dlist));
    new->valor = x;
    new->prox = NULL;
    if(!isEmptyDeque(*q)){
        new->ant = q->front;
        q->front->prox = new; 
        q->front = new;
        wasEmpty = 0;
    }else{
        new->ant = NULL;
        q->back = q->front = new;
        wasEmpty = 1;
    }
    return wasEmpty;
} 

//? 5
int popBackDeque (Deque *q, int *x){
    if(!isEmptyDeque(*q)){
        *x = q->back->valor;
        if(q->back->prox == NULL){
            free(q->back);
            // free(q->front);
            q->back = q->front = NULL;
        }else{
            DList temp = q->back->prox;
            free(q->back);
            q->back = temp;
            q->back->ant = NULL;
        }
        return 0;
    }return 1;
}

//? 6
int popFrontDeque (Deque *q, int *x){
    if(!isEmptyDeque(*q)){
        *x = q->front->valor;
        if(q->front->ant == NULL){
            free(q->back);
            // free(q->front);
            q->back = q->front = NULL;
        }else{
            DList temp = q->front->ant;
            free(q->front);
            q->front = temp;
            q->front->prox = NULL;
        }
        return 0;
    }return 1;
}

//? 7
int popMaxDeque (Deque *q, int *x){
    if(!isEmptyDeque(*q)){
        if(q->back->prox == NULL){
            *x = q->back->valor;
            free(q->back);
            // free(q->front);
            q->back = q->front = NULL;
        }else{
            DList inicio = q->back;
            DList fim = q->front;

            while(inicio != fim){
                if(inicio->valor > fim->valor) fim = fim->ant;
                else inicio = inicio->prox;
            }
            if(inicio->ant == NULL) popBackDeque(q,x);
            else if(inicio->prox == NULL) popFrontDeque(q,x);
            else{
                *x = inicio->valor;
                inicio = inicio->ant; fim = fim->prox;
                free(inicio->prox);
                // free(fim->ant);
                inicio->prox = fim; fim->ant = inicio;
            }
        }
        return 0;
    }return 1;
}

//? 8
int backDeque (Deque q, int *x){
    if(!isEmptyDeque(q)){
        *x = q.back->valor;
        return 0;
    }return 1;
}

//? 9
int frontDeque (Deque q, int *x){
    if(!isEmptyDeque(q)){
        *x = q.front->valor;
        return 0;
    }return 1;
}


//! DequeC

//? 1
void initDequeC (DequeC *q){
    q->front = NULL;
}        

//? 2
int isEmptyDequeC (DequeC q){
    return q.front == NULL;
}         

//? 3
int pushBackDequeC (DequeC *q, int x){
    int wasEmpty;
    DList new = (DList) malloc(sizeof(struct dlist));
    new->valor = x;
    if(!isEmptyDequeC(*q)){
        new->prox = q->front->prox;
        q->front->prox->ant = new;
        q->front->prox = new;
        new->ant = q->front;
        wasEmpty = 0;
    }else{
        q->front = new;
        q->front->ant = q->front->prox = q->front;
        wasEmpty = 1;
    }
    return wasEmpty;
} 

//? 4
int pushFrontDequeC (DequeC *q, int x){
    int wasEmpty;
    DList new = (DList) malloc(sizeof(struct dlist));
    new->valor = x;
    if(!isEmptyDequeC(*q)){
        new->prox = q->front->prox;
        q->front->prox->ant = new;
        q->front->prox = new;
        new->ant = q->front;
        q->front = new;
        wasEmpty = 0;
    }else{
        q->front = new;
        q->front->ant = q->front;
        q->front->prox = q->front;
        wasEmpty = 1;
    }
    return wasEmpty;
} 

//? 5
int popBackDequeC (DequeC *q, int *x){
    if(!isEmptyDequeC(*q)){
        *x = q->front->prox->valor;
        if(q->front->prox == q->front){
            free(q->front);
            q->front = NULL;
        }else{
            DList temp = q->front->prox->prox;
            temp->ant = q->front;
            free(q->front->prox);
            q->front->prox = temp;
        }
        return 0;
    }return 1;
}

//? 6
int popFrontDequeC (DequeC *q, int *x){
    if(!isEmptyDequeC(*q)){
        *x = q->front->valor;
        if(q->front == q->front->prox){
            free(q->front);
            q->front = NULL;
        }else{
            DList temp = q->front->ant;
            temp->prox = q->front->prox;
            q->front->prox->ant = temp;
            free(q->front);
            q->front = temp;
        }
        return 0;
    }return 1;
}

//? 7
int popMaxDequeC (DequeC *q, int *x){
    if(!isEmptyDequeC(*q)){
        DList start = q->front->prox;
        DList end = q->front;

        while(start != end){
            if(start->valor > end->valor) end = end->ant;
            else start = start->prox;
        }
        if(start->ant == q->front) popBackDequeC(q,x);
        else if(end == q->front) popFrontDequeC(q,x);
        else{
            *x = start->valor;
            start = start->ant; end = end->prox;
            free(start->prox);
            // free(end->ant);
            start->prox = end; end->ant = start;
        }
        return 0;
    }return 1;
}

//? 8
int backDequeC (DequeC q, int *x){
    if(!isEmptyDequeC(q)){
        *x = q.front->prox->valor;
        return 0;
    }return 1;
} 

//? 9
int frontDequeC (DequeC q, int *x){
    if(!isEmptyDequeC(q)){
        *x = q.front->valor;
        return 0;
    }return 1;
} 