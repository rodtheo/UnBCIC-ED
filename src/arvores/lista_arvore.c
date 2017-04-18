#include <stdio.h>
#include <stdlib.h>
#include "lista_arvore.h"


t_lista* criaLista (){
  t_lista* lista = (t_lista *)malloc(sizeof(t_lista));

  lista->inicio = NULL;
  lista->fim = NULL;

  return lista;
}

t_elem* criaElemento (t_node *valor){
  t_elem* el = (t_elem *)malloc(sizeof(t_elem));

  el->valor = valor;
  el->proximo = NULL;

  return el;
}

int listaVazia (t_lista* lista){
  return (lista->inicio == NULL);
}

void insereFinal (t_node *valor, t_lista *lista){
  t_elem *el = criaElemento (valor);
  if(listaVazia(lista)){
    lista->inicio = el;
  } else {
  lista->fim->proximo = el;}
  lista->fim = el;
}

t_elem* removeInicio (t_lista *lista) {
  t_elem *el;
  if(!listaVazia(lista)){
    el = lista->inicio;
    lista->inicio = lista->inicio->proximo;
  } else {
    printf("Lista vazia!\n\n");
  }
}

void imprime (t_lista* lista){
  t_elem *ptr;
  ptr = lista->inicio;
  while (ptr != NULL){
    printf("%d -> ", ptr->valor->info);
    ptr = ptr -> proximo;
  }
  printf("NULL\n");
}
