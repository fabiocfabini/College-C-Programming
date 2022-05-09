#ifndef __E1617__
#define __E1617__

#define MAXc 4
typedef struct chunk {
    int vs [MAXc];
    struct chunk *prox;
} *CList;

typedef struct stackC {
    CList valores;
    int sp;
} StackC;

// Helpfull function
void initStackC(StackC *s, CList c);
void printStackC(StackC s);
CList newCList(CList rest);
void freeCList(CList c);

// Exam Questions
int push (StackC *s, int x);
int pop (StackC *s, int *x);
int size(StackC s);
void Libreverse (StackC *s);
void reverse (StackC *s);

#endif