#ifndef __R20_21_H__
#define __R20_21_H__

#define COUNT 10

typedef struct mconj{
    char* word;
    int count;
    struct mconj *esq, *dir;
} *MConj;

void print2D(MConj a);

int acrescentaPal(MConj *m, char *pal);

#endif // __R20_21_H__