#ifndef __R1415__
#define __R1415__

typedef struct nodo {
    char nome [50];
    int numero ;
    int nota; // >=0, <=20
    struct nodo *esq, *dir;
}*Alunos;

typedef struct strlist{
    char *string;
    struct strlist *prox;
}*StrList;

// Helpfull functions
Alunos newAluno(char nome[50], int numero, int nota, Alunos e, Alunos d);
void freeAlunos(Alunos a);
void freeStrList(StrList s);

// Exam Questions
int fnotas (Alunos a, int notas [21]);
int rankAluno (Alunos a, int numero, int fnotas[21]);
int rankNota (int nota, int fnotas[21]);
int comNota (Alunos a, int nota, StrList *l);
    int aux(Alunos a, int nota, StrList *l);
void imprime ( Alunos a );
    void preenche (Alunos a, Alunos t[], int freq[21]);
    void preencheAux(Alunos a, Alunos t[], int freq[21], int filled[]);
    int classSize(Alunos a);


#endif