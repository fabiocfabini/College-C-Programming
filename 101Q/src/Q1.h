#ifndef __Q1__
#define __Q1__

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
        int x, y;
}Posicao;

/* 1 */ void scanLargest();
/* 2 */ void scanAverage();
/* 3 */ void scan2ndLargest();
/* 4 */ int bitsUm (unsigned int n);
/* 5 */ int trailingZ (unsigned int n);
/* 6 */ int qDig (unsigned int n);
/* 7 */ char *mystrcat (char s1[], char s2[]);
/* 8 */ char *mystrcpy (char *dest, char source[]);
/* 9 */ int mystrcmp (char s1[], char s2[]);
/* 10*/ char *mystrstr(char s1[], char s2[]);
        int my2strcmp(char s1[], char s2[]);
/* 11*/ void mystrrev (char s[]);
/* 12*/ void mystrnoV (char s[]);
        int isVowel (char c);
        void takeFirstChar(char* s);
/* 13*/ void truncW (char t[], int n);
        void truncw (char* s, int n);
/* 14*/ char charMaisfreq (char s[]);
        int countChar(char* s, char p);
/* 15*/ int iguaisConsecutivos (char s[]);
/* 16*/ int difConsecutivos (char s[]);
        int stringElem(char* start, char* finish, char p);
/* 17*/ int maiorPrefixo (char s1 [], char s2 []);
/* 18*/ int maiorSufixo (char s1 [], char s2 []);
/* 19*/ int sufPref (char s1[], char s2[]);
/* 20*/ int contaPal (char s[]);
/* 21*/ int contaVogais (char s[]);
/* 22*/ int contida (char a[], char b[]);
/* 23*/ int palindorome (char s[]);
/* 24*/ int remRep (char x[]);
/* 25*/ int limpaEspacos (char t[]);
/* 26*/ void insere (int v[], int N, int x);
/* 27*/ void merge (int r [], int a[], int b[], int na, int nb);
/* 28*/ int crescente (int a[], int i, int j);
/* 29*/ int retiraNeg (int v[], int N);
        void TakeFirstInt(int v[], int N);
/* 30*/ int menosFreq (int v[], int N);
/* 31*/ int maisFreq (int v[], int N);
/* 32*/ int maxCresc (int v[], int N);
/* 33*/ int elimRep (int v[], int n);
        int elemInt(int v[], int i, int j, int x);
/* 34*/ int elimRepOrd (int v[], int n);
/* 35*/ int comunsOrd (int a[], int na, int b[], int nb);
/* 36*/ int comuns (int a[], int na, int b[], int nb);
        int elem(int v[], int N, int x);
/* 37*/ int minInd (int v[], int n);
/* 38*/ void somasAc (int v[], int Ac [], int N);
/* 39*/ int triSup (int N, float m [N][N]);
/* 40*/ void transposta (int N, float m [N][N]);
/* 41*/ void addTo (int N, int M, int a [N][M], int b[N][M]);
/* 42*/ int unionSet (int N, int v1[N], int v2[N], int r[N]);
/* 43*/ int intersectSet (int N, int v1[N], int v2[N], int r[N]);
/* 44*/ int intersectMSet (int N, int v1[N], int v2[N], int r[N]);
/* 45*/ int unionMSet (int N, int v1[N], int v2[N], int r[N]);
/* 46*/ int cardinalMSet (int N, int v[N]);
/* 47*/ Posicao posFinal (Posicao inicial, Movimento mov[], int N);
/* 48*/ int caminho (Posicao inicial, Posicao final, Movimento mov[], int N);
/* 49*/ int maisCentral (Posicao pos[], int N);
/* 50*/ int vizinhos (Posicao p, Posicao pos[], int N);

#endif