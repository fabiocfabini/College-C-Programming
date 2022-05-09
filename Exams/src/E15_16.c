#include <stdio.h>
#include <stdlib.h>
#include "../includes/E15_16.h"

// Helper functions
void freeMat(Mat m){
    while(m){
        while(m->lcol){
            Colunas ctemp = m->lcol->prox;
            free(m->lcol);
            m->lcol = ctemp;
        }
        Mat mtemp = m->prox;
        free(m);
        m = mtemp;
    }
}

void printMat(Mat m){
    printf("\nPrinting matrix\n");
    while(m){
        printf("%d: ", m->linha);
        Colunas col = m->lcol;
        while(col){
            printf("(%d, %g) -> ", col->coluna, col->valor);
            col = col->prox;
        }
        printf("NULL\n");
        m = m->prox;
    }
}

Colunas newCol(int column, float value, Colunas rest){
    Colunas new = malloc(sizeof(struct listaC));

    if(new){
        new->coluna = column;
        new->valor = value;
        new->prox = rest;
    }

    return new;
}

Mat newLine(int line, Colunas col, Mat rest){
    Mat new = malloc(sizeof(struct listaL));

    if(new){
        new->linha = line;
        new->lcol = col;
        new->prox = rest;
    }

    return new;
}


// Exam Questions
int getLine(Mat m, int line, Mat* mline){
    int res = 1; *mline = NULL;

    // m is still a line and the line is not found
    while(m && m->linha != line){
        // move to next line
        m = m->prox;
    }
    // Either m is null (no line in m) or m is the correct line
    if(m){
        // m is the correct line so ...
        res = 0;
        *mline = m;
    }
    return res;
}

int getColumn(Colunas col, int column, Colunas* mcol){
    int res = 1; *mcol = NULL;
    // col is still a column and the column is not found
    while(col && col->coluna != column){
        // move to next column
        col = col->prox;
    }
    // Either col is null (no column in col) or col is the correct column
    if(col){
        // col is the correct column so ...
        res = 0;
        *mcol = col;
    }
    return res;
}

float getEntry(Mat m, int line, int column){
    Mat mline;
    // Check for the line
    int res = getLine(m, line, &mline);
    float entry = 0.0;

    // if the line was found
    if(res != 1){
        Colunas mcol;
        // Check for the column
        res = getColumn(mline->lcol, column, &mcol);

        // if the column was found
        if(res != 1) entry = mcol->valor;
    }

    return entry;
}

void setEntry (Mat *m, int line, int column, float value){
    // while the line is not found
    while(*m && (*m)->linha < line){
        m = &(*m)->prox;
    }
    // if the line was not in the matrix
    if(!(*m) || (*m)->linha != line){
        Colunas newC = newCol(column, value, NULL);
        Mat newL = newLine(line, newC, *m);
        *m = newL;
    }else{// the line was found
        Colunas* col = &(*m)->lcol;

        // while the column is not found
        while(*col && (*col)->coluna < column){
            col = &(*col)->prox;
        }
        // if the column was not in the line
        if(!(*col) || (*col)->coluna != column){
            Colunas newC = newCol(column, value, *col);
            *col = newC;
        }else{ // the column was found
            (*col)->valor = value;
        }
    }
}

void addTo (Mat *m1, Mat m2){
    //* O(n*n) bad 
    // while(m2){
    //     Colunas col = m2->lcol;
    //     while(col){
    //         int val = getEntry(*m1, m2->linha, col->coluna);
    //         setEntry(m1, m2->linha, col->coluna, val + col->valor);
    //         col = col->prox;
    //     }
    //     m2 = m2->prox;
    // }
    //* O(n) good
    // while both matrixes have lines
    while(*m1 && m2){ 
        // if the lines match
        if((*m1)->linha == m2->linha){
            Colunas* col1 = &(*m1)->lcol; Colunas col2 = m2->lcol;
            // while both lines have columns
            while(*col1 && col2){
                // if the columns match
                if((*col1)->coluna == col2->coluna){
                    (*col1)->valor += col2->valor;
                    col2 = col2->prox;
                // ih the columns don't match and col2 comes first 
                }else if((*col1)->coluna > col2->coluna){
                    Colunas new = newCol(col2->coluna, col2->valor, *col1);
                    *col1 = new; 
                    col2 = col2->prox;
                }
                col1 = &(*col1)->prox;
            }
            // if col2 has more columns
            while(col2){
                Colunas new = newCol(col2->coluna, col2->valor, *col1);
                *col1 = new; col1 = &(*col1)->prox;
                col2 = col2->prox;
            }
            m2 = m2->prox;
        // if the lines don't match and m2 comes first
        }else if((*m1)->linha > m2->linha){
            Mat new = newLine(m2->linha, m2->lcol, *m1);
            *m1 = new; 
            m2 = m2->prox;
        }
        m1 = &((*m1)->prox);
    }
    // if m2 has more lines
    while(m2){
        Colunas newC = NULL; Colunas* ad = &newC;
        Colunas col2 = m2->lcol;

        while(col2){
            *ad = newCol(col2->coluna, col2->valor, NULL);
            ad = &(*ad)->prox;
            col2 = col2->prox;
        }

        Mat newL = newLine(m2->linha, newC, *m1);
        *m1 = newL; m1 = &((*m1)->prox);
        m2 = m2->prox;
    }
}

void transpose (Mat *m){
    Mat M = *m;
    Mat aux = NULL;

    // Copy *m to aux
    while(M){
        Colunas col = (M)->lcol;
        while(col){
            setEntry(&aux, (col)->coluna, (M)->linha, (col)->valor);
            col = col->prox;
        }
        M = ((M)->prox);
    }

    // free *m
    freeMat(*m); *m = NULL;

    Mat AUX = aux;
    // Copy aux to *m
    while(AUX){
        Colunas col = (AUX)->lcol;
        while(col){
            setEntry(m, AUX->linha, col->coluna, col->valor);
            col = col->prox;
        }
        AUX = AUX->prox;
    }

    // free aux
    freeMat(aux);
}