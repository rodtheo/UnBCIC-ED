#ifndef __ARVORES_H__
#define __ARVORES_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int info;
  struct node* esquerda;
  struct node* direita;
} t_node;

// Assinaturas das funções

t_node* criano(int valor);
void free_node();
void setleft (t_node *p, int x);
void setright (t_node *p, int x);
void em_ordem (t_node *raiz);
void pre_ordem (t_node *raiz);
void pos_ordem (t_node *raiz);
void em_largura (t_node *raiz);

#endif
