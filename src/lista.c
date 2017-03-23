
#include <stdlib.h>

// BEGIN - HEADER

typedef struct elemento {
  int dado;
  struct elemento* proximo;
} t_elemento;

typedef struct lista_posicoes {
  t_elemento* inicio;
  t_elemento* fim;
} t_lista;

t_elemento* set_elemento (int valor);

t_lista* set_lista ();
// END - HEADER

// BEGIN - Functions

t_elemento* set_elemento (int valor){
  t_elemento* ptr = (t_elemento*)malloc(sizeof(t_elemento));

  ptr->dado = valor;
  ptr->proximo = NULL;

  return ptr;
} // end set_elemento()

t_lista* set_lista (){
  t_lista* ptrLista = (t_lista*)malloc(sizeof(t_lista));

  ptrLista->inicio = NULL;
  ptrLista->fim = NULL;

  return ptrLista;
}



// END - Functions

int main(){
  t_elemento* el;

  el = set_elemento (5);
  return 0;
}
