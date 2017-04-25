#include <stdlib.h>
#include <stdio.h>

void printMatriz(int **M);

void printMatriz(int **M, int NLINS, int NCOLS){
  for (int i=0; i<NLINS; i++){
    for(int j=0; j<NCOLS; j++){
      printf("%d ", M[i][j]);
    }
    printf("\n");
  }
}

int main(){
  int NCOLS, NLINS;
  int **M;

  printf("Digite o num de linhas da matriz a ser formada: ");
  scanf("%d", &NLINS);

  printf("Digite o num de colunas da matriz a ser formada: ");
  scanf("%d", &NCOLS);

  M = (int **)malloc(NLINS*sizeof(int *));

  for (int i=0; i<NLINS; i++){
    *(M+i) = (int *)malloc(NCOLS*sizeof(int));
  }

  for(int j=0; j<NCOLS; j++){
    for (int i=0; i<NLINS; i++){
      printf("Digite elemento M[%d][%d]", i, j);
      scanf("%d", *(M+i)+j);
    }
  }

  for(int j=0; j<NCOLS; j++){
    for (int i=0; i<NLINS; i++){
      for (int p=i+1; p<NLINS; p++){
        if (M[i][j] == M[p][j])
          printf("COLUNA: Elemento M[%d][%d]=%d repetido!\n", i, j, M[i][j]);
      }
    }
  }

  for(int i=0; i<NLINS; i++){
    for (int j=0; j<NCOLS; j++){
      for (int p=j+1; p<NCOLS; p++){
        if (M[i][j] == M[i][p])
          printf("LINHA: Elemento M[%d][%d]=%d repetido!\n", i, j, M[i][j]);
      }
    }
  }

  printMatriz(M, NLINS, NCOLS);

}
