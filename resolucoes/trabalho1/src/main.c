#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/pilha.h"
#include "../include/posfixa.h"

int main(){
  FILE *fp;
  int i;
  char nomedoarquivo[]="../tests/lista_4_2_input.txt";
  t_pilha *pilha = get_pilha ();
  //
  // char **linha;
  //
  // linha = (char **)malloc(NLINES*sizeof(char *));
  // for (i=0; i<NLINES; i++){
  //   *(linha + i)=(char *)malloc(SIZEWORD*sizeof(char));
  // }
  //
  // int c;
  // i = 0;
  // int n = 0;
  // do {
  //    c = fgetc (stdin);
  //    linha[i][n] = c;
  //    n = n + 1;
  //    if (c == '\n'){
  //      linha[i][n] = '\0';
  //      i++;
  //      n=0;
  //    }
  // } while (c != EOF);


  // char expr1Pos[50] = "6 2.5 7.5 + *";
  // t_pilha *result_posfixa;
  // result_posfixa = avalia_posfixa (expr1Pos);
  //
  // printf("Resultado da avaliacao = %f\n\n", result_posfixa->stack[0].element.fval);

  char expr1[50] = "A*(B+C)/D";
  char result_transformacao[100];
  infixa_to_posfixa (expr1, result_transformacao);

  printf("A transformacao da infixa %s para prefixa %s.\n\n", expr1, result_transformacao);

  //checkValidity (pilha, linha);

  // for (i = 0; i < NLINES-1; i ++)
  //    fputs (linha[i], stdout);


  // fp = fopen(nomedoarquivo, "r");
  // if (fp == NULL){
  //   printf("Nao foi possivel abrir.\n");
  //   exit(1);
  // }

  return 0;
}
