#ifndef __LISTA_ARVORE_H__
#define __LISTA_ARVORE_H__

#include "arvores.h"

typedef struct elem {
  t_node *valor;
  struct elem *proximo;
} t_elem;

typedef struct lista {
  struct elem *inicio;
  struct elem *fim;
} t_lista;


t_lista* criaLista ();
t_elem* criaElemento (t_node *valor);
void insereFinal (t_node *valor, t_lista *lista);
t_elem* removeInicio (t_lista *lista);
int listaVazia (t_lista* lista);
void imprime (t_lista* lista);

#endif
