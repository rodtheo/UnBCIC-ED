#include <stdlib.h>
#include <stdio.h>

typedef struct elemento {
  int valor;
  struct elemento *proximo;
} t_elem;

typedef struct lista {
  t_elem *inicio;
  t_elem *fim;
} t_lista;

t_elem *access_head (t_lista *lista);
t_elem *access_tail (t_lista *lista);
t_elem *access (t_lista *lista, int valor);
void remove_head (t_lista *lista);
void remove_tail (t_lista *lista);
void remove (t_lista *lista, int valor);
