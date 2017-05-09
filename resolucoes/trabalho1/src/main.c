#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/pilha.h"
#include "../include/posfixa.h"
#include "../include/calculadora.h"

int main(){

  char strNumber[11];
  float fNumber;
  char c, q;
  int pos, posOut;
  char strAfterNumber[11];
  int neg;
  t_pilha *stk;

  char opcaoExterna;
  int opcaoExternaInt=0;
  int opcaoMenu = 1;

  while (opcaoMenu == 1){
  printf("******************************\n");
  printf("*** Escolha o módulo *********\n");
  printf("******************************\n");
  printf("Entre com a opcao desejada: \n");
  printf("(1): Iniciar Calculadora\n");
  printf("(2): Iniciar Modo Expressão\n");
  printf("(CTRL+C): Sair\n");
  opcaoExterna = fgetc(stdin);
  opcaoExternaInt = atoi(&opcaoExterna);
  // printf("OpcaoExterna=%d\n", atoi(&opcaoExterna));
  stk = get_pilha();
  while (opcaoExternaInt == 1){

    // Inicia Calculadora
    printf ("\n");
    printf("-----------------------------\n");
    printf("Modo Calculadora\n");
    printf("-----------------------------\n");
    printf("Digite um número (real), uma operação ou comandos abaixo:\n");
    printf("(+): aplica a soma dos dois últimos elementos da pilha\n");
    printf("(-): aplica a subtração dos dois últimos elementos da pilha\n");
    printf("(*): aplica a multiplacação nos dois últimos elementos da pilha\n");
    printf("(/): aplica a divisão dos dois últimos elementos da pilha\n");
    printf("(x!): aplica-se recursivamente uma operação x, onde x deve ser substituido por um dos 4 operadores acima (+,-,*,/)\n");
    printf("(c): dada uma pilha com 2 elementos ou mais, esta operação repete o penúltimo elemento da pilha N vezes e isere-o na pilha. Onde N é o número o topo da pilha\n");
    printf("(e): Volta ao menu inicial\n");

    do {
      fgets (strNumber, 11, stdin);
      memset(strAfterNumber,0,strlen(strAfterNumber));
      posOut = 0;
      neg = 1;

      for ( pos = 0; (c = *(strNumber+pos)) != '\0'; ){
        pos++;
        q = *( strNumber + pos ); /* próximo caractere após c */
        if ( is_digit(c) || is_point(c) ){
          strAfterNumber[posOut++] = c;
        } else if ( is_operador(c) ) {
          if ( is_digit(q) ){
            neg = -1;
          } else if ( q == '!' ){
            printf("repeticao\n");
            apply_repeticao (stk, c);
            print_stack (stk);
          }
          else {
            apply_operacao (stk, c);
            printf("aplicar operacao\n");
            print_stack (stk);
          }
        } // end elseif is_operador
        else if ( c == 'c' ){
          apply_copia_el (stk);
          printf("copia\n");
          print_stack (stk);
        } // end elsif repeticao
        else if ( c == 'e' ){
          printf("Volta menu e esvazia a pilha!\n");
          free_pilha (stk);
          opcaoExternaInt = 0;
          fNumber = -1;
        }
        else if ( c == 'o' ){
          fNumber = -1;
        }
      } // end for
      // printf("after for\n");
      // printf("%s\n", strAfterNumber);
      if (strlen(strAfterNumber) > 0 ){
        fNumber = atof(strNumber);
        push_float (stk, fNumber);
        print_stack (stk);
      }

    } while (fNumber != -1); // end while da Calculadora
  } // end while da opcaoExterna da Calculadora

  if (opcaoExternaInt == 2){
    int validaInfixa;
    char ch;
    char exprIn[100];
    char exprPos[100];
    t_pilha *pilhaPos;
    while ((ch = getchar()) != '\n' && ch != EOF);
    printf ("Digite a expressão na forma infixa (separe cada termo com espaços):");
    fgets (exprIn, 100, stdin);
    char *exprInReplaced;
    exprInReplaced = replace (exprIn);
    validaInfixa = check_infixa (exprInReplaced);

    if (!validaInfixa) {
      printf ("A expressão infixa %s é inválida!\n\n", exprIn);
      opcaoExternaInt = 0;
    } else {
      printf ("A expressão infixa %s é válida! \n\n", exprInReplaced);
      infixa_to_posfixa (exprInReplaced, exprPos);
      RemoveNewLines(exprPos);
      printf ("A forma posfixa é: %s", exprPos);
      pilhaPos = avalia_posfixa (exprPos);
      printf ("\nA avaliação da expressão %s resulta em: %.2f", exprPos, pilhaPos->stack[pilhaPos->p].element.fval);
    }
  }

} // end while do menu principal

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
