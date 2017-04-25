#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define NLINES 6
#define SIZEWORD 1000

int main (void) {
   char **linha;

   linha = (char **)malloc(NLINES*sizeof(char *));
   for (int i=0; i<NLINES; i++){
     *(linha + i)=(char *)malloc(SIZEWORD*sizeof(char));
   }

   int c;
   int i = 0;
   int n = 0;
   do {
      c = fgetc (stdin);
      linha[i][n] = c;
      n = n + 1;
      if (c == '\n'){
        // linha[i][n] = '\0';
        printf("new\n");
        i++;
        n=0;
      }
   } while (c != EOF);

   for (i = 0; i < NLINES-1; i ++)
      fputs (linha[i], stdout);

   return EXIT_SUCCESS;
}
