#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/R14_15.h"

// Helpfull Functions
Alunos newAluno(char nome[50], int numero, int nota, Alunos e, Alunos d){
    Alunos new = malloc(sizeof(struct nodo));
    
    if(new){
        strcpy(new->nome, nome);
        new->numero = numero;
        new->nota = nota;
        new->esq = e;
        new->dir = d;
    }

    return new;
}

void freeAlunos(Alunos a){
    if(a){
        Alunos e_temp = a->esq; 
        Alunos d_temp = a->dir; 

        free(a);

        freeAlunos(e_temp);
        freeAlunos(d_temp);
    }
}

void freeStrList(StrList s){
    while(s){
        free(s->string);    
        StrList temp = s->prox;
        free(s);
        s = temp;
    }
}



// Exam Questions
int fnotas (Alunos a, int notas [21]){
    if(!a) return 0;
    notas[a->nota] += 1;
    return 1 + fnotas(a->esq, notas) + fnotas(a->dir, notas);
}


int rankAluno (Alunos a, int numero, int fnotas[21]){
    while(a->numero != numero){
        if(numero < a->numero){
            a = a->esq;
        }else a = a->dir;
    }

    return rankNota(a->nota, fnotas);
}

int rankNota(int nota, int fnotas[21]){
    int rank = 1;
    for(int i = 20; i >= 0 && i > nota; i--){
        rank += fnotas[i];
    }
    return rank;
}

int aux(Alunos a, int nota, StrList *l){
    if(!a) return 0;
    int res = 0;
    if(a->nota == nota){
        StrList new = malloc(sizeof(struct strlist));
        new->string = strdup(a->nome);
        new->prox = *l;
        *l = new;
        res = 1;
    }

    int e = aux(a->esq, nota, l);
    int d = aux(a->dir, nota, l);

    return res + e + d;
}

int comNota (Alunos a, int nota, StrList *l){
    *l = NULL;
    return aux(a, nota, l);
}

void preencheAux(Alunos a, Alunos t[], int freq[21], int filled[]){
    if(a){
        int idx = freq[a->nota] + rankNota(a->nota, freq) -2;
        while(filled[idx]) idx--;
        filled[idx] = 1;
        t[idx] = a; 
        preencheAux(a->esq, t, freq, filled);
        preencheAux(a->dir, t, freq, filled);
    }
}

int classSize(Alunos a){
    int res = 0;
    if(a){
        res = 1 + classSize(a->esq) + classSize(a->dir);
    }
    return res;
}

void preenche (Alunos a, Alunos t[], int freq[21]){
    int N = classSize(a);
    int filled[N];
    for (int i = 0; i < N; filled[i++] = 0);
    
    preencheAux(a, t, freq, filled);
}

void imprime ( Alunos a ) {
    int i;
    int notas[21];
    for (int i = 0; i < 21; notas[i++] = 0);
    int quantos = fnotas(a, notas);
    Alunos todos[quantos];
    preenche(a, todos, notas);
    for(i = 0;i < quantos; i++)
        printf("%d %s %d\n",
            todos[i]->numero,
            todos[i]->nome,
            todos[i]->nota
        );
}
