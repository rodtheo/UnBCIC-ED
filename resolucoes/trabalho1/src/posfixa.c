#include <stdlib.h>
#include <stdio.h>
#include "../include/pilha.h"

#define MAXDECIMAL 10

void check_infixa (t_pilha *pilha, char ** linha){
  char ch;
  char chout;
  int i;
  for (i = 0; i < NLINES-1; i ++) {
    int valido=1;
    int j=0;
    do {
      ch = linha[i][j];

      if (ch == '\n'){
      if (empty(pilha)){
        if(valido){
            printf("correct\n");
        } else {
          printf("incorrect\n");
        }
      } else {
        printf("incorrect\n");
      }

        pilha = get_pilha ();
        // printf("NOVA PILHA\n");
      }

      if (ch == '('){
        // printf("PUSH: %c\n", ch);
        push (pilha, ch);
      }

      if (ch == ')'){
        if (!(empty(pilha)))
          pop (pilha, &chout);
        else
          valido=0;
        // printf("POP: %c\n", chout);
      }
      j++;
    } while (ch != '\0');
  }
}

int is_digit (char c){
  return (c >= '0' && c <='9');
}

int is_point (char c){
  return (c == '.');
}

float avalia_posfixa (char *expr){
  t_pilha *stk = get_pilha();
  int posicao;
  char c;
  char string_number[MAXDECIMAL];
  // Varremos enquanto nao chegamos ao fim da expressao posfixa
  for (posicao = 0; (c= *(expr+posicao)) != '\0'){

    while (is_digit(c) || is_point(c)){

    }


  }

}
