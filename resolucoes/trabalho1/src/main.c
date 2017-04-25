#include <stdlib.h>
#include <stdio.h>
#include "../include/pilha.h"

int main(){
  FILE *fp;
  int i;
  char nomedoarquivo[]="../tests/lista_4_2_input.txt";
  t_pilha *pilha = get_pilha ();

  char **linha;

  linha = (char **)malloc(NLINES*sizeof(char *));
  for (i=0; i<NLINES; i++){
    *(linha + i)=(char *)malloc(SIZEWORD*sizeof(char));
  }

  int c;
  i = 0;
  int n = 0;
  do {
     c = fgetc (stdin);
     linha[i][n] = c;
     n = n + 1;
     if (c == '\n'){
       linha[i][n] = '\0';
       i++;
       n=0;
     }
  } while (c != EOF);

  checkValidity (pilha, linha);

  // for (i = 0; i < NLINES-1; i ++)
  //    fputs (linha[i], stdout);


  // fp = fopen(nomedoarquivo, "r");
  // if (fp == NULL){
  //   printf("Nao foi possivel abrir.\n");
  //   exit(1);
  // }

  return 0;
}
