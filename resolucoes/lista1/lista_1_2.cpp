#include <stdlib.h>
#include <stdio.h>

typedef struct matriz{
  int **MATRIZ;
  int NLINS;
  int NCOLS;
} t_mat;

void printMatriz(int **M, int, int);
t_mat* multiplicacao(t_mat* M, t_mat* N);
void getMatriz(char inicial, t_mat *M);

void printMatriz(int **M, int NLINS, int NCOLS){
  for (int i=0; i<NLINS; i++){
    for(int j=0; j<NCOLS; j++){
      printf("%d ", M[i][j]);
    }
    printf("\n");
  }
}

t_mat* multiplicacao(t_mat* M, t_mat* N){
  int NCOLS, NLINS;
  t_mat *R = (t_mat*)malloc(sizeof(t_mat));
  int **RM;

  NLINS = M->NLINS;
  NCOLS = N->NCOLS;

  if (M->NCOLS != N->NLINS){
    printf("Essas matrizes nao satisfazem as condicoes de multiplicacao!\n");
    return R;
  }

  // RM = R->MATRIZ;
  RM = (int **)malloc(NLINS*(sizeof(int *)));

  for (int i=0; i<NLINS; i++){
    *(RM+i) = (int *)malloc(NCOLS*sizeof(int));
  }

  int result=0;
  for (int jj=0; jj<N->NCOLS; jj++){
    for (int i=0; i<M->NLINS; i++){
      for (int j=0; j<M->NCOLS; j++){
        result=result+M->MATRIZ[i][j]*N->MATRIZ[j][jj];
      }
      RM[i][jj] = result;
      result=0;
    }
  }
  R->MATRIZ = RM;
  R->NCOLS = NCOLS;
  R->NLINS = NLINS;

  return R;
}

void getMatriz(char inicial, t_mat* M){
  int N, C;
  printf("Digite o num de linhas da matriz a ser formada: ");
  scanf("%d", &N);
  printf("Digite o num de colunas da matriz a ser formada: ");
  scanf("%d", &C);

  M->NLINS=N;
  M->NCOLS=C;

  printf("As dimensoes da matriz %c sao (%d, %d)\n\n", inicial, M->NLINS, M->NCOLS);

  M->MATRIZ=(int **)malloc(N*(sizeof(int *)));

  for (int i=0; i<N; i++){
    *(M->MATRIZ+i) = (int *)malloc(C*sizeof(int));
  }

  for(int j=0; j<C; j++){
    for (int i=0; i<N; i++){
      printf("Digite elemento %c[%d][%d]", inicial, i, j);
      scanf("%d", *(M->MATRIZ+i)+j);
    }
  }
}

int main(){
  t_mat *M, *N, *R;

  M= (t_mat *)malloc(sizeof(t_mat));

  getMatriz('M', M);
  getMatriz('N', N);

  R = multiplicacao(M, N);
  // int NLINS, NCOLS;

  // (*dM).NLINS=2;
  // (*dM).NCOLS=2;

  // dM->NLINS = NLINS;
  // dM->NCOLS = NCOLS;

  // getMatriz('M', M, dM);
  // N = getMatriz('N', N, dN);
  // dN.NLINS=2;
  // dN.NCOLS=2;
  // dM->NCOLS=2;
  // dM->NLINS=2;
  // printf("DIM: (%d, %d)", dN.NLINS, dN.NCOLS);
  // printf("DIM: (%d, %d)", dM->NLINS, dM->NCOLS);



  printMatriz(R->MATRIZ, R->NLINS, R->NCOLS);

}
