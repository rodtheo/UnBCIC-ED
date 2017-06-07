#include <stdlib.h>
#include <stdio.h>

typedef struct nodo {
  int dado;
  struct nodo* proximo;
  struct nodo* anterior;
} Nodo;

typedef struct lista {
  struct nodo* cabeca;
} Lista;

Lista* cria_lista();

int vazia_lista(Lista* cabeca);

void insere_lista(Lista* cabeca, int posicao, int personagem);

void remove_lista(Lista* cabeca, int posicao);

void free_lista(Lista* cabeca);

void imprime (Lista* lista);

void remove_lista (Lista* cabeca, int posicao);

Lista* cria_lista(){
  Lista* ptr_lista = (Lista*)malloc(sizeof(Lista));
  ptr_lista->cabeca = NULL;

  return ptr_lista;
}

int vazia_lista(Lista* cabeca){
  return (cabeca->cabeca == NULL);
}

void insere_lista(Lista* cabeca, int posicao, int personagem){
  Nodo* el = (Nodo*)malloc(sizeof(Nodo));
  Nodo* ptr = cabeca->cabeca;
  Nodo* ptr_ant;
  int i = 0;
  el->dado = personagem;

  if (vazia_lista(cabeca)) {
    cabeca->cabeca = el;
    el->anterior = NULL;
    el->proximo = NULL;
  }
  else {
    // loop ate a posicao i
    while ((ptr != NULL && i != posicao)) {
      i++;
      ptr_ant = ptr;
      ptr = ptr->proximo;
    } // end for
    if (ptr == NULL) {
      //printf ("Posicao %d invalida ou ultima pos! Adicionado ao final da lista (nova posicao %d)",
      //        posicao, i);

        ptr_ant->proximo = el;
        el->anterior = ptr_ant;
        el->proximo = NULL;
    }
    else if (i == posicao) {
      printf ("sera\n");
      if (posicao == 0) {
        cabeca->cabeca = el;
        el->anterior = NULL;
        el->proximo = ptr_ant;
      } else {
      ptr_ant -> proximo = el;
      el->anterior = ptr_ant;
      el->proximo = ptr;
    }
    }
  } // end else
} // end insere_lista()

void imprime (Lista* cabeca){
  Nodo *ptr;
  ptr = cabeca->cabeca;
  while (ptr != NULL){
    printf("%d -> ", ptr->dado);
    ptr = ptr -> proximo;
  }
  printf("NULL\n");
}

void remove_lista (Lista* cabeca, int posicao) {
  Nodo *ptr;
  ptr = cabeca->cabeca;
  int i=0;
  while (ptr != NULL && i != posicao) {
    i++;
    ptr = ptr->proximo;
  }
  if (ptr == NULL) {
    printf ("Posicao que deseja remover inexistente.");
  }
  else if (i == posicao) {
    free (ptr);
  }
}

void free_lista (Lista* cabeca) {
  Nodo *ptr;
  Nodo *ptr_primeiro;
  ptr = cabeca->cabeca;
  int i=0;
  if (!vazia_lista(cabeca)) {

    while (ptr != NULL) {
      ptr_primeiro = ptr->proximo;

      remove_lista (cabeca, i);

      i ++;
      ptr = ptr_primeiro;
    }

    free (cabeca);

  }
}

int main(void){
  Lista* lista;
  printf("aqui");
  lista = cria_lista();

  insere_lista (lista, 0, 0);
  insere_lista (lista, 1, 1);
  insere_lista (lista, 2, 2);
  insere_lista (lista, 1, 3);
  insere_lista (lista, 0, 10);
  insere_lista (lista, 4, 9);
  insere_lista (lista, 15, 13);
  imprime (lista);
  free_lista (lista);
  printf("\n===================\n");


   return 0;
}
