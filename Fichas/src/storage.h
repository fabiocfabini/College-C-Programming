#ifndef __STORAGE__
#define __STORAGE__

//! From Main
void print_array(int v[], int N);
int max(int x, int y);
void simNao (int x);

//! Ficha 1

/* 1 */ void makeSquare(int n);
/* 2 */ void chessBoard(int n);
/* 3 a*/ void sideTriangle(int n);
/* 3 b*/ void upTriangle(int n);

//! Ficha 2

/* 1 */ float multInt1 (int n, float m);
/* 2 */ float multInt2 (int n, float m);
/* 3 */ int mdc1 (int a, int b);
/* 4 */ int mdc2 (int a, int b);
/* 5 */ int mdc3 (int a, int b);
/* 6a */ int fib1 (int n);
/* 6b */ int fib2 (int n);

//! Ficha 3

/* 2 */ void swapM (int *x, int *y);
/* 3 */ void swap (int v[], int i, int j);
/* 4 */ int soma (int v[], int N);
/* 5 */ void inverteArray (int v[], int N);
/* 6 */ int maximum (int v[], int N, int *m);
/* 7 */ void quadrados (int q[], int N);
/* 8 */ void pascal (int v[], int N);

//! Ficha 4

//* Helpfull functions
int isVowel (char c);
int stringLen (char*s);

/* 1 */ int contaVogais (char *s);
/* 2 */ int retiraVogaisRep (char *s);
/* 3 */ int duplicaVogais (char *s);

/* 1 */ int ordenado (int v[], int N);
/* 2 */ void merge (int a[], int na, int b[], int nb, int r[]);
/* 3 */ int partition (int v[], int N, int x);

//! Ficha 5

typedef struct aluno{
    int numero;
    char nome[100];
    int miniT[6];
    float teste;
} Aluno;

// * Helpfull functions
void swapAluno(Aluno t[], int i, int j);
void porNumPartition(Aluno t[], int N, int* p);
void cipNUMPartition(Aluno t[], int ind[], int N, int * p);
void cipNUMRec (Aluno t[], int ind[], int N);
void cipNamePartition(Aluno t[], int ind[], int N, int *p);
void cipNameRec (Aluno t[], int ind[], int N);

/* 1 */ int nota (Aluno a);
/* 2 */ int procuraNum (int num, Aluno t[], int N);
/* 3 */ void ordenaPorNum (Aluno t [], int N);
/* 4 */ void criaIndPorNum (Aluno t [], int N, int ind[]);
/* 5 */ void imprimeTurma (int ind[], Aluno t[], int N);
/* 6 */ int procuraNumInd (int num, Aluno t[], int ind[], int N);
/* 7 */ void criaIndPorNome (Aluno t [], int N, int ind[]);

//! Ficha 6

#define Max 1
typedef struct staticStack{
    int sp;
    int values[Max];
}Stack, *SStack;

typedef struct staticQueue{
    int front;
    int length;
    int values[Max];
}QUEUE, *SQueue;

typedef struct dinStack {
    int size; // guarda o tamanho do array values
    int sp;
    int *values;
} *DStack;

typedef struct dinQueue {
    int size; // guarda o tamanho do array values
    int front;
    int length;
    int *values;
} *DQueue;


/* 1a */ void SinitStack(SStack s); 
/* 1b */ int SisEmpty (SStack s);
/* 1c */ int Spush (SStack s, int x);
/* 1d */ int Spop (SStack s, int *x);
/* 1e */ int Stop (SStack s, int *x);

/* 2a */ void SinitQueue (SQueue q);
/* 2b */ int SisEmptyQ (SQueue q);
/* 2c */ int Senqueue (SQueue q, int x);
/* 2d */ int Sdequeue (SQueue q, int *x);
/* 2e */ int Sfront (SQueue q, int *x);

/* 3a1 */ void DinitStack(DStack s);
/* 3a2 */ int DisEmpty (DStack s);
/* 3a3 */ int Dpush (DStack s, int x);
/* 3a4 */ int Dpop (DStack s, int *x);
/* 3a5 */ int Dtop (DStack s, int *x);

/* 3b1 */ void DinitQueue (DQueue q);
/* 3b2 */ int DisEmptyQ (DQueue q);
/* 3b3 */ int Denqueue (DQueue q, int x);
/* 3b4 */ int Ddequeue (DQueue q, int *x);
/* 3b5 */ int Dfront (DQueue q, int *x);

//! Ficha 7

typedef struct celula{
    char* palavra;
    int ocorr;
    struct celula* prox;
}*Palavras;

/* 1 */ void libertaLista (Palavras);
/* 2 */ int quantasP (Palavras l);
/* 3 */ void listaPal (Palavras l);
/* 4 */ char* ultima (Palavras l);
/* 5 */ Palavras acrescentaInicio (Palavras l, char *p);
/* 6 */ Palavras acrescentaFim (Palavras l, char *p);
/* 7 */ Palavras acrescenta (Palavras l, char *p);
/* 8 */ struct celula * maisFreq (Palavras l);

//! Ficha 8

typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;

typedef LInt LStack;
typedef struct{
    LInt fim;
}LQueueC;
typedef struct {
    LInt inicio,fim;
} LQueue;

typedef struct dlist {
    int valor;
    struct dlist *ant, *prox;
} *DList;

typedef struct{
    DList front;
} DequeC;

typedef struct {
    DList back, front;
} Deque;

//* Helpfull functions
void printLStack(LStack s);
void printLQueue(LQueue q);
void printLQC(LQueueC q);
void printDeque(Deque d);
void printDequeC(DequeC d);


//* LStack
/* 1 */ void LinitStack (LStack *s);
/* 2 */ int LisEmpty (LStack s);
/* 3 */ int Lpush (LStack *s, int x);
/* 4 */ int Lpop (LStack *s, int *x);
/* 5 */ int Ltop (LStack s, int *x);

//* LQueue
/* 1 */ void LinitQueue (LQueue *q);
/* 2 */ int LQisEmpty (LQueue q);
/* 3 */ int Lenqueue (LQueue *q, int x);
/* 4 */ int Ldequeue (LQueue *q, int *x);
/* 5 */ int Lfront (LQueue q, int *x);

//* LQueueC
/* 1 */ void LinitQueueC (LQueueC *q);
/* 2 */ int LQCisEmpty (LQueueC q);
/* 3 */ int LenqueueC (LQueueC *q, int x);
/* 4 */ int LdequeueC (LQueueC *q, int *x);
/* 5 */ int LfrontC (LQueueC q, int *x);

//* Deque
/* 1 */ void initDeque (Deque *q);          
/* 2 */ int isEmptyDeque (Deque q);              
/* 3 */ int pushBackDeque (Deque *q, int x);             
/* 4 */ int pushFrontDeque (Deque *q, int x);          
/* 5 */ int popBackDeque (Deque *q, int *x);            
/* 6 */ int popFrontDeque (Deque *q, int *x);              
/* 7 */ int popMaxDeque (Deque *q, int *x);               
/* 8 */ int backDeque (Deque q, int *x);           
/* 9 */ int frontDeque (Deque q, int *x);              

//* DequeC
/* 1 */ void initDequeC (DequeC *q);            
/* 2 */ int isEmptyDequeC (DequeC q);              
/* 3 */ int pushBackDequeC (DequeC *q, int x);              
/* 4 */ int pushFrontDequeC (DequeC *q, int x);          
/* 5 */ int popBackDequeC (DequeC *q, int *x);              
/* 6 */ int popFrontDequeC (DequeC *q, int *x);            
/* 7 */ int popMaxDequeC (DequeC *q, int *x);             
/* 8 */ int backDequeC (DequeC q, int *x);               
/* 9 */ int frontDequeC (DequeC q, int *x);

//! Ficha 9

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

//* Helpfull Functions
#define COUNT 10
void print2DUtil(ABin a, int space);
void print2D(ABin a);
ABin newABin (int r, ABin e, ABin d);
ABin RandArvFromArray (int v[], int N);
void freeABin(ABin a);


/* 1 */ int altura (ABin a);
/* 2 */ int nFolhas (ABin a);
/* 3 */ ABin maisEsquerda (ABin a);
/* 4 */ void imprimeNivel (ABin a, int l);
/* 5 */ int procuraE (ABin a, int x);
/* 6 */ struct nodo *procura (ABin a, int x);
/* 7 */ int nivel (ABin a, int x);
/* 8 */ void imprimeAte (ABin a, int x);

//! Ficha 10

//* Helpfull Functions
void rodaEsquerda (ABin *a);
void rodaDireita (ABin *a);
int Balenced(ABin a);

/* 1 */ ABin removeMenor (ABin *a);
/* 2 */ void removeRaiz (ABin *a);
/* 3 */ int removeElem (ABin *a, int x);
/* 4 */ void promoveMenor (ABin *a);
/* 5 */ void promoveMaior (ABin *a);
/* 6 */ ABin removeMenorMelhor (ABin *a);
/* 7 */ int constroiEspinha (ABin *a);
/* 8 */ ABin equilibraEspinha (ABin *a, int n);
/* 9 */ void equilibra (ABin *a);

#endif