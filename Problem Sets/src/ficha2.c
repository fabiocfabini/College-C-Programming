#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "storage.h"


//? 1
float multInt1 (int n, float m){
    float c = 0;
    for(int i = 0; i < n; i++){
        c += m;
    }
    return c;
}

//? 2
float multInt2 (int n, float m){
    float c = 0;
    while(n > 0){
        if(n % 2 == 1) c += m;
        n /= 2; m *= 2;
    }
    return c;
}

//? 3
int mdc1 (int a, int b){
    int m,M; int mdc = 1;
    if(a > b) {m = b; M = a;} else {m = a; M = b;}
    for (int i = 2; i <= m; i++){
        if(m % i == 0 && M % i == 0) mdc = i;
    }
    return mdc;
}

//? 4
int mdc2 (int a, int b){
    while(a != 0 && b != 0){
        if (a > b) a -= b;
        else b -= a;
    }
    return (a == 0)? b: a;
}

//? 5
int mdc3 (int a, int b){
    while(a != 0 && b != 0){
        if (a > b) a %= b;
        else b %= a;
    }
    return (a == 0)? b: a;
}

//? 6a
int fib1 (int n){
    if(n < 2) return 1;
    return fib1(n-1) + fib1(n-2);
}

//? 6b
int fib2 (int n){
    if(n < 2) return 1;
    int f1 = 1, f2 = 1;
    int fn = f1 + f2;
    while(n > 2){
        f1 = f2; f2 = fn;
        fn = f1 + f2;
        n--;
    } 
    return fn;
}
