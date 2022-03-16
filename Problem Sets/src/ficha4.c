#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "storage.h"


//! Funções sobre strings

//* Helpfull functions
int isVowel (char c){
    return 
        c == 'a' || c == 'A' ||
        c == 'e' || c == 'E' ||
        c == 'i' || c == 'I' ||
        c == 'o' || c == 'O' ||
        c == 'u' || c == 'U';
}
int stringLen (char*s){
    if(*s == '\0') return 0;
    return 1 + stringLen(s+1);
}


//? 1
int contaVogais (char *s){
    char* aux;
    int count = 0;

    for(aux = s; *aux != '\0'; aux++){
        if(isVowel(*aux)) count++;
    }

    return count;
}

//? 2
int retiraVogaisRep (char *s){
    char* aux;
    char lastV = '\0';
    int  count = 0;

    for (aux = s; *aux != '\0'; aux++){
        if(isVowel(*aux)){
            if(lastV == '\0') lastV = *aux;
            else if(lastV == *aux){
                char* aux2 = aux;
                for (aux2 = aux; *aux2 != '\0'; aux2++){
                    *aux2 = *(aux2+1);
                }
                count++; aux--;
            }
        }else lastV = '\0';
    }
    return count;
}

//? 3
int duplicaVogais (char *s){
    int N = stringLen(s);
    char* aux = s;
    int count = 0;

    for (aux = s; *aux != '\0'; aux++){
        if(isVowel(*aux)){
            char* aux2;
            for (aux2 = s+N; aux2 >= aux; aux2--){
                *(aux2+1) = *aux2;
            }count++; aux++; N++;
        }
    }
    return count;
}


//! Arrays ordenados

//? 1
int ordenado (int v[], int N){
    for (int i = 1; i < N; i++){
        if(v[i-1] > v[i]) return 0;
    }
    return 1;
}

//? 2
void merge (int a[], int na, int b[], int nb, int r[]){
    int ia = 0, ib = 0;

    while(ia < na && ib < nb){
        if(a[ia] <= b[ib]) {r[ia+ib] = a[ia]; ia++;}
        else {r[ia+ib] = b[ib]; ib++;}
    }
    while(ia < na){
        r[ia+ib] = a[ia]; ia++;
    }
    while(ib < nb){
        r[ia+ib] = b[ib]; ib++;
    }
}

//? 3
int partition (int v[], int N, int x){
    int count = 0; int i = N-1;

    while(i >= count){
        if(v[i] <= x){
            swap(v,count,i);
            count++;
        }else i--;
    }
    return count;
}