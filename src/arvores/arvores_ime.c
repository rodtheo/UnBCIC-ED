
#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
  int conteudo;
  struct reg* esq;
  struct reg* dir;
} noh;

typedef noh* arvore;

noh* cria_no (int dado) {
  noh* resultado = (noh*)malloc(sizeof(noh));

  resultado->conteudo = dado;
  resultado->esq = NULL;
  resultado->dir = NULL;

  return resultado;
}

noh* inserir (noh* raiz, int dado) {
  if (raiz == NULL){
    return cria_no (dado);
  }
  else {
      if (raiz->conteudo > dado)
        raiz->esq = inserir (raiz->esq, dado);
      else if (raiz->conteudo < dado)
        raiz->dir = inserir (raiz->dir, dado);
    }

  return raiz;
}

void em_ordem (arvore raiz) {
  if (raiz != NULL) {
    em_ordem (raiz->esq);
    printf ("%d\n",raiz->conteudo);
    em_ordem (raiz->dir);
  }
}

// Recebe a raiz r de uma árvore binária e
// imprime os conteúdos dos seus nós
// em ordem e-r-d.

void em_ordem_i (noh* raiz) {
  noh *x, *pilha[101];
  int t=0;
  pilha[t++] = raiz;
  while (1) {
    // pilha[0..t-1] é uma pilha de nós
    x = pilha[t-1];
    if (x != NULL)
      pilha[t++] = x->esq;
    else {
      if (t==0) break;
      x = pilha[--t];
      printf ("%d\n", x->conteudo);
      pilha[t++] = x->dir;
    }
  }
}

void count_nodes (noh* raiz, int *n) {
  if (raiz != NULL){
    count_nodes (raiz->esq, n);
    *n = *n + 1;
    count_nodes (raiz->dir, n);
  }
}

void busca_folha (noh* raiz) {
  if (raiz != NULL) {

    if (raiz->dir == NULL && raiz->esq == NULL){
    printf("%d\n", raiz->conteudo);
    return;}

    busca_folha (raiz->dir);
    busca_folha (raiz->esq);
  }
  // return busca_folha (raiz->dir);
}

void busca_conteudo (noh* raiz, int dado) {
  if (raiz != NULL) {

    if (raiz->conteudo == dado) {
      printf("Achado=%d\n", raiz->conteudo);
      return;
    }

    busca_conteudo (raiz->dir, dado);
    busca_conteudo (raiz->esq, dado);
}}

// Breadth-first search

void em_largura(t_no* raiz){
    t_fila* fila = getFila(20);
    t_no* no     = NULL;

    if(raiz == NULL)
        return;

    inserirFila(fila, raiz);

    while( !filaVazia(fila) ){
        no = removerFila(fila);

        printf("%d\n", no->dado);

        if(no->esq != NULL)
            inserirFila(fila, no->esq);

        if(no->dir != NULL)
            inserirFila(fila, no->dir);

    }//end while

    liberaFila(fila);

}//end em_largura


//-------------------------------------------
noh* busca_pai(noh* raiz, int dado){

    if( raiz == NULL || raiz->conteudo == dado )
        return NULL;

    if(raiz->conteudo > dado){

        if(raiz->esq != NULL && raiz->esq->conteudo == dado)
            return raiz;

        return busca_pai(raiz->esq, dado);

    }else if(raiz->conteudo < dado){

        if(raiz->dir != NULL && raiz->dir->conteudo == dado)
            return raiz;

        return busca_pai(raiz->dir, dado);
    }

}//end busca_pai()



// Devolve a altura da árvore binária
// cuja raiz é r.

int altura (arvore r) {
   if (r == NULL)
      return -1; // altura da árvore vazia
   else {
      int he = altura (r->esq);
      int hd = altura (r->dir);
      if (he < hd) return hd + 1;
      else return he + 1;
   }
}

int main (){
  noh* raiz = NULL;
  noh* ptr = NULL;

  raiz = inserir (raiz, 5);
  raiz = inserir (raiz, 3);
  raiz = inserir (raiz, 8);
  raiz = inserir (raiz, 1);
  raiz = inserir (raiz, 4);
  raiz = inserir (raiz, 6);
  raiz = inserir (raiz, 9);
  raiz = inserir (raiz, 0);
  raiz = inserir (raiz, 2);
  raiz = inserir (raiz, 7);

  em_ordem (raiz);
  int n=0;
  count_nodes (raiz, &n);
  printf ("=== O numero de nós na árvore: %d\n", n);

  busca_folha (raiz);

  busca_conteudo (raiz, 5);
  //printf("%d\n", ptr->conteudo);
}
