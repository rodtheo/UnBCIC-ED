#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void free_pilha (t_pilha *pilha){
  free (pilha);
}

t_pilha* get_pilha (){
  t_pilha *pilha;
  pilha = (t_pilha *)malloc(sizeof(t_pilha));
  pilha->p=-1;

  return pilha;
}

void top (t_pilha *pilha) {
  printf("top: %d\n", pilha->p);
}

int push (t_pilha *pilha, char valor) {
  if (pilha->p < STACKSIZE-1){
    pilha->p++;
    pilha->stack[pilha->p] = valor;
    return 1;}
  else{
    return -1;
  }
}

int pop (t_pilha *pilha, char *el) {
  if (empty(pilha)){
    return -1;
  }
  else{
    *el = pilha->stack[pilha->p];
    pilha->p--;
    return 1;
  }
}

int empty (t_pilha *pilha) {
  if (pilha->p == -1)
    return 1;
  else
    return 0;
}

void checkValidity (t_pilha *pilha, char ** linha){
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
