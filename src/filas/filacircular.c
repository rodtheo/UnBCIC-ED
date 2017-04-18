#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
  int *item;
  int tamanho;
  int inicio, fim;
} t_fila;

t_fila* criafila(int tamanho);
void colocanafila(t_fila *fila, int valor);
int tiradafila(t_fila *fila);
int filavazia(t_fila *fila);
int filacheia(t_fila *fila);
void liberafila (t_fila *fila);

t_fila* criafila(int tamanho){
  t_fila *fila = (t_fila *)malloc(sizeof(t_fila));
  fila->item = malloc(tamanho*sizeof(int));
  fila->inicio = 0;
  fila->fim = 0;
  fila->tamanho = tamanho;
  return fila;
}

int tiradafila(t_fila *fila) {
  int x = fila->item[fila->inicio];
  fila->inicio++;
  if (fila->inicio == fila->tamanho)
    fila->inicio = 0;
  return x;
}

void colocanafila(t_fila *fila, int valor){
  fila->item[fila->fim]
}
