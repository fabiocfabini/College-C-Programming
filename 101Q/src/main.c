#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Q1.h"
#include "Q2.h"

int main(int argc, char **argv){
    LInt l = NULL;
    for (int i = 0; i < 5; i++){
        appendL(&l,i);
    }
    
    LInt clone = cloneRev(l);
    imprimeL(l);
    imprimeL(clone);

    freeL(clone);
    freeL(l);
    

    return 0;
}