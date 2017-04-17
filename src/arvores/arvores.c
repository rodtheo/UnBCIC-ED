#include <stdio.h>
#include <stdlib.h>
#include "../pilhas.h"

typedef struct node {
  int info;
  struct node* esquerda;
  struct node* direita;
} t_node;

// Assinaturas das funções

t_node* get_node();
void free_node();
void setleft (t_node *p, int x);
void setright (t_node *p, int x);
t_node* maketree(int valor);


// Implementacao
t_node* get_node(){
  t_node* node = (t_node*) malloc(sizeof(t_node));
  return node;
}

t_node* maketree(int valor){
  t_node* node = get_node();

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
    p->esquerda = maketree(x);
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
    p->direita = maketree(x);
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

// Recebe a raiz r de uma árvore binária e
// imprime os conteúdos dos seus nós
// em ordem e-r-d.
void erd_i (arvore r) {
   criapilha ();  // pilha de nós
   empilha (r);
   while (1) {
      x = desempilha ();
      if (x != NULL) {
         empilha (x);
         empilha (x->esq);
      }
      else {
         if (pilhavazia ()) break;
         x = desempilha ();
         printf ("%d\n", x->conteudo);
         empilha (x->dir);
      }
   }
   liberapilha ();
}

int main(){
  t_node *arvore, *p, *q;
  int number;

  scanf("%d", &number);
  arvore = maketree(number);

  while (number != -1){
    scanf("%d", &number);
    // p e q serao utilizados no percurso da árvore. p aponta
    // para um nó pai e q aponta seu filho direito ou esquerdo
    p = q = arvore;
    // a árvore é percorrida até encontrar a primeira ocorrência
    // do número anteriormente digitado ou encontrar um ponteiro
    // esquero ou direito NULL
    while ((p->info != number) && (q != NULL)){
      p = q;
      if (number < p->info)
        q = p->esquerda;
      else
        q = p->direita;
    }
    // se o laço foi interrompido devido a (number == p->info), deve
    // indicar que o número já ocorreu antes
    if (number == p->info)
      printf ("%d já ocorreu.\n Digite:\n", number);
    // Se o laço foi interrompido devido a q == NULL, a árvore foi
    // toda percorrida e o número não foi encontrado. Nesse caso,
    // deve ser incluído como filho direito ou esquero de p
    else if (number < p->info){
      setleft (p, number);
    }
    else {
      setright (p, number);
    }
  }
  // setleft(arvore, 4);
  // setright(arvore, 6);
  printf("-----------------------------------------------------------");
  em_ordem (arvore);

  return 0;
}
