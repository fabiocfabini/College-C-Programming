#ifndef __E1516__
#define __E1516__

typedef struct listaC {
    int coluna;
    float valor;
    struct listaC *prox;
} *Colunas;

typedef struct listaL {
    int linha;
    Colunas lcol;
    struct listaL *prox;
} *Mat;

// Helpfull functions
void freeMat(Mat m);
void printMat(Mat m);
Colunas newCol(int column, float value, Colunas rest);
Mat newLine(int line, Colunas col, Mat rest);

// Exam Questions
float getEntry (Mat m, int linha, int coluna);
    int getLine(Mat m, int line, Mat* mline);
    int getColumn(Colunas col, int column, Colunas* mcol);
void setEntry (Mat *m, int linha, int coluna, float valor);
void addTo (Mat *m1, Mat m2);
void transpose (Mat *m);

#endif