#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int print_stack (t_pilha *ps){
  int i;
  if (ps->p >= 0){
    printf ("\n");
    printf("-----------------------------\n");
    printf("Modo Calculadora\n");
    printf("Digite 'o' para exibir as opcções da calculadora\n");
    printf("-----------------------------\n");
    // printf("%d\n", (ps->top));
    for (i=(ps->p); i>=0; i--){
      // printf("v[%d] %x ", i, &(ps->items[i].element));
      printf("%d. ", i+1);
      print_elem (&(ps->stack[i]));
      // if (i==0) printf("<--- base (inicio)");
      // if (i==ps->top) printf("<--- topo (fim)");
      // printf ("\n");
    }
  } else {
    printf ("\nA pilha esta vazia!!\n");
  }
  printf("\n");
  return 0;
}

// #define TINT    2
// #define TCHAR   3
// #define TFLOAT  4

void print_elem (t_elementPilha *se){
  switch (se->etype){
    case TFLOAT:
      printf("%.2f\n", se->element.fval);
      break;
    case TCHAR:
      printf("%c\n", *(se->element.cval));
      break;
    case TINT:
      printf("%d\n", se->element.ival);
      break;
    default:
      printf("Tipo desconhecido.\n");
  }
};

void free_pilha (t_pilha *pilha){
  free (pilha);
}

t_pilha* get_pilha (){
  t_pilha *pilha;
  pilha = (t_pilha *)malloc(sizeof(t_pilha));
  pilha->p=-1;

  return pilha;
}

int top (t_pilha *pilha) {
  return (pilha->p);
}

// int push_char (t_pilha *pilha, char valor) {
//   if (pilha->p < STACKSIZE-1){
//     pilha->p++;
//     pilha->stack[pilha->p] = valor;
//     return 1;}
//   else{
//     return -1;
//   }
// }

// switch (typeEl) {
//   case TINT:
//     pilha->stack[pilha->p].element.tval = valor;
//     break;
//   case TCHAR:
//     pilha->stack[pilha->p].element.tchar = valor;
//     break;
//   case TFLOAT:
//     pilha->stack[pilha->p].element.fval = valor;
//     break;
//   default:
//     printf("Tipo do elemento desconhecido !\n");
// }

int push_float (t_pilha *pilha, float valor) {
  if (pilha->p < STACKSIZE-1) {
    (pilha->p)++;
    pilha->stack[pilha->p].etype = TFLOAT;
    pilha->stack[pilha->p].element.fval = valor;
    return 1;
  } else {
    return 0;} // overflow
} //end push_float()

int push_int (t_pilha *pilha, int valor) {
  if (pilha->p < STACKSIZE-1) {
    (pilha->p)++;
    pilha->stack[pilha->p].etype = TINT;
    pilha->stack[pilha->p].element.ival = valor;
    return 1;
  } else {
    return 0;} // overflow
} //end push_int()

int push_char (t_pilha *pilha, char *pvalor) {
  if (pilha->p < STACKSIZE-1) {
    (pilha->p)++;
    pilha->stack[pilha->p].etype = TCHAR;
    pilha->stack[pilha->p].element.cval = pvalor;
    return 1;
  } else {
    return 0;} // overflow
} //end push_char()

int pop (t_pilha *pilha, t_elementPilha *el) {
  if (empty(pilha)){
    printf("ERRO! UNDERFLOW!\n");
    return 0;
  }
  else{
    *el = pilha->stack[pilha->p];
    (pilha->p)--;
    return 1;
  }
}

int empty (t_pilha *pilha) {
  if (pilha->p == -1)
    return 1;
  else
    return 0;
}
