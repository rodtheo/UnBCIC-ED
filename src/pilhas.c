#include <stdio.h>

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


/////////////////////////////////////
// Inicio da definição das funções //
/////////////////////////////////////

int initia (struct stack *ps){
  ps->top = -1;
  return 1;
}

int empty(struct stack *ps){
  if (ps->top == -1){
    // Pilha vazia
    return TRUE;
  else
    // Pilha não vazia
    return FALSE;
} // end funcao empty

int pop (struct stack *ps, struct stackelement *el){
  if (empty(ps)){
    printf("Pilha vazia");
    // Underflow
    return 0;
  } else {

    *el = ps->items[ps->top];
    (ps->top)--;
    return 1;
  }
}

int push (struct stack *ps, int x){
  if (ps->top < STACKSIZE-1){
    (ps->top)++;
    ps->items[ps->top].etype = INTGR;
    ps->items[ps->top].element.ival = x;
    return 1;
  } else {
    return 0; // OVERFLOW
  }
}

void print_elem (struct stackelement *se){
  switch (se->etype){
    case FLT:
      printf("%f\n", se->element.fval);
      break;
    case CHR:
      printf("%c\n", se->element.cval);
      break;
    case INTGR:
      printf("%d\n", se->element.ival);
      break;
    default:
      printf("Tipo desconhecido.\n");
  }
};

int print_stack (struct stack *ps){
  int i;

  if (ps->top >= 0){
    printf ("\n");
    printf("-----------------------------\n");
    printf("| var | cont  | end |\n");
    printf("-----------------------------\n");
    for (i=(ps->top); i>=0; i--){
      printf("v[%d] %x ", i, &(ps->items[i].element));
      print_elem (&ps->items[i].element);
      if (i==0) printf("<--- base (inicio)");
      if (i==pos->top) printf("<--- topo (fim)");
      printf ("\n");
    }
  } else {
    printf ("\nA pilha estah vazia!!\n");
  }
  printf("\n");
  return 0;
}

int main(){
  // Ponteiro para a pilha sptr e pilha s
  struct stack *sptr, s;
  // Ponteiro para elemento septr e elemento se
  struct stackelement *septr, se;

  // Exemplo usando ponteiros para as structs
  sptr->top = 0;
  sptr->items[sptr->top].element.fval = 3.5;
  septr = &sptr->items[sptr->top];
  septr->etype = FLT;

  print_elem (septr);

  // Exemplo usando as structs brutas
  s.items[s.top].element.ival = 21;
  se = s.items[s.top];
  se.etype = INTGR;

  print_elem (&se);

  // Exemplo usando as structs brutas
  s.items[s.top].element.cval = 'a';
  se = s.items[s.top];
  se.etype = CHR;

  print_elem (&se);

  return 0;
}
