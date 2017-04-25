#include <stdlib.h>
#include <stdio.h>

int main(){
  char ch;
  FILE *fp;
  char nomedoarquivo[]="lista_4_2_input.txt";

  fp = fopen(nomedoarquivo, "r");
  if (fp == NULL){
    printf("Nao foi possivel abrir.\n");
    exit(1);
  }


  while (!feof(fp)){
    ch = fgetc(fp);
    if (ch == '\n')
      printf("%c\n", ch);
  }


  fclose(fp);
}
