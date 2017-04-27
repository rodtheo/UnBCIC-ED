#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/pilha.h"

#define MAXDECIMAL 10
#define PRIOR_SUM 1
#define PRIOR_MULT  2

int check_infixa (char *expr){
  char ch;
  t_elementPilha chout;
  int valido=1;
  int j=0;
  // Iniciamos uma pilha que conterá os parenteses
  t_pilha *pilha = get_pilha ();
  do {
    ch = expr[j];

    // Se o caractere encontrado na expressao for um parenteses
    // de começo, incluir ele na pilha
    if (ch == '('){
      push_char (pilha, &ch);
    }
    // Para a expressao ser valida devemos achar um parentese final para cada par inicial
    if (ch == ')'){
      // Evitar segmentation fault ao fazer pop numa pilha vazia
      if (!(empty(pilha)))
        pop (pilha, &chout);
      else
        valido=0;
    }
    j++;
  } while (ch != '\0');

    // Caso a pilha esteja vazia checar se o indicador (valido)
    // é True ou False
    if (empty(pilha)){
      if(valido){
          printf("correct\n");
          return 1;
      } else {
        printf("incorrect\n");
          return 0;
      } // end else if(valido)
    } else { // Caso a pilha esteja cheia é pq exitem quantidades desbalanceadas de parênteses
      printf("incorrect\n");
      return 0;
    } // end else if(empty(pilha)
  }

int is_digit (char c){
  return (c >= '0' && c <='9');
}

int is_point (char c){
  return (c == '.');
}

t_pilha* avalia_posfixa (char *expr){
  t_pilha *stk = get_pilha();
  int posicao;
  char c;
  char string_number[MAXDECIMAL];
  int idx_sn=0;
  float value;
  float sn;
  t_elementPilha opnd2, opnd1;
  // Varremos enquanto nao chegamos ao fim da expressao posfixa
  for (posicao = 0; (c= *(expr+posicao)) != '\0';){
    printf("c = %c\n\n", c);
    // Caso em que o operando é um float ou inteiro com + de 1 dígito
    // Enquanto estivermos lendo um caractere que corresponde
    // a um único número

    if (is_digit(c) || is_point(c)){
      printf("WORKING!!\n\n");
      string_number[idx_sn] = c;
      idx_sn++;
      // end while
      string_number[idx_sn+1] = '\0';
      printf("string_num = %s\n\n", string_number);
      sn = atof(string_number);
      printf("sn = %f\n\n", sn);
    } // end if (is_digit(c))
    else if ((c == '+') || (c == '-') || (c == '*') || (c == '/')){
      memset(string_number,0,strlen(string_number));
      idx_sn = 0;
      printf("topo = %d\n", top (stk));
      pop (stk, &opnd2);
      printf("topo = %d\n", top (stk));
      pop (stk, &opnd1);
      printf("topo = %d\n", top (stk));

      switch (c){
        case '+':
          value = opnd1.element.fval + opnd2.element.fval;
          break;
        case '-':
          value = opnd1.element.fval - opnd2.element.fval;
          break;
        case '*':
          value = opnd1.element.fval * opnd2.element.fval;
          break;
        case '/':
          value = opnd1.element.fval / opnd2.element.fval;
          break;
        default:
          printf("%c - não é um operador válido!\n", c);
          return NULL;
      }
      printf("Resultado operacao %f %c %f = %f\n\n", opnd1.element.fval, c, opnd2.element.fval, value);
      push_float (stk, value);
  } // end else if (condicoes operandos)
  else if (c == ' ') { // caracteres que nao sao numeros e nem operadores
    // Evita a adicao de espaco à lista apos encontrar um operador
    if (idx_sn != 0){
    push_float (stk, (float)sn);}
    idx_sn = 0;
    memset(string_number,0,strlen(string_number));
  }
  posicao++;
  } // end for outer
return stk;
}

int prioridade_operador (char opr){
  int prior=0;
  switch (opr){
    case '+':
      prior = PRIOR_SUM;
      break;
    case '-':
      prior = PRIOR_SUM;
      break;
    case '/':
      prior = PRIOR_MULT;
      break;
    case '*':
      prior = PRIOR_MULT;
      break;
    default:
      printf("Não é um operador válido!\n\n");
      break;
  }
  return prior;
}

void infixa_to_posfixa (char *expr, char *exprSaida){
  t_pilha *pilha = get_pilha();
  char c;
  int pos;
  char oprTopo;
  int idxTopo;
  t_elementPilha elTopo;
  int priorCurrent, priorTopo;
  int outpos=0;
  for (pos = 0; (c = expr[pos]) != '\0'; pos ++){
    printf("C = %c\n\n", c);
    if ((c == '+') || (c == '-') || (c == '/') || (c == '*')){
      if ( (!empty(pilha)) ){
        idxTopo = top (pilha);
        oprTopo = *(pilha->stack[idxTopo].element.cval);
        printf("TESTe prior %c vs %c\n\n", oprTopo, c);
        if ( (prioridade_operador(oprTopo) >=   prioridade_operador(c)) ){
          pop (pilha, &elTopo);
          exprSaida[outpos++] = *(elTopo.element.cval);
        }
      } else {
          push_char (pilha, &c);
        }
      }      // end if operadores
    if (c == '(') { // inicio 2a condicao

          push_char (pilha, &c);
          printf("ADD ( na pos %d!!\n\n", top(pilha));
        }
    if (c == ')'){
      printf("WORKING!!\n\n");
      printf("W topo = %c na pos %d\n", *(elTopo.element.cval), top (pilha));
        // while ( ( *(elTopo.element.cval) != '(') ){
        //   pop (pilha, &elTopo);
        //   printf("Elemento topo: %c\n", *(elTopo.element.cval));
        //   exprSaida[outpos++] = *(elTopo.element.cval);
        //   pos++;}
      }
    else { // c é um operando
        // inclui c na string posfixa
        exprSaida[outpos++] = c;
      }
  } // end for
  if (!empty (pilha)){
    pop (pilha, &elTopo);
    exprSaida[outpos++] = *(elTopo.element.cval);
  }
  }
