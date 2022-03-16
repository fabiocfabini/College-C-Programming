#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "storage.h"


//* Helpfull functions
void swapAluno(Aluno t[], int i, int j){
    Aluno temp = t[i];
    t[i] = t[j];
    t[j] = temp;
    }
void porNumPartition(Aluno t[], int N, int* p){
    int i = 0; int pp = *p;

    while(pp != i){
        if(t[(pp)].numero > t[(pp-1)].numero) swapAluno(t,i++,(pp-1));
        else {swapAluno(t,pp,-1+pp);pp--;}
    }
    *p = pp;
}
void cipNumPartition(Aluno t[], int ind[], int N, int * p){
    int i = 0; int pp = *p;

    while(pp != i){
        if(t[ind[pp]].numero > t[ind[pp-1]].numero) swap(ind,i++,pp-1);
        else {swap(ind,pp,pp-1); pp--;}
    }
    *p = pp;
}
void cipNumRec (Aluno t[], int ind[], int N){
    int p = N-1;
    if(N > 1){
        cipNumPartition(t,ind,N,&p);
            cipNumRec(t,ind,p);
            cipNumRec(t,ind+p+1,N-p-1);
    }
}
void cipNamePartition(Aluno t[], int ind[], int N, int *p){
    int i = 0; int pp = *p;

    while(pp != i){
        if(strcmp(t[ind[pp]].nome,t[ind[pp-1]].nome) > 0) swap(ind,i++,pp-1);
        else {swap(ind,pp-1,pp); pp--;}
    }
    *p = pp;
}
void cipNameRec (Aluno t[], int ind[], int N){
    int p = N-1;
    if(N > 1){
        cipNamePartition(t,ind,N,&p);
            cipNameRec(t,ind,p);
            cipNameRec(t,ind+p+1,N-p-1);
    }
}


//? 1
int nota (Aluno a){
    //* Não sei quais são os critérios;
    return 0;
}

//? 2
int procuraNum (int num, Aluno t[], int N){
    for (int i = 0; i < N; i++){
        if(num == t[i].numero) return i;
    }
    return -1;
}

//? 3
void ordenaPorNum (Aluno t[], int N){
    int p = N-1;
    if(N > 1){
        porNumPartition(t,N,&p);
            ordenaPorNum(t,p);
            ordenaPorNum(t+p+1,N-p-1);
    }
}

//? 4
void criaIndPorNum (Aluno t [], int N, int ind[]){
    for (int i = 0; i < N; i++) ind[i] = i;
    cipNumRec(t,ind,N);
}

//? 5
void imprimeTurma (int ind[], Aluno t[], int N){
    for (int i = 0; i < N; i++){ Aluno atual = t[ind[i]];
        printf("\t\tNome: %s\t Número. %d\n", atual.nome, atual.numero);
        for(int j = 0; j < 6; printf("\t\t\t[Mini Teste %d] -> %d\n",j+1,atual.miniT[j]), j++);
        printf("\t\t\tTeste Final -> %g\n", atual.teste);
    }
}

//? 6
int procuraNumInd (int num, Aluno t[], int ind[], int N){
    for (int i = 0; i < N; i++){
        int numAtual = t[ind[i]].numero;
        if(num == numAtual) return ind[i];
        else if (num < numAtual) break;
    }
    return -1;
}

//? 7
void criaIndPorNome (Aluno t [], int N, int ind[]){
    for (int i = 0; i < N; i++) ind[i] = i;
    cipNameRec(t,ind,N);
}
