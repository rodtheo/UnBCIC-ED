#include <stdio.h>
#include <stdlib.h>

void insertion_sort (int *A, int tamanho){
  int i, j, elemento;

  for (j=1; j<=tamanho-1; j++){
    // elemento <- A[j]
    elemento = *(A+j);
    // buscamos por numeros menores que elemento voltando na lista
    i = j-1;
    while ((i >= 0) && (A[i] > elemento)){
      A[i+1] = A[i];
      A[i] = elemento;

    }
  }
}
