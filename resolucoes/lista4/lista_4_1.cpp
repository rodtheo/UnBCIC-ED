#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100

typedef struct pilha {
  char stack[STACKSIZE];
  int p;
} t_pilha;

t_pilha* get_pilha ();
void top (t_pilha *pilha);
int push (t_pilha *pilha, int valor);
int pop (t_pilha *pilha, int *el);
int empty (t_pilha *pilha);

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

int main(){
  t_pilha *pilha = get_pilha();
  char e;

  printf("Pilha vazia? %d\n", empty(pilha));

  push (pilha, 'a');
  push (pilha, 'b');
  push (pilha,'c');

  top(pilha);
  pop (pilha, &e);
  printf("Elemento poped: %c\n", e);
  top(pilha);

  pop (pilha, &e);
  printf("Elemento poped: %c\n", e);
  top(pilha);

  return 0;
}
