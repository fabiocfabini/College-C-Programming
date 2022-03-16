#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "storage.h"


//? 2
void swapM (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//? 3
void swap (int v[], int i, int j){
    swapM(v+i,v+j);
}

//? 4 
int soma (int v[], int N){
    int c = 0;
    for (int i = 0; i < N; i++){
        c += v[i];
    }
    return c;
}

//? 5
void inverteArray (int v[], int N){
    for (int i = 0, k = N-1; k > i; i++,k--){
        swap(v,i,k);
    }
}

//? 6
int maximum (int v[], int N, int *m){
    *m = 0;

    for (int i = 0; i < N; i++){
        if(v[i] > *m) *m = v[i];
    }
    return *m;
}

//? 7
void quadrados (int q[], int N){
    if(N > 0) q[0] = 1;
    for (int i = 1; i < N; i++){
        q[i] = q[i-1] + (2*i+1);
    }
}

//? 8
void pascal (int v[], int N){
    v[0] = 1;
    printf("\t\t");print_array(v,1);
    for (int i = 1; i < N; i++){
        v[i] = 1;
        for (int j = i-1; j > 0 ; j--){
            v[j] += v[j-1];
        }
        printf("\t\t");print_array(v,i+1);
    }
}