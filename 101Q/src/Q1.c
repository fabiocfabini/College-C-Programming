#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <math.h>
#include "Q1.h"

//? 1
void scanLargest(){
    int max = INT_MIN, aux = INT_MIN;
    printf("[Type a list of numbers stopping at 0]:\n");
    while(aux != 0){
        scanf("%d",&aux);
        if(aux > max) max = aux;
    }
    printf("[%d is the largest number]:",max);
}

//? 2
void scanAverage(){
    int sum = 0, aux = 1, count = 0;
    printf("[Type a list of numbers stopping at 0]:\n");
    while(aux != 0){
        scanf("%d",&aux);
        sum += aux;
        count++;
    }
    printf("[%g is the average]:",(float) sum/count);
}

//? 3
void scan2ndLargest(){
    int max = INT_MIN, max2 = INT_MIN, aux = INT_MIN;
    printf("[Type a list of numbers stopping at 0]:\n");
    while(aux != 0){
        scanf("%d",&aux);
        if(aux > max2) max2 = aux;
        if(max2 > max) {max = max + max2; max2 = max - max2; max = max - max2;}
    }
    printf("[%d is the 2nd largest number]:",max2);
}

//? 4
int bitsUm(unsigned int n){
    int count = 0;

    while (n != 0){
        if(n % 2 == 1) count++;
        n >>= 1;
    }
    return count;
}

//? 5
int trailingZ(unsigned int n){
    unsigned int count = 0; // conta o nº de bits minimo
    unsigned int limit = pow(2,31);// maior unsigned int possivel

    while(n < limit && count < 32){// enquanto n < limite e nº de bits < 32
        n <<= 1; // fazer shift pra direita
        count++; // incrementar count
    }
    return (count == 32)? count: 31-count; // se count = 32 ent o valor é 0, caso contrario não é 0
}

//? 6
int qDig(unsigned int n){
    unsigned int aux = 1;
    int count = -1;

    while(aux < n){
        aux *= 10;
        count++;
    }
    return ++count;
}

//? 7
char *mystrcat(char s1[], char s2[]){
    char* aux1;
    char* aux2;

    for(aux1 = s1; *aux1 != '\0'; aux1++);
    for(aux2 = s2; *(aux2) != '\0'; aux2++){
        *aux1 = *aux2;
        aux1++;
    }*aux1 = '\0';
    return s1;
} 

//? 8
char *mystrcpy(char *dest, char source[]){
    char* auxD;
    char* auxS;

    for(auxD = dest, auxS = source; *auxS != '\0'; auxS++, auxD++){
        *auxD = *auxS;
    }*auxD = '\0';
    return dest;
}

//? 9
int mystrcmp(char s1[], char s2[]){
    char* aux1 = s1;
    char* aux2 = s2;

    while(*aux1 == *aux2 && *aux1 != '\0'){
        aux1++; aux2++;
    }
    return (*aux1 >= *aux2)? ((*aux1 == *aux2)? 0:1):-1;
}

//? 10
int my2strcmp(char s1[], char s2[]){
    char* aux1 = s1;
    char* aux2 = s2;

    while(*aux1 == *aux2 && *aux1 != '\0'){
        aux1++; aux2++;
    }
    return (*aux1 == '\0')? 1:0;
}
char *mystrstr(char s1[], char s2[]){
    char* aux1 = s1;
    if(*s2 == '\0') return s1;

    for (aux1 = s1; *aux1 != '\0'; aux1++){
        if(my2strcmp(s2, aux1)) return aux1;
    }
    return NULL;
}

//? 11
void mystrrev (char s[]){
    if(*s != '\0'){
        char* start = s;
        char* end = s;
        for(end = s; *(end+1) != '\0'; end++);
        for(; end > start; start++, end--){
            char temp = *start;
            *start = *end;
            *end = temp;
        }
    }
}

//? 12
int isVowel (char c){
    return 
        c == 'a' || c == 'A' ||
        c == 'e' || c == 'E' ||
        c == 'i' || c == 'I' ||
        c == 'o' || c == 'O' ||
        c == 'u' || c == 'U';
}
void takeFirstChar(char* s){
    if(*s != '\0'){
        char* aux = s;
        for(; *(aux+1) != '\0'; aux++){
            *aux = *(aux+1);
        }*aux = *(aux+1);
    }
}
void mystrnoV (char s[]){
    if(*s != '\0'){
        char* aux = s;
        for(; *aux != '\0'; aux++){
            if(isVowel(*aux)) {takeFirstChar(aux); aux--;}
        }
    }
}

//? 13
void truncw(char* s, int n){
    if(*s != '\0'){
        char* aux = s;
        int i;
        for(i = 0; i < n; i++){
            if(*aux != ' ' && *aux != '\0'){
                aux++;
            }else break;
        }
        if(*aux != ' ' && *aux != '\0'){
            for(; *aux != ' ' && *aux != '\0'; aux++){
                takeFirstChar(aux); aux--;
            }
        }
    }
}
void truncW (char s[], int n){
    if(*s != '\0'){
        char* aux = s;
        for(; *aux != '\0'; aux++){
            if(*aux != ' ') {truncw(aux,n);}
        }
    }
}

//? 14
int countChar(char* s, char p){
    int count = 0;
    char* aux = s;
    for(; *aux; aux++){
        if(*aux == p) count++;
    }
    return count;
}
char charMaisfreq (char s[]){
    char max = 0;
    int freq = 0;
    int freqMax = 0;
    char* aux;

    for(aux = s; *aux; aux++){
        freq = countChar(aux,*aux);
        if(freq > freqMax){
            freqMax = freq;
            max = *aux;
        }
    }
    return max;
}

//? 15
int iguaisConsecutivos (char s[]){
    if(*s){
        int max = 1;
        int c = 1;
        char curr = *s;
        char* aux = s+1;

        for(; *aux; aux++){
            if(*aux == curr){
                c++;
                if(c > max) max = c;
            }else {curr = *aux; c = 1;}
        }
        return max;
    } return 0;
}

//? 16
int stringElem(char* start, char* finish, char p){
    for(;start != finish; start++){
        if(*start == p) return 1;
    }return 0;
}
int difConsecutivos (char s[]){
    if(*s){
        int max = 1;
        int c = 1;
        char* back = s;
        char* front = s+1;
        for(; *front; front++){
            if(!stringElem(back,front,*front)){
                c++;
                if(c > max) max = c;
            }else{
                back++;
                front = back;
                c = 1;
            }
        }
        return max;
    } return 0;
}

//? 17
int maiorPrefixo (char s1 [], char s2 []){
    int c = 0;
    for(; *s1 && *s2 && *s1 == *s2; s1++, s2++, c++);
    return c;
}

//? 18
int maiorSufixo (char s1 [], char s2 []){
    int c = -1;
    char* start1 = s1;
    char* start2 = s2;
    while(*s1 || *s2){
        if(*s1) s1++;
        if(*s2) s2++;
    }
    for(; s1 != start1 && s2 != start2 && *s2 == *s1; s1--, s2--, c++);
    
    return c + (*s1 == *s2);
}

//? 19
int sufPref (char s1[], char s2[]){
    char* start = s2;
    int count = 0;

    while(*s1){
        if(*s1 != *s2){
                s2 = start;
                count = 0;
        }else{
            s2++;
            count++;
        }
        s1++;
    }
    return count;
}

//? 20
int contaPal (char s[]){
    int count = 0;
    if(*s){
        while(*s){
            while(*s == ' ' || *s == '\n' || *s == '\t') s++;
            if(*s != '\0'){
                count++;
                while(*s && *s != ' ') s++;
            }
        }
    }
    return count;
}

//? 21
int contaVogais (char s[]){
    int count = 0;
    for(; *s; s++){
        if(isVowel(*s)) count++;
    }
    return count;
}

//? 22
int elemChar(char* s, char p){
    for(; *s && *s != p ; s++);
    return (*s != '\0');
}
int contida (char a[], char b[]){
    for(; *a; a++){
        if(!elemChar(b,*a)) return 0;
    }
    return 1;
}

//? 23 
int palindorome (char s[]){
    if(!*s) return 1;
    char* end = s;
    for(end = s; *end; end++); end--;
    for(; *s == *end && s < end; s++, end--);
    return (end <= s);
}

//? 24
int remRep (char x[]){
    if(!*x) return 0;
    int count = 1;
    for(; *x; x++){
        if(*(x+1)){
            if(*x == *(x+1)){
                takeFirstChar(x); x--;
            }else{
                count++;
            }
        }
    }
    return count;
}

//? 25
int limpaEspacos (char t[]){
    int count = 0;
    while(*t){
        while(*t && *t != ' '){
            count++; t++;
        }
        if(!*t) break;
        while(*(t+1) && *(t+1) == ' '){
            takeFirstChar(t);
        }
        t++; count++;
    }
    return count;
}

//? 26
void insere (int v[], int N, int x){
    int i;
    for(i = N-1; i >= 0; i--){
        if(x >= v[i]) {v[i+1] = x; break;}
        else v[i+1] = v[i];
    }
    if(i == -1) v[0] = x;
}

//? 27
void merge (int r [], int a[], int b[], int na, int nb){
    int ia = 0, ib = 0;
    while(na > ia && nb > ib){
        if(a[ia] < b[ib]){
            r[ia+ib] = a[ia++];
        }else{
            r[ia+ib] = b[ib++];
        }
    }
    while(na > ia){
        r[ia+ib] = a[ia++];
    }
    while(nb > ib){
        r[ia+ib] = b[ib++];
    }
}

//? 28
int crescente (int a[], int i, int j){
    i++;
    int res = 1;
    for(; i <= j; i++){
        if(a[i] < a[i-1]) {res = 0; break;}
    }
    return res;
}

//? 29
void TakeFirstInt(int v[], int N){
    int i;
    for(i = 1; i < N; i++){
        v[i-1] = v[i];
    }
}
int retiraNeg (int v[], int N){
    int i;
    for(i = 0; i < N; i++){
        if(v[i] < 0){
            TakeFirstInt(v+i,N-i); N--; i--;
        }
    }
    return N;
}

//? 30
int menosFreq (int v[], int N){
    int i = 1;
    int out = v[0];
    int freq = 1, freqMin = 1;
    while(i < N && v[i] == v[0]){
        freqMin++;
        i++;
    }
    for(; i < N-1; i++){
        if(v[i] == v[i+1]){
            freq++;
        }else{
            if(freq < freqMin){
                freqMin = freq;
                out = v[i];
            }
            freq = 1;
        }
    }
    if(v[i] != v[i-1] && freqMin > 1) out = v[i];
    return out;
}

//? 31
int maisFreq (int v[], int N){
    int i = 1;
    int out = v[0];
    int freq = 1, freqMax = 1;
    for(; i < N; i++){
        if(v[i] == v[i-1]){
            freq++;
        }else{
            if(freq > freqMax){
                freqMax = freq;
                out = v[i-1];
            }
            freq = 1;
        }
    }
    if(freq > freqMax) out = v[i-1];
    return out;
}

//? 32
int maxCresc (int v[], int N){
    int i, cMax = 1, c = 1;
    for(i = 0; i < N; i++){
        if(v[i] <= v[i+1]){
            c++;
        }else{
            if(c > cMax) cMax = c;
            c = 1;
        }
    }
    if(c > cMax) cMax = c;
    return cMax;
}

//? 33
int elemInt(int v[], int i, int j, int x){
    for(; i < j; i++){
        if(v[i] == x) return 1;
    }return 0;
}
int elimRep (int v[], int n){
    int i = 1;
    for(; i < n; i++){
        if(elemInt(v,0,i,v[i])){
            TakeFirstInt(v+i,n-i); n--; i--;
        }
    }
    return n;
}

//? 34
int elimRepOrd (int v[], int n){
    int i;
    for(i = 1; i < n; i++){
        if(v[i] == v[i-1]){
            TakeFirstInt(v+i,n-i); n--; i--;
        }
    }
    return n;
}

//? 35
int comunsOrd (int a[], int na, int b[], int nb){
    int count = 0, ia = 0, ib = 0;
    while(na > ia && nb > ib){
        while(nb > ib && a[ia] > b[ib]) ib++;
        if(!(nb > ib)) break;
        while(na > ia && nb > ib && a[ia] == b[ib]){
            ia++; ib++; count++;
        }
        if(!(nb > ib)) break;
        while(na > ia && b[ib] > a[ia]) ia++;
    }
    return count;
}

//? 36
int elem(int v[], int N, int x){
    int i = 0;
    for(;i < N && v[i] != x; i++);
    return (i < N);
}
int comuns (int a[], int na, int b[], int nb){
    int i = 0, count = 0;
    for(; i < na; i++){
        if(elem(b,nb,a[i])) count++;
    }
    return count;
}

//? 37
int minInd (int v[], int n) {
    int i = 1;
    int min = v[0], indMin = 0;
    for(; i < n; i++){
        if(v[i] < min){
            min = v[i];
            indMin = i;
        }
    }
    return indMin;
}

//? 38
void somasAc (int v[], int Ac [], int N){
    int i = 1;
    Ac[0] = v[0];
    for(; i < N; i++) Ac[i] = v[i] + Ac[i-1];
}

//? 39
int triSup (int N, float m [N][N]){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < i; j++){
            if(m[i][j] != 0) return 0;
        }
    }
    return 1;
}

//? 40
void transposta (int N, float m [N][N]){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = i+1; j < N; j++){
            int temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

//? 41
void addTo (int N, int M, int a [N][M], int b[N][M]){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < M; j++){
            a[i][j] += b[i][j];
        }
    }
}

//? 42
int unionSet (int N, int v1[N], int v2[N], int r[N]){
    int c = 0, i;
    for(i = 0; i < N; i++){
        r[i] = v1[i] || v2[i];
        c += r[i];
    }
    return c;
}

//? 43
int intersectSet (int N, int v1[N], int v2[N], int r[N]){
    int c = 0, i;
    for(i = 0; i < N; i++){
        r[i] = v1[i] && v2[i];
        c += r[i];
    }
    return c;
}

//? 44
int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
    int c = 0, i;
    for(i = 0; i < N; i++){
        r[i] = (v1[i] < v2[i])? v1[i]:v2[i];
        c += r[i];
    }
    return c;
}

//? 45
int unionMSet (int N, int v1[N], int v2[N], int r[N]){
    int c = 0, i;
    for(i = 0; i < N; i++){
        r[i] = (v1[i] > v2[i])? v1[i]:v2[i];
        c += r[i];
    }
    return c;
}

//? 46
int cardinalMSet (int N, int v[N]){
    int c = 0, i;
    for(i = 0; i < N; i++){
        c += v[i];
    }
    return c;
}

//? 47
Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i = 0;
    for(; i < N; i++){
        if(mov[i] == Norte) inicial.y++;
        else if(mov[i] == Sul) inicial.y--;
        else if(mov[i] == Este) inicial.x++;
        else if(mov[i] == Oeste) inicial.x--; 
    }
    return inicial;
}

//? 48
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i = 0;
    for(; i < N && (inicial.x != final.x || inicial.y != final.y); i++){
        if(inicial.x < final.x){
            mov[i] = Este;
            inicial.x++;
            continue;
        }else if(inicial.x > final.x){
            mov[i] = Oeste;
            inicial.x--;
            continue;
        }
        if(inicial.y < final.y){
            mov[i] = Norte;
            inicial.y++;
        }else if(inicial.y > final.y){
            mov[i] = Sul;
            inicial.y--;
        }
    }
    return (inicial.x == final.x && final.y == inicial.y)? i: -1;
}

//? 49
int maisCentral (Posicao pos[], int N){
    int i = 1;
    int res = 0;
    float minDist = sqrt((float) pos[0].x*pos[0].x + (float) pos[0].y*pos[0].y);
    float Dist = minDist;
    for(; i < N; i++){
        Dist = sqrt((float) pos[i].x*pos[i].x + (float) pos[i].y*pos[i].y);
        if(Dist < minDist){
            minDist = Dist;
            res = i;
        }
    }
    return res;
}

//? 50
int vizinhos (Posicao p, Posicao pos[], int N){
    int i, count = 0;
    for(i = 0; i < N; i++){
        if((abs(p.x-pos[i].x) == 1 && p.y == pos[i].y) || (abs(p.y-pos[i].y) == 1 && p.x == pos[i].x)) count++;
    }
    return count;
}

