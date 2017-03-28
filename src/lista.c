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

void inserirInicio (int valor, t_lista* lista);
void inserirFim (int valor, t_lista* lista);
void inserirPos (int pos, int valor, t_lista* lista);

bool listaVazia (t_lista* lista);
// END - HEADER

// BEGIN - Functions

void inserirInicio (int valor, t_lista* lista) {
  t_elemento* el = set_elemento(valor);

  if listaVazia(lista) {
    lista->inicio = el;
    lista->fim    = el;
  }
  else {
    el->proximo = lista->inicio;
    lista->inicio = el;
  }
}

void inserirFim (int valor, t_lista* lista){
  t_elemento* el = set_elemento(valor);


}

bool listaVazia (t_lista* lista){
  return ((lista->inicio == NULL) && (lista->fim == NULL))
}

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
