#ifndef __E2021__
#define __E2021__

typedef struct mc{
    int val;
    int count;
    struct mc* prox;
}*MC;

int sumhtpo (int n);
int moda(int v[], int N, int *m);

#endif // __E2021__