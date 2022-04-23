#include <stdio.h>
#include <stdlib.h>
#include "E15_16.h"

int main(int argc, char** argv){
    Colunas col0 = newCol(0, 2, newCol(2, 3, newCol(3, 4, newCol(4, 5, NULL))));
    Colunas col1 = newCol(1, -2, newCol(4, 1, newCol(5, 4, NULL)));
    Colunas col2 = newCol(2, 2, NULL);
    Colunas col3 = newCol(0, -1, newCol(1, 4, newCol(3, 1, newCol(4, 9, NULL))));
    Colunas _col0 = newCol(0, 2, newCol(2, 3, newCol(3, 4, newCol(4, 5, NULL))));
    Colunas _col1 = newCol(1, -2, newCol(4, 1, newCol(5, 4, NULL)));
    Colunas _col2 = newCol(2, 2, NULL);
    Colunas _col3 = newCol(0, -1, newCol(1, 4, newCol(3, 1, newCol(4, 9, NULL))));

    Mat m = newLine(0, col0, newLine(2, col1, newLine(3, col2, newLine(5, col3, NULL))));
    Mat m1 = newLine(0, _col0, newLine(2, _col1, newLine(3, _col2, newLine(5, _col3, NULL))));

    printMat(m);

    int line = 6, col = 8, value = 7;
    printf("\nMatrix entry at line %d column %d: %g\n\n", line, col, getEntry(m, line, col));

    printf("Setting entry at line %d column %d equal to %d.\n", line, col, value);

    setEntry(&m, line, col, value);

    printf("\nMatrix entry at line %d column %d: %g\n\n", line, col, getEntry(m, line, col));

    printMat(m);

    printf("\nTransposing matrix m\n");

    transpose(&m);

    printMat(m);

    printf("\nAdding m1 to new m\n");
    addTo(&m, m1);
    printMat(m);

    freeMat(m);
    freeMat(m1);

    return 0;
}
