#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/R20_21.h"


// Helpfull Functions
void rotateRight(MConj* m){
    MConj temp = (*m)->esq;
    (*m)->esq = temp->dir;
    temp->dir = *m;
    *m = temp;
}

void rotateLeft(MConj* m){
    MConj temp = (*m)->dir;
    (*m)->dir = temp->esq;
    temp->esq = *m;
    *m = temp;
}

void print2DUtil(MConj a, int space)
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
    printf("(%s, %d)\n", a->word, a->count);

    // Process left child
    print2DUtil(a->esq, space);
}

void print2D(MConj a){
   // Pass initial space count as 0
    print2DUtil(a, 0);
}

// Exam Questions

void fixMConj(MConj* m, char* pal){
    int ord = strcmp(pal, (*m)->word);
    if(ord < 0){
        if(strcmp(pal, (*m)->esq->word) == 0 && (*m)->count < (*m)->esq->count){
            rotateRight(m);
        }else{
            fixMConj(&(*m)->esq, pal);
            if(strcmp(pal, (*m)->esq->word) == 0 && (*m)->count < (*m)->esq->count){
                rotateRight(m);
            }
        }
    }else{
        if(strcmp(pal, (*m)->dir->word) == 0 && (*m)->count < (*m)->dir->count){
            rotateLeft(m);
        }else{
            fixMConj(&(*m)->dir, pal);
            if(strcmp(pal, (*m)->dir->word) == 0 && (*m)->count < (*m)->dir->count){
                rotateLeft(m);
            }
        }
    }
}

int aPaux(MConj* root, MConj* m, char* pal, int* fatherCount){
    if(!(*m)){
        *m = malloc(sizeof(struct mconj));
        (*m)->word = strdup(pal);
        (*m)->count = 1;
        (*m)->dir = (*m)->esq = NULL;
        return (*m)->count;
    }else{
        int ord = strcmp(pal, (*m)->word);
        if(ord == 0){ // found pal
            int r = ++(*m)->count;
            if((*m)->count > *fatherCount){
                fixMConj(root, pal);
            }
            return r;
        }else if(ord < 0){ // pal is on the left 
            return aPaux(root, &(*m)->esq, pal, &(*m)->count);
        }else{ // pal is on the right
            return aPaux(root, &(*m)->dir, pal, &(*m)->count);
        }
    }
}

int acrescentaPal(MConj *m, char *pal){
    return aPaux(m, m, pal, &(*m)->count);
}
