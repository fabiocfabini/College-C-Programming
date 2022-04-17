#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "storage.h"

int max(int x, int y){
    return (x>y)? x:y;
}

void print_array(int v[], int N){
    for (int i = 0; i < N; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void simNao (int x){
    if (!x) printf (" not");
}

int verifyCommandLine(int argc, char* argv[], int* problemSetNum, int* erro);

int main(int argc, char *argv[]){
    int problemSetNum, erro;

    if(!verifyCommandLine(argc, argv, &problemSetNum, &erro)){
        if(erro == 1) printf("When executing the program specify which problem set you wish to test\n");
        else if(erro == 2) printf("To many argumens were given");
        else if(erro == 3) printf("Chose a valid problem set");
        return 0;
    }

    switch (problemSetNum)
    {
    case 1:
        if(1){
            printf("[START OF SCRIPT]\n");

            printf("\t[Drawing a square]\n");
            makeSquare(10);

            printf("\n\t[Drawing a chess board]\n");
            chessBoard(10);

            printf("\n\t[Drawing a side triangle]\n");
            sideTriangle(10);

            printf("\n\t[Drawing a up triangle]\n");
            upTriangle(10);

            printf("\n[END OF SCRIPT]\n");
        }
        break;
    case 2:
        if(1){
            int a,b,r1,r2,r3;
            float f, f1, f2;

            printf("[START OF SCRIPT]\n");
            printf ("\t[Input 2 numbers to be multiplied]: ");
            scanf ("%d", &a); scanf ("%f", &f);
            f1 = multInt1 (a,f);
            f2 = multInt2 (a,f);
            printf ("\t[Results of multiplication]: %f, %f\n", f1, f2);

            printf ("\t[Input two numbers to find their mdc]: ");
            scanf ("%d", &a); scanf ("%d", &b);

            r1 = mdc1 (a,b);
            r2 = mdc2 (a,b);
            r3 = mdc3 (a,b);
            printf ("\t[Results of mdc]: %d, %d, %d\n", r1, r2, r3);

            printf ("\t[Input a number to calculate it's fibonacci]: ");
            scanf ("%d", &a);
            printf ("\t\tFib2 (%d) = %d \n", a, fib2 (a));
            printf ("\t\tFib1 (%d) = %d \n", a, fib1 (a));
            printf("\n[END OF SCRIPT]\n");
        }
        break;
    case 3:
        if(1){
            int v[10] = {10, 6, 2, 3, 5, 1, 5, 9, 8, 7};
            int x = 3, y = 5;

            printf("[START OF SCRIPT]\n");

            printf("\t[Swapping x and y ...]:\n");
            printf("\t\tx = %d y = %d\n", x, y);
            swapM(&x, &y);
            printf("\t[Done]:\n");
            printf ("\t\tx = %d y = %d\n", x, y);

            printf("\t[Swapping the 1st and last elements of the array]:\n");
            printf("\t\t"); print_array(v,10);
            swap (v,0,9);
            printf("\t\t"); print_array(v,10);


            printf ("\t[Inverting]: "); print_array (v,10);
            inverteArray (v,10);
            printf ("\t[we get]:     "); print_array (v,10);

            // teste das funções maximum, soma e quadrados

            x = maximum (v,10, &y);
            printf ("\t[The biggest number in]: "); print_array (v,10);
            printf ("\t[Is]: %d\n", y);


            printf ("\t[The first 10 squares]: "); 
            quadrados (v,10); 
            print_array (v,10);


            x = soma (v,10);
            printf ("\t[The sum of the elements in]: "); print_array (v,10);
            printf ("\t[Is]: %d\n", x);

            printf ("\t[The first 10 pascal lines]:\n\n");
            pascal (v,10);

            printf ("\n[END OF SCRIPT]");
        }
        break;
    case 4:
        if(1){
            char s1 [100] = "Estaa e umaa string coom duuuplicadoos";
            int x;

            printf("[START OF SCRIPT]\n");
            
            printf ("\t[This string has %d vowels]:\"%s\"\n",contaVogais (s1),s1);

            x = retiraVogaisRep (s1);
            printf ("\t[%d vowels were removed, resulting in]: \"%s\"\n", x, s1);

            x = duplicaVogais (s1);
            printf ("\t[%d vowels were added, resulting in]: \"%s\"\n", x, s1);
        }
        if(1){
            int a [15] = {10, 3,45,56, 8,23,13,42,77,31,18,88,24,45, 1},
                b [10] = { 4,12,34,45,48,52,61,73,84,87}, 
                c [10] = { 1, 3, 8,22,33,35,38,41,44,49}, 
                d [50];
            int x;

            printf ("\n\t[The array]: "); print_array(a,15);
            printf ("\t[is"); simNao (ordenado (a,15)); printf(" sorted]:\n");
            printf ("\n\t[The array]: "); print_array(b,10);
            printf ("\t[is"); simNao (ordenado (b,10)); printf(" sorted]:\n");

            printf ("\n\t[Merging the array]: "); print_array (b,10);
            printf ("\n\t[and]:               "); print_array (c,10); 
            merge (b, 10, c, 10, d);
            printf ("\n\t[results in]:        "); print_array (d,20);

            printf ("\n\n\t[Partitioning the array]:  "); print_array (a,15);
            printf ("\n\t[using 30, results in] "); 
            x = partition (a,15,30); 
            print_array (a,15); printf ("\t[and returns]: %d \n", x);

            printf("\n[END OF SCRIPT]\n");
        }
        break;
    case 5:
        if(1){
            Aluno T [7] = {
                {4444, "André", {2,1,0,2,2,2}, 10.5},
                {3333, "Paulo", {0,0,2,2,2,1},  8.7},
                {8888, "Carla", {2,1,2,1,0,1}, 14.5},
                {2222, "Joana", {2,0,2,1,0,2},  3.5},
                {7777, "Maria", {2,2,2,2,2,1},  5.5},
                {6666, "Bruna", {2,2,2,1,0,0}, 12.5},
                {5555, "Diogo", {2,2,1,1,1,0},  8.5}
            };
            int v[7] = {0,1,2,3,4,5,6};
            int ind[7];

            printf("[START OF SCRIPT]\n\n");

            printf("\t[Initial Class]\n");
            imprimeTurma(v,T,7);

            printf("\t[Creating Index List By Number]: ");
            criaIndPorNum(T,7,ind);
            print_array(ind,7);
            printf("\t[Printing Class]\n");
            imprimeTurma(ind,T,7);

            printf("\t[Creating Index List By Name]: ");
            criaIndPorNome(T,7,ind);
            print_array(ind,7);
            printf("\t[Printing Class]\n");
            imprimeTurma(ind,T,7);

            printf("\t[Sorting By Number ...");
            ordenaPorNum(T,7);
            printf(" Done]\n");
            printf("\t[Printing Class]\n");
            imprimeTurma(v,T,7);

            printf("\t[Search Number 4444]\n");
            printf("\t\t[Found %s]\n", T[procuraNum(4444,T,7)].nome);

            printf("\n[END OF SCRIPT]");
        }
        break;
    case 6:
        if(1){
            srand(time(NULL));
            int n;

            struct dinStack s1;
            struct dinQueue q1;

            DStack S = &s1;
            DQueue Q = &q1;
            printf("\n[START OF SCRIPT]\n");

            printf("\t[Preparing Stack and Queue]\n");
            DinitStack(S);
            DinitQueue(Q);

            for(int i = 0; i < 50; i++){
                n = rand()%10;
                if(n <= 5){
                    printf("\t\t[Inserting %d]\n", n);
                    Dpush(S,n);
                    Denqueue(Q,n);
                }else{
                    printf("\t\t[Removing ...]\n");
                    if(Dpop(S,&n) != 0) printf("\t\t[ERROR] EMPTY STACK\n");
                    if(Ddequeue(Q,&n) != 0) printf("\t\t[ERROR] EMPTY QUEUE\n");
                }
                printf("\t\t\t[Current Stack] ");
                showDStack(s1);
                printf("\t\t\t[Current Queue] ");
                showDQueue(q1);
            }
            free(S->values);
            free(Q->values);
            printf("[END OF SCRIPT]\n");
        }
        break;
    case 7:
        if(1){
            Palavras dic = NULL;

            char * canto1 [44] = {
                "as", "armas", "e", "os", "baroes", "assinalados",
                "que", "da", "ocidental", "praia", "lusitana", 
                "por", "mares", "nunca", "de", "antes", "navegados",
                "passaram", "ainda", "alem", "da", "taprobana",
                "em", "perigos", "e", "guerras", "esforcados",
                "mais", "do", "que", "prometia", "a", "forca", "humana",
                "e", "entre", "gente", "remota", "edificaram", 
                "novo", "reino", "que", "tanto", "sublimaram"
            };

            printf ("\n[START OF SCRIPT]\n");

            int i; struct celula *p;
            for (i=0;i<44;i++)
                dic = acrescentaInicio (dic, canto1[i]);

            printf ("\t[%d words were inserted]:\n", quantasP (dic));
            printf ("\t[Existing words]:\n\n");
            listaPal (dic);
            printf ("\t[Last inserted word]: %s\n\n", ultima (dic));

            libertaLista (dic);

            dic = NULL;

            srand(time(NULL));

            for (i=0; i<10000; i++)
                dic = acrescenta (dic, canto1 [rand() % 44]);

            printf ("\t[%d words were inserted]:\n", quantasP (dic));
            printf ("\t[Existing words]:\n\n");
            listaPal (dic);
            printf ("\t[Last inserted word]: %s\n\n", ultima (dic));

            p = maisFreq (dic);
            printf ("\t[Most frequent word]: %s (%d)\n", p->palavra, p->ocorr);

            printf ("\n[END OF SCRIPT]\n");
        }
        break;
    case 8:
        if(1){

            LStack S;
            LQueue Q;
            LQueueC C;
            int x;

            LinitStack(&S);
            LinitQueue(&Q);
            LinitQueueC(&C);

            printf("[BEGINNING TESTS]\n\n");

            // PUSH/ENQUEUE 
            printf("\t[Inserting elements in Stack, Queue, QueueC]\n");
            for (int i = 0; i < 20; i++){
                printf("\t\t[Inserting %d ...", i);
                Lpush(&S,i);
                Lenqueue(&Q,i);
                LenqueueC(&C,i);
                printf(" Done]\n");
                printf("\t\t\t");printLStack(S);
                printf("\t\t\t");printLQueue(Q);
                printf("\t\t\t");printLQC(C);
            }
            // POP/DEQUEUE
            printf("\t[Removing elements from Stack, Queue and QueueC]\n");
            for (int i = 0; i < 10; i++){
                Ltop(S,&x); printf("\t\t[Removing top of Stack (%d)]\n",x); Lpop(&S,&x);
                Lfront(Q,&x); printf("\t\t[Removing front of Queue (%d)]\n",x); Ldequeue(&Q,&x);
                LfrontC(C,&x); printf("\t\t[Removing front of QueueC (%d)]\n",x); LdequeueC(&C,&x);
                printf("\t\t\t");printLStack(S);
                printf("\t\t\t");printLQueue(Q);
                printf("\t\t\t");printLQC(C);
            }

            printf("\t[Final State]\n");

            printf("\t\tStack: ");
            while (!LisEmpty(S)){
                Lpop(&S,&x); printf("%d ", x);
            }
            printf("\n\t\tQueue: ");
            while (!LQisEmpty(Q)){
                Ldequeue(&Q,&x); printf("%d ", x);
            }
            printf("\n\t\tQueueC: ");
            while (!LQCisEmpty(C)){
                LdequeueC(&C,&x); printf("%d ", x);
            }
        }
        if(1){
            Deque D;
            DequeC C;
            int x;
            int n;

            srand(time(NULL));

            initDeque(&D);
            initDequeC(&C);

            // PUSH
            printf("\n\n\t[Inserting elements in Deque and DequeC]\n");
            for (int i = 0; i < 20; i++){
                n = rand();
                if(n % 2 == 0){
                    n %= 50;
                    printf("\t\t[Back Insert %d ... ",n);
                    pushBackDeque(&D,n);
                    pushBackDequeC(&C,n);
                    printf(" Done]\n");
                }else{
                    n %= 50;
                    printf("\t\t[Front Insert %d ... ",n);
                    pushFrontDeque(&D,n);
                    pushFrontDequeC(&C,n);
                    printf(" Done]\n");
                }
                printf("\t\t\t");printDeque(D);
                printf("\t\t\t");printDequeC(C);
            }

            // POP MAX
            int emptyD = 0;
            int emptyC = 0;
            printf("\t[Removing max elements in Deque and DequeC]\n");
            while(!emptyD || !emptyC){
                if(!isEmptyDeque(D)){
                    popMaxDeque(&D,&x); printf("\t\t[Removed max from Deque (%d)]\n",x);
                }else emptyD = 1;
                if(!isEmptyDequeC(C)){
                    popMaxDequeC(&C,&x); printf("\t\t[Removed max from DequeC (%d)]\n",x);
                }else emptyC = 1;
                if(!emptyD) {printf("\t\t\t");printDeque(D);}
                if(!emptyC) {printf("\t\t\t");printDequeC(C);}
            }

            printf("[END OF SCRIPT]");
        }
        break;
    case 9:
        if(1){
            int N = 15,
            i,
            v1[15],
            v2[15];

            ABin a1, a2, r;

            srand(time(NULL));
            for(i = 0; i < N; i++){v2[i] = rand()%N; v1[i] = i;}

            a1 = RandArvFromArray(v2, N);
            a2 = RandArvFromArray(v1, N);

            printf ("[START OF SCRIPT]\n\n");


            printf("\t[First test tree (%d elements)]\n", N);
            print2D(a1);

            printf("\t\t[Height]: %d\n", altura(a1));

            printf("\t\t[Number of leafs]: %d\n", nFolhas(a1));

            printf("\t\t[Left most node]: ");
            r = maisEsquerda(a1);
            if(r==NULL) printf("(NULL)\n"); else printf("%d\n",r->valor);

            printf("\t\t[Elements of level 3]: ");
            imprimeNivel(a1, 3);

            printf("\n\t\t[Search 9]: %d\n", procuraE (a1, 9));

            printf("\t\t[Search 4]: %d\n", procuraE (a1, 4));

            freeABin(a1);


            printf("\t[Second test tree (%d elements)]\n", N);
            print2D(a2);

            printf("\t\t[Search 9]: ");
            r = procura(a2, 9);
            if(r==NULL) printf("(NULL)\n"); else printf ("%d\n", r->valor);

            printf("\t\t[Search 4]: ");
            r = procura(a2, 4);
            if(r==NULL) printf("(NULL)\n"); else printf("%d\n", r->valor);

            printf("\t\t[Level of 9]: %d\n", nivel(a2, 9));

            printf("\t\t[Level of 4]: %d\n", nivel(a2, 4));

            printf("\t\t[Elements less than 9]: "); imprimeAte(a2, 9);

            freeABin(a1);


            printf("\n\n[END OF SCRIPT]\n\n");
        }
        break;
    case 10:
        if(1){
            int N = 15, i;
            int v1[N];
            ABin a,r;

            for(i = 0; i < N; i++) v1[i] = i;

            srand(time(NULL));

            a = RandArvFromArray(v1, N);


            printf("[START OF SCRIPT]\n\n");

            printf("\t[First test tree (%d elements)\n]", N);
            print2D(a);

            i = rand() %N;
            printf("\t\t[Removal of element (%d)]\n", v1[i]);
            removeElem(&a,v1[i]);
            print2D(a);

            r = removeMenorMelhor(&a);
            printf("\t\t[Removal of smallest element (%d)]\n", r->valor);
            print2D(a);

            printf("\t\t[Removal of root (%d)]\n", a->valor);
            removeRaiz(&a);
            print2D(a);

            freeABin(a);


            a = newABin(v1[7], RandArvFromArray (v1  ,7), RandArvFromArray (v1+8,7));

            printf("\t\t[Second test tree (%d elements)\n]\n", N);
            print2D(a);

            printf("\t\t[Right rotation]\n");
            rodaDireita(&a);
            print2D(a);

            printf("\t\t[Left rotation]\n");
            rodaEsquerda(&a);
            print2D(a);

            printf("\t\t[Promote bigger]\n");
            promoveMaior(&a);
            print2D(a);

            printf("\t\t[Promote smaller]\n");
            promoveMenor(&a);
            print2D(a);

            freeABin(a);


            a = newABin(v1[7], RandArvFromArray (v1  ,7), RandArvFromArray (v1+8,7));

            printf("\t\t[Third test tree (%d elements)]\n\n", N);
            print2D(a);

            printf("\t\t[Build Spine]\n");
            int n = constroiEspinha(&a);
            print2D(a);

            printf("\t\t[Balancing Spine]\n");
            equilibraEspinha(&a,n);
            print2D(a);

            printf("\t\t[Check Balance]: ");
            if(Balenced(a) != -1) printf("All good!\n"); else printf("Error\n"); 

            freeABin(a);


            printf("\n[END OF SCRIPT]\n");
        }
        break;
    }

    return 0;
}

int verifyCommandLine(int argc, char* argv[], int* problemSetNum, int* erro){
    if(argc < 2){
        *erro = 1;
    }else if(argc > 2){
        *erro = 2;
    }else{
        *problemSetNum = atoi(argv[1]);
        if(*problemSetNum < 1 || *problemSetNum > 10){
            *erro = 3;
        }else *erro = 0;
    }
    return (*erro)? 0:1;
}