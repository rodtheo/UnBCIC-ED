#include <stdio.h>
#include <stdlib.h>
#include "arvores.h"
#include "lista_arvore.h"

t_node* criano(int valor){
  t_node* node = (t_node*) malloc(sizeof(t_node));

  node->esquerda=NULL;
  node->direita=NULL;
  node->info=valor;

  return node;
}

void free_node (t_node *node){
  free (node);
}

void setleft (t_node *p, int x){
  if (p == NULL){
    printf("Insercao vazia\n");}
  else if (p->esquerda != NULL) {
    printf("Insercao incorreta, no na esquerda preenchido\n");}
  else {
    p->esquerda = criano(x);
  }
}

void setright (t_node *p, int x){
  if (p==NULL){
    printf("Insercao vazia, p nulo\n");
  }
  else if (p->direita != NULL){
    printf("Insercao incorreta, no da direita preenchido\n");
  }
  else {
    p->direita = criano(x);
  }
}

// Percorre a árvore binári em ordem, isto é, subárvore esquerda-raiz-direita
void em_ordem (t_node *raiz) {
  if (raiz != NULL) {
    em_ordem (raiz->esquerda);
    printf("%d\n", raiz->info);
    em_ordem (raiz->direita);
  }
}

void pre_ordem (t_node *raiz) {
  if (raiz != NULL) {
    printf("%d\n", raiz->info);
    pre_ordem (raiz->esquerda);
    pre_ordem (raiz->direita);
  }
}

void pos_ordem (t_node *raiz) {
  if (raiz != NULL) {
    pos_ordem (raiz->esquerda);
    pos_ordem (raiz->direita);
    printf("%d\n", raiz->info);
  }
}

void em_largura (t_node *raiz) {
  t_lista *lista;
  t_elem *el;
  lista = criaLista ();
  insereFinal (raiz, lista);
  while (!listaVazia(lista)) {
    el = removeInicio (lista);
    printf("%d", el->valor->info);
    if (el->valor->esquerda != NULL)
      insereFinal (el->valor->esquerda, lista);
    if (el->valor->direita != NULL)
      insereFinal (el->valor->direita, lista);
  }
}
