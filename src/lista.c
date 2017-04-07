#include <stdlib.h>
#include <stdio.h>
// BEGIN - HEADER

typedef struct elemento {
  int dado;
  struct elemento* proximo;
} t_elemento;

typedef struct lista_posicoes {
  t_elemento* inicio;
  t_elemento* fim;
} t_lista;

t_elemento* get_elemento (int valor);

t_lista* get_lista ();

void inserirInicio (int valor, t_lista* lista);
void inserirFim (int valor, t_lista* lista);
void inserirPos (int pos, int valor, t_lista* lista);

int listaVazia (t_lista* lista);
void imprime (t_lista* lista);
void imprimeElemento (t_elemento* elemento);
void imprimeInterativa (t_lista* lista);

//////////////////
// Exercicios 2 //
//////////////////

int tamanho (t_lista* lista);
int altura (t_elemento* c, t_lista lista);
int profundidade (t_elemento* c, t_lista *lista);

/////////////////
// EXERCICIO 3 //
/////////////////

t_elemento* busca (int valor, t_lista *lista);
t_elemento* buscaR (int valor, t_elemento *el);
int isOrdemCrescente (t_lista *lista);
t_elemento* buscaCrescente (int valor, t_lista *lista);


// TO-IMPLEMENT
void buscaConteudoMinimo (t_lista *lista);
void listasIguais (t_lista *lista1, t_lista *lista2);


// END - HEADER

///////////////////////
// BEGIN - Functions //
///////////////////////



//////////////////
// Exercicios 2 //
//////////////////

/**
 * A altura de um elemento c em uma lista encadeada é a distância
 * entre c e o fim da lista.
 * @param  c     elemento
 * @param  lista struct da lista encadeada
 * @return       altura do elemento c na lista
 */
int altura (t_elemento* c, t_lista lista){
  int alt=0;
  while (c != NULL){
    alt ++;
    c = c->proximo;
  }
  return alt;
}

/**
 * A profundidade de um elemento (célula) c em uma lista
 * encadeada é o número de passos que vai do primeiro elemento
 * até o elemento c
 *
 * @param  c     elemento (célula)
 * @param  lista lista encadeada
 * @return       profundidade do elemento c
 */
int profundidade (t_elemento* c, t_lista* lista){
  t_elemento* ptr;
  int prof = 0;

  ptr = lista -> inicio;
  while (ptr != c){
    prof ++;
    ptr = ptr -> proximo;
  }
  return prof;
}

/**
 * Calcula o número de elementos na lista.
 * @param  lista ponteiro para a struct lista.
 * @return       O tamanho da lista.
 */

int tamanho (t_lista* lista){
  t_elemento *ptr;
  int contador = 0;
  for (ptr = lista->inicio; ptr != NULL; ptr = ptr->proximo){
      contador++;
  }
  return contador;
}


void imprime (t_lista* lista){
  t_elemento *ptr;
  ptr = lista->inicio;
  while (ptr != NULL){
    printf("%d -> ", ptr->dado);
    ptr = ptr -> proximo;
  }
  printf("NULL\n");
}

void imprimeInterativa (t_lista* lista){
  imprimeElemento (lista->inicio);
  printf("NULL\n");
}

void imprimeElemento (t_elemento* le){
  if (le != NULL){
    printf ("%d -> ", le->dado);
    imprimeElemento (le->proximo);
  }
}

/**
 * Insere uma célula no inicio da lista
 * @param valor conteúdo da célula
 * @param lista ponteiro da lista
 */
void inserirInicio (int valor, t_lista* lista) {
  t_elemento* el = get_elemento(valor);

  if (listaVazia(lista)) {
    lista->inicio = el;
    lista->fim    = el;
  }
  else {
    el->proximo = lista->inicio;
    lista->inicio = el;
  }
}

//////////////////////////////
// Exercícios 3 - lista USP //
//////////////////////////////


/**
 * Buscar uma célula com conteúdo igual a valor
 * @param  valor Inteiro para buscar uma célula com este valor
 * @param  lista Ponteiro da lista
 * @return       Se busca for sucesso retorna a célula com conteúdo igual ao valor e NULL caso contrário
 */
t_elemento* busca (int valor, t_lista *lista){
  t_elemento* ptr;
  ptr = lista->inicio;
  while (ptr != NULL && ptr->dado != valor){
    ptr = ptr->proximo;
  }
  return ptr;
}

// EX 3.3 - Verificar se lista esta em ORDEM CRESCENTE

int isOrdemCrescente (t_lista *lista) {
  t_elemento *ptr;
  int ordem=1;
  ptr = lista->inicio;
  while ((ptr != NULL) && (ptr->proximo != NULL)){
    if (ptr->dado > ptr->proximo->dado){
      ordem=0;
      return ordem;
    }
    else {
      ptr = ptr->proximo;
    }
  }
  return ordem;
}

// t_elemento* buscaCrescente (int valor, t_lista *lista);

void inserirFim (int valor, t_lista* lista){
  t_elemento* el = get_elemento(valor);
  t_elemento* lastOne;
  if(listaVazia(lista)) {
    lista->inicio = el;
  }
  else {
    lista->fim->proximo = el;
  }
  lista->fim = el;
}

int listaVazia (t_lista* lista){
  return (lista->inicio == NULL);
}

t_elemento* get_elemento (int valor){
  t_elemento* ptr = (t_elemento*)malloc(sizeof(t_elemento));

  ptr->dado = valor;
  ptr->proximo = NULL;

  return ptr;
} // end set_elemento()

t_lista* get_lista (){
  t_lista* ptrLista = (t_lista*)malloc(sizeof(t_lista));

  ptrLista->inicio = NULL;
  ptrLista->fim = NULL;

  return ptrLista;
}




// END - Functions

int main(void){
  t_lista* lista;

  lista = get_lista();

  inserirInicio (5, lista);
  inserirInicio (4, lista);
  inserirInicio (3, lista);
  imprime (lista);
  printf("\n===================\n");
  printf("Add 6 no fim da lista: \n");
  inserirFim (6, lista);
  imprimeInterativa (lista);
  printf("\n===================\n");
  printf ("Tamanho da lista = %d\n", tamanho (lista));

  printf ("sizeof (celula) = %d\n", sizeof (t_elemento));
  // Porque o tamanho da struct eh 16 bytes se int tem 4 bytes
  // e ponteiro para t_elemento tem 8 bytes?

  printf("\n===================\n");
  t_elemento* queryElement;
  int query = 10;
  queryElement = busca (query, lista);
  if (queryElement != NULL){
  printf("Conteúdo buscado %i, conteúdo encontrado %i,\n", query, (int) queryElement->dado);}
  else {
    printf("Conteúdo buscado %i, conteúdo encontrado NULL.\n", query);
  }

  printf("\n===================\n");
  int ordem;
  ordem = isOrdemCrescente (lista);
  printf("Esta na ordem? %i", ordem);


   return EXIT_SUCCESS;
}
