#include <stdio.h>
#include <stdlib.h>
#include "E13_14.h"
#include "E15_16.h"
#include "E16_17.h"
#include "E17_18.h"
#include "R14_15.h"
#include "R15_16.h"

int main(int argc, char **argv)
{
    LInt a = newLInt(1, newLInt(2, newLInt(3, newLInt(4, NULL))));
    LInt b = newLInt(-1, newLInt(-2, newLInt(-3, newLInt(-4, newLInt(5, NULL)))));

    int len;
    LPares z = zip(a, b, &len);
    printf("Size of zip: %d\n", len);
    printLPares(z);

    freeLInt(a);
    freeLInt(b);
    freePar(z);

    Tree root = newTree(1, newTree(2, NULL, NULL, NULL), newTree(3, NULL, NULL, NULL), NULL);

    calculaPais(root);

    freeTree(root);

    return 0;
}

//* R15_16
// char* words[TOP];
// int word_count[TOP], i = 0, hist_length = 0;
// char word[MAX_WORD_SIZE];
// Hist head = NULL;

// printf("Write something:\n");

// do
// {
//     scanf ("%60[^ \n]s", word);
//     filter(word);
//     hist_length += inc(&head, word);

// } while (getchar() != '\n');

// if(hist_length > TOP) hist_length = TOP;
// for(; i < hist_length; i++){
//     words[i] = remMaisFreq(&head, word_count+i);
// }

// for (i = 0; i < hist_length; i++){
//     printf("[%d] -> %s, %d\n", i+1, words[i], word_count[i]);
// }

// freeHist(head);
// printf("\nEND\n");

//* R14_15
// Alunos root   = newAluno("fabio", 1000, 14, NULL, NULL);
// Alunos rootl  = newAluno("lucas",  900,  2, NULL, NULL);
// Alunos rootll = newAluno("luisa",  800, 19, NULL, NULL);
// Alunos rootlr = newAluno("pedro",  950, 18, NULL, NULL);
// Alunos rootr  = newAluno("maria", 1100, 14, NULL, NULL);
// Alunos rootrl = newAluno("sofia", 1050, 18, NULL, NULL);
// Alunos rootrr = newAluno("santa", 1200, 20, NULL, NULL);
// root->esq = rootl; root->dir = rootr;
// rootl->esq = rootll; rootl->dir = rootlr;
// rootr->esq = rootrl; rootr->dir = rootrr;

// int freq[21];
// for (int i = 0; i < 21; freq[i++] = 0);
// int N = fnotas(root, freq);
// printf("There are %d students.\n\n", N);

// printf("Rank of %s is %d.\n\n", root->nome, rankAluno(root, root->numero, freq));

// StrList nota14;
// int n = comNota(root, 14, &nota14);
// printf("%d Students with 14: ", n);
// StrList aux = nota14;
// while(aux){
//     printf("%s, ", aux->string);
//     aux = aux->prox;
// } printf("\n\n");
// freeStrList(nota14);

// printf("ClassRoom:\n");
// imprime(root);

// freeAlunos(root);

//* E15_16
// Colunas col0 = newCol(0, 2, newCol(2, 3, newCol(3, 4, newCol(4, 5, NULL))));
// Colunas col1 = newCol(1, -2, newCol(4, 1, newCol(5, 4, NULL)));
// Colunas col2 = newCol(2, 2, NULL);
// Colunas col3 = newCol(0, -1, newCol(1, 4, newCol(3, 1, newCol(4, 9, NULL))));
// Colunas _col0 = newCol(0, 2, newCol(2, 3, newCol(3, 4, newCol(4, 5, NULL))));
// Colunas _col1 = newCol(1, -2, newCol(4, 1, newCol(5, 4, NULL)));
// Colunas _col2 = newCol(2, 2, NULL);
// Colunas _col3 = newCol(0, -1, newCol(1, 4, newCol(3, 1, newCol(4, 9, NULL))));

// Mat m = newLine(0, col0, newLine(2, col1, newLine(3, col2, newLine(5, col3, NULL))));
// Mat m1 = newLine(0, _col0, newLine(2, _col1, newLine(3, _col2, newLine(5, _col3, NULL))));

// printMat(m);

// int line = 6, col = 8, value = 7;
// printf("\nMatrix entry at line %d column %d: %g\n\n", line, col, getEntry(m, line, col));

// printf("Setting entry at line %d column %d equal to %d.\n", line, col, value);

// setEntry(&m, line, col, value);

// printf("\nMatrix entry at line %d column %d: %g\n\n", line, col, getEntry(m, line, col));

// printMat(m);

// printf("\nTransposing matrix m\n");

// transpose(&m);

// printMat(m);

// printf("\nAdding m1 to new m\n");
// addTo(&m, m1);
// printMat(m);

// freeMat(m);
// freeMat(m1);

//* E16_17
// int N = 10;
// StackC s;
// CList c = newCList(NULL);

// initStackC(&s, c);

// printf("\t");printStackC(s);
// for (int i = 0; i < N; i++){
//     push(&s, i);
//     printf("Pushed %d to StackC\n", i);
//     printf("\t");printStackC(s);
// }

// printf("\nThe Stack has %d elements\n\n", size(s));

// printf("Inverting StackC with pop push\n\t");
// Libreverse(&s);
// printStackC(s);
// printf("Inverting StackC w/out pop push\n\t");
// Libreverse(&s);
// printStackC(s);

// int x;
// for (int i = 0; i < N + 1; i++){
//     if(pop(&s, &x) == 0) printf("Removed %d from StackC.\n", x);
//     else printf("Empty StackC\nbin");
//     printf("\t");printStackC(s);
// }

// if(s.valores) freeCList(s.valores);

//* E17_18
    // formata(big_text, 100);