#ifndef __E1718__
#define __E1718__




typedef struct celula
{
    char *palavra;
    int comp;
    struct celula *prox;
} * Palavras;

// Helpfull functions
Palavras newPalavra(char *palavra, int comp, Palavras rest);
void printPalavras(Palavras p);
void freePalavras(Palavras p);

// Exam Questions
int daPalavra(char *s, int *e);
Palavras words(char *texto);
Palavras daLinha(Palavras t, int n);
void escreveLinha(Palavras p, int n);
    int countWordsAndChars(Palavras p, int *nChars);
void formata(char texto[], int largura);

#endif