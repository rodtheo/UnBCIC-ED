#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/pilha.h"
#include "../include/calculadora.h"

void apply_operacao (t_pilha *stk, char c){
  t_elementPilha opnd2, opnd1;
  float fopnd2, fopnd1;
  float result;
  if ( top(stk) >= 1 ) { /* pilha deve conter no minimo 2 elementos */
    pop (stk, &opnd2);
    pop (stk, &opnd1);

    fopnd2 = opnd2.element.fval;
    fopnd1 = opnd1.element.fval;

    result = apply_operador (fopnd1, fopnd2, c);

    push_float (stk, result);

  } else {
    printf ("Número de operandos insuficiente!\n");
  }
} // end func apply_operacao

int apply_operador (float fopnd1, float fopnd2, char c){
  float result;

  if ( c == '+' )
    result = fopnd1 + fopnd2;
  else if ( c == '-' )
    result = fopnd1 - fopnd2;
  else if ( c == '*' )
    result = fopnd1 * fopnd2;
  else if ( c == '/' )
    result = fopnd1 / fopnd2;

  return result;
}

void apply_copia_el (t_pilha *stk) {
  float number;
  float times;
  int i;
  t_elementPilha out;
  pop (stk, &out);
  times = out.element.fval;
  pop (stk, &out);
  number = out.element.fval;

  printf("O número %.2f foi repetido %d vezes\n", number, (int)times);
  for (i=0; i<(int)times; i++)
    push_float (stk, number);
} // end func apply_copia_el

void apply_repeticao (t_pilha *stk, char c){
  t_elementPilha opnd2, opnd1;
  float fopnd2, fopnd1, resultado;
  while ( top(stk) > 0 ){
    pop (stk, &opnd2);
    fopnd2 = opnd2.element.fval;

    pop (stk, &opnd1);
    fopnd1 = opnd1.element.fval;

    resultado = apply_operador (fopnd1, fopnd2, c);

    push_float (stk, resultado);
  }
} // end function apply_repeticao
