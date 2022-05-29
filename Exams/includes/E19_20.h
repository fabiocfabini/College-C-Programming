#ifndef __E19_20_H__
#define __E19_20_H__

#define COUNT 10

typedef struct dict{
    char* word;
    int count;
    struct dict *esq, *dir;
} *Dict;

void print2DD(Dict a);

Dict rodaDireita(Dict d);
Dict rodaEsquerda(Dict d);
Dict promoveMenor(Dict d);
Dict acrescenta(Dict d, char* word);

#endif // __E19_20_H__