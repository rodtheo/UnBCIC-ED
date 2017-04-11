// Aluno: Rodrigo Theodoro Rocha
// Matricula: 15/0157967
// Projeto: trab1

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

p_nodo *getNodo(float coef, int expo);

l_polinomio *getPolinomio();

void inserir_nodo (l_polinomio *pol, float coef, int expo);

void imprime_polinomio (l_polinomio *pol, char n);

float calcula_polinomio (l_polinomio *pol, float x);

void inserir_nodo (l_polinomio *pol, float coef, int expo);

p_nodo *busca (l_polinomio *pol, int expo);

void liberaMemoria (l_polinomio *pol);

// Fim das assinaturas das funcoes

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

/**
 * Funcao retorna o polinomio
 * @return polinomio
 */
l_polinomio *getPolinomio(){
  l_polinomio *pol = (l_polinomio*)malloc(sizeof(l_polinomio));
  pol->primeiro = NULL;

  return pol;
}

/**
 * Libera a memoria alocada para o polinomio pol
 */
void liberaMemoria (l_polinomio *pol) {
    p_nodo *ptr;

    pol->primeiro;
    while (ptr != NULL) {
        free (ptr);
    }
    free (pol);
}

/**
 * Insere um nodo com coeficiente e expoente especificados
 * no polinomio pol
 */
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

/**
 * Esta funcao busca por um nodo com expoente expo no polinomio pol
 * Retorna o endereco do nodo, se encontrado, ou NULL caso contrario
 */
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

/**
 * Imprime o polinomio
 */
void imprime_polinomio (l_polinomio *pol, char n) {
    p_nodo *ptr;

    ptr = pol->primeiro;
      printf("%c(X) = ", n);
    while (ptr != NULL) {
      if (ptr->coeficiente < 0){
          if (ptr->expoente == 0){
            printf("-%.2f", fabs(ptr->coeficiente));
          } else {
        printf("-%.2f*X^%i", fabs(ptr->coeficiente), ptr->expoente);}
        } else {
           if (ptr->expoente == 0){
            printf("-%.2f", fabs(ptr->coeficiente));
          } else {
        printf("+%.2f*X^%i", fabs(ptr->coeficiente), ptr->expoente);}
        }
      ptr = ptr->proximo;
    }
    printf("\n\n");
}

/**
 * Calcula o valor do polinomio para x
 * Retorna um float com o resultado
 */
float calcula_polinomio (l_polinomio *pol, float x) {
    p_nodo *ptr;
    float res = 0;
    for (ptr=pol->primeiro; ptr != NULL; ptr=ptr->proximo) {
        res += (ptr->coeficiente)*pow(x, ptr->expoente);
    }
    return res;
}
