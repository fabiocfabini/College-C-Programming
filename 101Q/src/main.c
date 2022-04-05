#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Q1.h"
#include "Q2.h"

int main(int argc, char **argv){
    Posicao p1 = {0,0};
    Posicao p2 = {1,0};
    Posicao p3 = {2,0};
    Posicao p4 = {0,-1};
    Posicao p5 = {0,-1};
    Posicao p6 = {1,0};
    Posicao p7 = {1,-1};

    Posicao pos[] = {p1,p2,p3,p4,p5,p6};

    printf("%d\n", vizinhos(p1, pos, 6));

    return 0;
}