#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "storage.h"


//! Estado e atribuições

//? 1
// int x, y;
// x = 3; y = x+1;
    //* x = 3 && y = 4
// x = x*y; y = x + y;
    //* x = 12 && y = 16
// printf("%d %d\n", x, y);
    //* out: 12 16

//? 2
// int x, y;
// x = 0;
    //* x = 0 && y = lixo
// printf ("%d %d\n", x, y); //* ERRO y não inicializado 

//? 3
// char a, b, c;
// a = ’A’; b = ’ ’; c = ’0’;
    //* a = 'A' && b = ' ' && c = '0' 
// printf ("%c %d\n", a, a);
    //* out: A 65
// a = a+1; c = c+2;
    //* a = 'B' b = ' ' && c = '2'
// printf ("%c %d %c %d\n", a, a, c, c);
    //* out: B 66 2 50
// c = a + b;
    //* c = 'b'
// printf ("%c %d\n", c, c);
    //* out: b 98

//? 4
// int x, y;
// x = 200; y = 100;
    //* x = 200 & y = 100
// x = x+y; y = x-y; x = x-y;
    //* x = 100 & y = 200
// printf ("%d %d\n", x, y);
    //* out: 100 200

//! Estruturas de controlo

//? 1
// int x, y;
// x = 3; y = 5;
    //* x = 3 && y = 5
// if (x > y) //* False
// y = 6;
    //* x = 3 && y = 5
// printf ("%d %d\n", x, y);
    //* out: 3 5

//? 2

// int x, y;
// x = y = 0;
    //* x = 0 && y = 0
// while (x != 11) {
// x = x+1; y += x;
// }
    //* x = 11 && y = 55
// printf ("%d %d\n", x, y);
    //* out: 11 55

//? 3
// int i;
// for (i=0; (i<20) ; i++)
// if (i%2 == 0) putchar (’_’);
// else putchar (’#’);
    //* out: _#_#_#_#_#_#_#_#_#_#

//? 4 
// void f (int n) {
// while (n>0) {
// if (n%2 == 0) putchar (’0’);
// else putchar (’1’);
// n = n/2;
// }
// putchar (’\n’);
// }
// int main () {
// int i;
// for (i=0;(i<16);i++)
// f (i);
// return 0;
// }
    //* out: bits de todos os numeros de 0 até 15 (ao contrário)


//! Programas iterativos

//? 1
void makeSquare(int n){
    for (int i = 0; i < n; i++){
        printf("\t\t");
        for (int j = 0; j < n; j++){
            putchar('#');
        }
        putchar('\n');
    }
}

//? 2
void chessBoard(int n){
    for (int i = 0; i < n; i++){
        printf("\t\t");
        for (int j = 0; j < n; j++){
            if(i % 2 == 0){
                if(j % 2 == 0) putchar('#');
                else putchar('_');
            }else{
                if(j % 2 == 0) putchar('_');
                else putchar('#');
            }
        }
        putchar('\n');
    }
}

//? 3
void sideTriangle(int n){
    int i = 1, up = 1, down = 0;

    while(i > 0){
        printf("\t\t");
        if(up){
            for(int j = 0; j < i; j++){
                putchar('#');
            }
            putchar('\n');
            i++;
            if(i == n+1) {up = 0; down = 1; i = n-1;}
        }else if (down){
            for(int j = 0; j < i; j++){
                putchar('#');
            }
            putchar('\n');
            i--;
        }
    }
}
void upTriangle(int n){
    for (int i = 1; i <= n ; i++){
        printf("\t\t");
        for (int j = n-i; j > 0; j--){
            putchar(' ');
        }
        for (int k = 0; k < 1 + 2*(i-1); k++){
            putchar('#');
        }
        putchar('\n');
    }
}

void circle(int n){
    for (int x = -n; x <= n; x++){
        printf("\t\t");
        for (int y = -n; y <= n; y++){
            if (n*n <= x*x + y*y){
                putchar('#');
            }
            else putchar(' ');
        }
        putchar('\n');
    }
}


