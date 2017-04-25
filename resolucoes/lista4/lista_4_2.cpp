#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 1001
#define NLINES 6
#define SIZEWORD 1000

typedef struct pilha {
  char stack[STACKSIZE];
  int p;
} t_pilha;

t_pilha* get_pilha ();
void top (t_pilha *pilha);
int push (t_pilha *pilha, char valor);
int pop (t_pilha *pilha, char *el);
int empty (t_pilha *pilha);
void check (t_pilha *pilha, char ** linha);

t_pilha* get_pilha (){
  t_pilha *pilha;
  pilha = (t_pilha *)malloc(sizeof(t_pilha));
  pilha->p=-1;

  return pilha;
}

void top (t_pilha *pilha) {
  printf("top: %d\n", pilha->p);
}

int push (t_pilha *pilha, char valor) {
  if (pilha->p < STACKSIZE-1){
    pilha->p++;
    pilha->stack[pilha->p] = valor;
    return 1;}
  else{
    return -1;
  }
}

int pop (t_pilha *pilha, char *el) {
  if (empty(pilha)){
    return -1;
  }
  else{
    *el = pilha->stack[pilha->p];
    pilha->p--;
    return 1;
  }
}

int empty (t_pilha *pilha) {
  if (pilha->p == -1)
    return 1;
  else
    return 0;
}

void check (t_pilha *pilha, char ** linha){
  char ch;
  char chout;
  int i;
  for (i = 0; i < NLINES-1; i ++) {
    int valido=1;
    int j=0;
    do {
      ch = linha[i][j];

      if (ch == '\n'){
      if (empty(pilha)){
        if(valido){
            printf("correct\n");
        } else {
          printf("incorrect\n");
        }
      } else {
        printf("incorrect\n");
      }

        pilha = get_pilha ();
        // printf("NOVA PILHA\n");
      }

      if (ch == '('){
        // printf("PUSH: %c\n", ch);
        push (pilha, ch);
      }

      if (ch == ')'){
        if (!(empty(pilha)))
          pop (pilha, &chout);
        else
          valido=0;
        // printf("POP: %c\n", chout);
      }
      j++;
    } while (ch != '\0');
  }
}

int main(){
  FILE *fp;
  int i;
  char nomedoarquivo[]="lista_4_2_input.txt";
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

  check (pilha, linha);

  // for (i = 0; i < NLINES-1; i ++)
  //    fputs (linha[i], stdout);


  // fp = fopen(nomedoarquivo, "r");
  // if (fp == NULL){
  //   printf("Nao foi possivel abrir.\n");
  //   exit(1);
  // }

  return 0;
}
