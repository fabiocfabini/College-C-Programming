#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/E19_20.h"

//* Helpfull Functions

void print2DDUtil(Dict a, int space)
{
    // Base case
    if (a == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DDUtil(a->dir, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("(%s, %d)\n", a->word, a->count);

    // Process left child
    print2DDUtil(a->esq, space);
}

void print2DD(Dict a){
   // Pass initial space count as 0
    printf("\n--------------------------\n");
    print2DDUtil(a, 0);
    printf("\n--------------------------\n");
}

//* Exam Questions
Dict rodaDireita(Dict d){
    Dict r = d->esq;
    d->esq = r->dir;
    r->dir = d;
    return r;
}
/*
This funcion will produce an error if:
    d == NULL - When trying to access the field esq (in line 6 "d->esq")
    d->esq == NULL - When trying to access the field dir (in line 7 "r->dir")

Let d be the following Dict:
        d
         \
          1
         / *
        2
       / *
      3
     * *

The result would be:
        d
         \
          2
         / \
        3   1
       * * * *
*/


Dict rodaEsquerda(Dict d){
    Dict l = d->dir;
    d->dir = l->esq;
    l->esq = d;
    return l;
}
// Reverse the previous answer

void promoveMenorEasy(Dict* d){
    if(*d && (*d)->esq){
        promoveMenorEasy(&(*d)->esq);
        *d = rodaDireita(*d);
    }
}

Dict promoveMenor(Dict d){
    promoveMenorEasy(&d);
    return d;
}


void addWord(Dict* d, char* word){
    int ord;
    while(*d){
        ord = strcmp(word, (*d)->word);
        if(ord == 0){
            (*d)->count++;
            break;
        }else if(ord < 0){
            d = &(*d)->esq;
        }else{
            d = &(*d)->dir;
        }
    }
    if(!(*d)){
        *d = malloc(sizeof(struct dict));
        (*d)->count = 1;
        (*d)->word = strdup(word);
        (*d)->esq = (*d)->dir = NULL;
    }
}

void promoteWord(Dict* d, char* word){
    if(*d){
        int ord = strcmp(word, (*d)->word);
        if(ord < 0){
            if(strcmp(word, (*d)->esq->word) == 0){
                *d = rodaDireita(*d);
            }else{
                promoteWord(&(*d)->esq, word);
                *d = rodaDireita(*d);
            }
        }else{
            if(strcmp(word, (*d)->dir->word) == 0){
                *d = rodaEsquerda(*d);
            }else{
                promoteWord(&(*d)->dir, word);
                *d = rodaEsquerda(*d);
            }
        }
    }
}

Dict acrescenta(Dict d, char* word){
    addWord(&d, word);
    if(strcmp(word, d->word) != 0) promoteWord(&d, word);
    return d;
}


