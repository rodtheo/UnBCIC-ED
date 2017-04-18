#include <stdio.h>
#include <stdlib.h>

// Suponha que nossa fila mora no vetor fila[0..N-1]
// Diz-se que parte do vetor ocupada pela fila é fila[p..u-1]
// o primeiro elemento está na posição p e o último na posição u-1

// Para tirar ou remover um elemento x = fila[p++] (equivale a x=fila[p]; p=p+1;)

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

void colocanafila(t_fila *fila, int valor) {
  if (!filacheia(fila)){
    fila->item[fila->fim] = valor;
    fila->fim ++;
  }
  else {
    printf("Overflow!\n");
  }
}

int filacheia (t_fila *fila){
  if (fila->fim >= fila->tamanho)
    return 1;
  else
    return 0;
}

int filavazia (t_fila *fila){
  if (fila->inicio == fila->fim)
    return 1;
  else
    return 0;
}

int tiradafila (t_fila *fila){
  int x;
  if (!filavazia(fila)){
    x = fila->item[fila->inicio];
    fila->inicio ++;
    return x;
    } else {
    printf("Fila vazia!\n");
    return -1;
  }
}

void liberafila (t_fila *fila){
  free(fila->item);
  free(fila);
}

int  main(){
    t_fila* fila = criafila(10);

    printf("Fila vazia %d\n", filavazia(fila));
    for(int i = 0; i < 15; i++)
        colocanafila(fila, i);

    printf("\n\nRemovendo da lista:\n");

    for(int i = 0; i < 10; i++)
        printf("%d \n", tiradafila(fila));

    liberafila(fila);
}
