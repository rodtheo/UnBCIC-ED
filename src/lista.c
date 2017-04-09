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

/////////////////
// EXERCICIO 5 //
/////////////////

t_elemento* buscaPre (t_elemento *el, t_lista *lista);
void trocaPos (t_elemento *i, t_elemento *j, t_lista *lista);
void ordenar(t_lista *lista);
// void copiaLista (t_lista *lista, t_lista *nova_lista);
t_lista *copiaLista (t_lista *lista);

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

// void buscaConteudoMinimo (t_lista *lista){
//   t_elemento *ptr;
//
//   for(ptr = lista->inicio; ptr != NULL; ptr = ptr->proximo){
//
//   }
// }

// t_elemento* buscaCrescente (int valor, t_lista *lista);

//////////////////////////////
// Exercícios 5 - lista USP //
//////////////////////////////

void trocaPos (t_elemento *A, t_elemento *B, t_lista *lista){
  int profundidadeA, profundidadeB;
  t_elemento *ptrMenor, *prx, *ptr;

  // Verificamos a profundidade (similar ao index) dos elementos A e B
  profundidadeA = profundidade (A, lista);
  profundidadeB = profundidade (B, lista);

  // Se o elemento A vem antes do B
  // com isso quando os elementos sao iguais nada fazemos
  if (profundidadeA < profundidadeB){
    // ponteiro para percorrer a lista
    ptr = lista -> inicio;
    // ponteiro armazenando o endereço de A (menor indice)
    ptrMenor = A;
    // ponteiro com o end do elemento apontado por B
    // já que iremos modificar o endereço do B pelo A
    // devemos armazenar esta informação
    prx = B->proximo;

    // verificamos se o elemento A é cabeça da lista
    // se positivo apontamos o inicio para B
    // e setamos o ponteiro como NULL para ele não iniciar o while a seguir
    if (ptr == A){
      lista->inicio = B;
      ptr = NULL;
    }
    // se o elemento A não é cabeça da lista devemos procurar
    // qual elemento é anterior a ele
    while (ptr != NULL && ptr->proximo != A) {
      ptr = ptr->proximo;
    }
    // se o A não for cabeça da lista executamos esse condicional
    // que mudará o ponteiro do pré-elemento de A para o endereço de B
    if (ptr != NULL){
      ptr->proximo = B;
      // printf("ptr proximo not NULL %i\n\n", ptr->dado);
    }
    // Caso no qual o elemento B vem logo depois do elemento A
    // caso não lidassemos com este caso, ficariamos num loop eterno
    if (A->proximo == B) {
        B->proximo = A;
    }
    else {
      B->proximo = A->proximo;
    }

    // Até aqui já resolvemos a troca do B para o endereço de A
    // agora vamos prosseguir para trocar os endereços futuros que
    // apontarão para A

    // Como B vem depois de A, podemos percorrer a lista a partir de A
    // para encontrar o pre-elemento de B
    ptr = ptrMenor;

    while (ptr != NULL && ptr->proximo != B){
      ptr = ptr->proximo;
    }
    // O pre-elemento de B aponta para A
    ptr->proximo = A;
    // printf("ptr B->proximo old: %i\n\n", prx->dado);
    // O proximo elemento de A aponta para o proximo armazenado no
    // ponteiro prxB
    A->proximo = prx;

    // B é o fim da lista, isto é, aponta para NULL
    if (prx == NULL) {
      lista->fim = A;
    }
  }
  // Analogamente procedemos com o caso de A estar a frente de B na lista
  else {
    ptr = lista -> inicio;
    ptrMenor = B;
    prx = A->proximo;
    if (ptr == B){
      lista->inicio = A;
      ptr = NULL;
    }
    while (ptr != NULL && ptr->proximo != B) {
      ptr = ptr->proximo;
    }
    if (ptr != NULL){
      ptr->proximo = A;
    }
    if (B->proximo == A) {
        A->proximo = B;
    }
    else {
      A->proximo = B->proximo;
    }

    ptr = ptrMenor;

    while (ptr != NULL && ptr->proximo != A){
      ptr = ptr->proximo;
    }

    ptr->proximo = B;

    B->proximo = prx;

    if (prx == NULL) {
      lista->fim = B;
    }
  }
}

t_elemento* buscaPre (t_elemento *el, t_lista *lista){
  t_elemento* ptr;

  ptr = lista->inicio;
  // caso o pre-elemento a ser pesquisado seja o primeiro da lista
  if (ptr == el){
    return 0;
  }
  while ((ptr != NULL) && (ptr->proximo != el)){
    ptr = ptr->proximo;
  }
  return ptr;
}

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

void ordenar(t_lista *lista){
  t_lista *cplista = copiaLista (lista);
  t_elemento *ptri, *ptrj, *prx, *ptrMin;
  ptri = cplista->inicio;
  while ((ptri != NULL) && (!isOrdemCrescente (lista))){
    // printf("elemento Comparado prx: %i\n", prx->dado);
    ptrMin= ptri;

    for (ptrj = busca(ptri->proximo->dado, lista); ptrj != NULL; ptrj=ptrj->proximo){
      if (ptrj->dado < ptrMin->dado){
        ptrMin = ptrj;
      }
    }
    if (ptrMin != ptri){
      trocaPos (busca(ptrMin->dado, lista), busca(ptri->dado, lista), lista);
    }
    ptri=ptri->proximo;
  }
}

t_lista *copiaLista (t_lista *lista){
  t_lista *nova_lista = get_lista();
  t_elemento *ptr;

  ptr = lista->inicio;
  while(ptr != NULL){
    // printf("ptr: %i\n", ptr->dado);
    inserirFim (ptr->dado, nova_lista);
    ptr = ptr->proximo;
  }
  return nova_lista;
}



// END - Functions

int main(void){
  t_lista* lista;

  lista = get_lista();

  inserirInicio (5, lista);
  inserirInicio (4, lista);
  inserirInicio (3, lista);
  inserirInicio (2, lista);
  inserirInicio (1, lista);
  imprime (lista);
  printf("\n===================\n");
  printf("Add 6 no fim da lista: \n");
  inserirFim (6, lista);
  inserirFim (7, lista);
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

  printf("\n===================\n");
  // t_elemento *eli, *elj;
  //
  // eli = buscaPre (busca(4, lista), lista);
  // elj = buscaPre (busca(5, lista), lista);
  //
  // printf("%i, %i", eli->dado, elj->dado);
  printf("Mudar elementos 1 e 6 de posição.\n");
  t_elemento *eli, *elj;
  eli = busca(1, lista);
  elj = busca(6, lista);
  trocaPos (eli, elj, lista);
  imprimeInterativa (lista);

  printf("\n===================\n");
  printf("Mudar elementos 2 e 3 de posição.\n");
  eli = busca(2, lista);
  elj = busca(3, lista);
  trocaPos (eli, elj, lista);
  imprimeInterativa (lista);

  printf("\n===================\n");
  printf("Mudar elementos 5 e 4 de posição.\n");
  eli = busca(5, lista);
  elj = busca(4, lista);
  trocaPos (eli, elj, lista);
  imprimeInterativa (lista);

  printf("\n===================\n");
  ordenar (lista);
  imprimeInterativa (lista);
  printf("\n===================\n");
  // // t_lista *cplista = get_lista();
  // t_lista *cplista;
  //
  // cplista = copiaLista(lista);
  // imprimeInterativa(cplista);

   return EXIT_SUCCESS;
}
