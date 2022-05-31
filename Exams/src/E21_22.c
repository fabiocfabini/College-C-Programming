#include <stdio.h>
#include <math.h>
#include <string.h>
#include "../includes/E21_22.h"

void tobit(int v[], int x, int N){
	int i = 0;
	while(x > 0){
		v[i++] = x%2;
		x >>= 1;	
	}
	for(; i < N; v[i++] = 0);
}

void take(int v[], int N){
	for(int i = 0; i < N-1; v[i] = v[i+1], i++);
}

void remUsed(int p[], int bits[], int* N){
    int n = *N; int j = 0;
    for(int i = 0; i < n; i++){
        if(bits[i] == 1){
            take(p+j, *N-j); (*N)--;
        }else j++;
    }
}

int try(int p[], int bits[], int N, int C){
	for(int i = 0; i < N && C > 0; i++){
		if(bits[i] == 1) C -= p[i];
	}
	if(C >= 0) return C;
	return -1;
}

void enche(int p[], int* N, int C){
	int bits[*N]; int store[*N];
	int attempt = 1; int max = pow(2, *N);
	int c = *N; int CC = C;

	while(attempt < max && C != 0){
		tobit(bits, attempt, *N);
		c = try(p, bits, *N, C); attempt++;
		if(c != -1 && c < CC){
			CC = c;
			memcpy(store, bits, sizeof(int) * (*N));
		}
	}
	remUsed(p, store, N);
}

int sacos(int p[], int N, int C){
	int c = 0;
	while(N > 0){
		enche(p, &N, C);
		c++;
	}
	return c;
}