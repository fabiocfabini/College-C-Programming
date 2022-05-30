#include <stdio.h>
#include <stdlib.h>
#include "../includes/E20_21.h"

void insere(int v[], int *len, int n){
    if(*len < 10){
        int i;
        for(i = *len-1; i >= 0 && v[i] > n; i--) v[i+1] = v[i];
        v[i+1] = n; (*len)++; 
    }else if(n < v[*len -1]){
        int i;
        for(i = *len-1; i >= 0 && v[i] > n; i--) v[i] = v[i-1];
        v[i+1] = n;
    }
}

int sumhtpo (int n) {
    int v[100];
    int len = 0;
    while (n != 1) {
        printf("%d ", n);
        insere(v, &len, n);
        if (n%2 == 0) n = n
        /2; else n = 1+(3*n);
    }
    printf("length: %d\n", len);
    if(len < 10) return -1;
    else return v[len-1];
}

void addMC(MC* m, int x){
    while(*m && (*m)->val != x) m = &(*m)->prox;
    if(*m){
        (*m)->count++;
    }else{
        *m = malloc(sizeof(struct mc));
        (*m)->val = x;
        (*m)->count = 1;
        (*m)->prox = NULL;
    }
}

int max(MC* m){
    MC* place = m;
    while(*m){
        if((*m)->count > (*place)->count) place = m;
        m = &(*m)->prox;
    }
    int r = (*place)->count;
    MC temp = (*place)->prox;
    free(*place); *place = temp;
    return r;
}

int look(MC m, int count){
    while(m && m->count != count) m = m->prox;
    return m != NULL;
}

int moda(int v[], int N, int *m){
    if(N < 1) return 0;
    MC mc = NULL;
    for(int i = 0; i < N; i++) addMC(&mc, v[i]);
    int _max = max(&mc);
    if(look(mc, _max)) return 0;
    else{
        *m = _max;
        return 1;
    }
}