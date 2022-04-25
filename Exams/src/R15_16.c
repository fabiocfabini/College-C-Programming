#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "R15_16.h"

// Helpfull Functions
Hist newHist(char* pal, Hist h){
    Hist new = malloc(sizeof(Nodo));

    if(new){
        new->pal = strdup(pal);
        new->cont = 1;
        new->prox = h;
    }

    return new;
}

void freeHist(Hist h){
    while(h){
        free(h->pal);
        Hist temp = h->prox;
        free(h);
        h = temp;
    }
}

void takeChar(char* s){
    for(; *s; s++){
        *s = *(s+1);
    }
}
void filter(char* pal){
    int i;
    // removes all non-alphabetic characters
    for(i = 0; pal[i]; i++){
        if(!isalpha(pal[i])){
            takeChar(pal+i--);
        }
    }

    // Makes all characters upper case
    for(i = 0; pal[i]; i++){
        pal[i] = toupper(pal[i]);
    }
}

// Exam Questions
int inc(Hist *h, char *pal){
    int r = 0; // r is code for added(1) or incremented(0)
    while(*h && strcmp((*h)->pal, pal) < 0){
        h = &(*h)->prox;
    }
    if(*h && strcmp((*h)->pal, pal) == 0){
        (*h)->cont++;
    }else{
        Hist new = newHist(pal, *h);
        *h = new;
        r = 1;
    }
    return r;
}


char *remMaisFreq(Hist *h, int *count){
    Hist* rem = h;

    while(*h){
        if((*rem)->cont < (*h)->cont){
            rem = h;
        }
        h = &(*h)->prox;
    }
    Hist temp = (*rem)->prox;

    *count = (*rem)->cont; char* pal = strdup((*rem)->pal);
    
    free((*rem)->pal); free(*rem);
    
    *rem = temp;
    
    return pal;
}
