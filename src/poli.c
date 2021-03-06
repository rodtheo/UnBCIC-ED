#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct nodo{
  float coeficiente;
  int expoente;
  struct nodo *proximo;
} p_nodo;

typedef struct polinomio{
  p_nodo *primeiro;
} l_polinomio;

// Assinaturas das funcoes

/**
 * Funcao retorna um nodo do polinomio inicializado
 * com zero e ponteiro NULL
 * @return nodo
 */
p_nodo *getNodo(float coef, int expo);

l_polinomio *getPolinomio();

void inserir_nodo (l_polinomio *pol, float coef, int expo);

void imprime_polinomio (l_polinomio *pol, char n);

void calcula_polinomio (l_polinomio *pol, float x);

void inserir_nodo (l_polinomio *pol, float coef, int expo);

p_nodo *busca (l_polinomio *pol, int expo);


/**
 * Funcao retorna um nodo do polinomio inicializado
 * com zero e ponteiro NULL
 * @return nodo
 */
p_nodo *getNodo(float coef, int expo) {
  p_nodo *nodo = (p_nodo*)malloc(sizeof(p_nodo));

  nodo->coeficiente = coef;
  nodo->expoente = expo;
  nodo->proximo = NULL;

  return nodo;
}

l_polinomio *getPolinomio(){
  l_polinomio *pol = (l_polinomio*)malloc(sizeof(l_polinomio));
  printf("criou");
  pol->primeiro = NULL;

  return pol;
}

void inserir_nodo (l_polinomio *pol, float coef, int expo){
  p_nodo *nodo = getNodo(coef, expo);
  p_nodo *ptr;

  // If the poli is empty then poli pointer to nodo
  if (pol->primeiro == NULL) {
    printf("not null");
    pol->primeiro = nodo;
    }
  else { // If not add nodo in the begin of poli
    // we pointer the next of nodo to the old first-nodo in poli
    // so the old first-nodo becomes the second element of the poli
    // and the inserted nodo the first element (pointing the poli structure to it)
    ptr = busca(pol, expo);
    // printf("ptr: %i", ptr->expoente);
    if ( ptr != NULL) {
      ptr->coeficiente = ptr->coeficiente + coef;
    } else {
      nodo->proximo = pol->primeiro;
      pol->primeiro = nodo;}
  }
}

p_nodo *busca (l_polinomio *pol, int expo){
    p_nodo *ptr;
    ptr = pol->primeiro;
    if (ptr != NULL){
      printf("expoente: %i", ptr->expoente);}
    else {
      printf("expoente: NULL");
    }
    while ((ptr != NULL) && (ptr->expoente != expo)){
      ptr = ptr->proximo;
    }
    return ptr;
  }

void imprime_polinomio (l_polinomio *pol, char n) {
    p_nodo *ptr;

    ptr = pol->primeiro;
      printf("p(X) = ");
    while (ptr != NULL) {
      if (ptr->coeficiente < 0){
        printf("-%.2f*X^%i", fabs(ptr->coeficiente), ptr->expoente);
      } else {
        printf("+%.2f*X^%i", fabs(ptr->coeficiente), ptr->expoente);
      }
      ptr = ptr->proximo;
    }
    printf("\n\n");
}



int main(){
  l_polinomio *polinomio;
  polinomio = getPolinomio();
  float s;
  inserir_nodo (polinomio, 10, 2);
  inserir_nodo (polinomio, 6, 1);
  inserir_nodo (polinomio, -1, 0);
  inserir_nodo (polinomio, -2, 2);

  imprime_polinomio (polinomio, 'p');
  // s = calcula_polinomio (polinomio, 4);
  // printf("Polinomio calculado: %.2f \n", s);
  return 0;
}
