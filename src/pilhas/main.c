#include "pilhas.h"


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

  push (sptr, 10);
  pop (sptr, septr);
  print_elem (septr);

  return 0;
}
