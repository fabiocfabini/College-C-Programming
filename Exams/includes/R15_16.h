#ifndef __R1516__
#define __R1516__

#define TOP 10
#define MAX_WORD_SIZE 60

typedef struct listaP{
    char *pal;
    int cont;
    struct listaP *prox;
} Nodo, *Hist;

// Helpfull functions
Hist newHist(char* pal, Hist h);
void freeHist(Hist h);
void filter(char* pal);

// Exam Questions
int inc(Hist *h, char *pal);
char *remMaisFreq(Hist *h, int *count);

#endif 