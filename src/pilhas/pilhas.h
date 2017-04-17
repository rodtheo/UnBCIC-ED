#ifndef __PILHAS_H__
#define __PILHAS_H__

#define STACKSIZE 100
#define INTGR 1
#define FLT 2
#define CHR 3
#define TRUE 1
#define FALSE 0

struct stackelement {
  int etype;
  union {
    int ival;
    float fval;
    char cval;
  } element;
};

struct stack {
  int top;
  struct stackelement items[STACKSIZE];
};


/////////////////////////////////////////
// Inicio das assinaturas das funções  //
/////////////////////////////////////////

int initia (struct stack *);
int empty (struct stack *);
int pop (struct stack *, struct stackelement *);
int push (struct stack *, int x);
int print_stack (struct stack *);
void print_elem (struct stackelement *);

/////////////////////////////////////
// Fim das assinaturas das funções //
/////////////////////////////////////
#endif
