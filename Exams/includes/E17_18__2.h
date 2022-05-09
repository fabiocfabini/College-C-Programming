#ifndef __E17_18__2__
#define __E17_18__2__

typedef struct _mheap {
    int valor;
    struct _mheap *esq, *dir;
} mheap, *MinHeap;

int minheapOK (MinHeap a);
int maxHeap (MinHeap a);
void removeMin (MinHeap *a);
void add (MinHeap*a, int x);
void heapSort (int v[], int N);
int kMaior (int v[], int N, int k);


#endif  