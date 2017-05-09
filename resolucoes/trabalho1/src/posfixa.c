#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/pilha.h"
#include "../include/posfixa.h"

#define MAXDECIMAL 10
#define PRIOR_SUM 1
#define PRIOR_MULT  2
#define PRIOR_PAR 3

// char * digits_to_expr (char digits[]){
//   int i=0;
//   char c;
//   int idx_sn = 0;
//   float sn;
//   t_pilha *pilha;
//   pilha = get_pilha ();
//   int idxOut = 0;
//   do {
//
//     c = digits[i];
//     i++;
//
//     while (is_digit(c) || is_point(c)) {
//         string_number[idx_sn] = c;
//         idx_sn++;
//         // end while
//         string_number[idx_sn+1] = '\0';
//         printf("string_num = %s\n\n", string_number);
//         sn = atof(string_number);
//         printf("sn = %f\n\n", sn);
//         c = digits[i];
//         i++;
//     } // end if (is_digit || is_point)
//     else if ( c == ' ' ){
//       if (ifx_sn != 0){
//         push_float (pilha, sn);
//         pilha->stack[pilha->p].element.cval =
//         array_floats[idxOut] = sn;
//         idxOut++;
//
//       }
//       idx_sn = 0;
//     }
//     else {
//
//     }
//
//   } while ( c != '/0');
// }

/* return a new string with every instance of ch replaced by repl */
char *replace(const char *s) {
    // int count = 0;
    const char *t;
    // for(t=s; *t; t++)
        // count += (*t == ch);

    size_t rlen = 1;
    char *res = malloc(strlen(s)*sizeof(char));
    char *ptr = res;
    char *ch;
    for(t=s; *t; t++) {
        if((*t == '{') || (*t == '}') || (*t == '[') || (*t == ']')) {
          ch = malloc(sizeof(char));
          switch (*t)
            {
              case '{':
                *ch = '(';
                break;
              case '}':
                *ch = ')';
                break;
              case '[':
                *ch = '(';
                break;
              case ']':
                *ch = ')';
                break;
            }
            memcpy(ptr, ch, rlen);
            ptr += rlen;
        } else {
            *ptr++ = *t;
        }
    }
    *ptr = 0;
    return res;
}


void RemoveNewLines(char* source)
{
  char* i = source;
  char* j = source;
  while(*j != '\0')
  {
    *i = *j++;
    if(*i != '\n')
      i++;
  }
  *i = 0;
}

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

int is_alfa (char c){
  return (c >= 'a' && c <= 'z');
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
  char q;
  t_elementPilha opnd2, opnd1;
  int neg = 1;
  // Varremos enquanto nao chegamos ao fim da expressao posfixa
  for (posicao = 0; (c= *(expr+posicao)) != '\0';){
    q = *(expr+posicao+1);
    // printf("c = %c\n\n", c);
    // Caso em que o operando é um float ou inteiro com + de 1 dígito
    // Enquanto estivermos lendo um caractere que corresponde
    // a um único número

    if (is_digit(c) || is_point(c)){
      // printf("WORKING!!\n\n");
      string_number[idx_sn] = c;
      idx_sn++;
      // end while
      string_number[idx_sn+1] = '\0';
      // printf("string_num = %s\n\n", string_number);
      sn = atof(string_number)*neg;
      // printf("sn = %f\n\n", sn);
    } // end if (is_digit(c))
    else if ((c == '+') || (c == '-') || (c == '*') || (c == '/')){
      if ( !is_digit(q) ){
        // printf("IS DIGIT\n");
        neg = 1;
      memset(string_number,0,strlen(string_number));
      idx_sn = 0;
      // printf("topo = %d\n", top (stk));
      pop (stk, &opnd2);
      // printf("topo = %d\n", top (stk));
      pop (stk, &opnd1);
      // printf("topo = %d\n", top (stk));

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
      // printf("Resultado operacao %f %c %f = %f\n\n", opnd1.element.fval, c, opnd2.element.fval, value);
      push_float (stk, value);
    } else {
      neg = -1;
    }
  } // end else if (condicoes operandos)
  else if (c == ' ') { // caracteres que nao sao numeros e nem operadores
    // Evita a adicao de espaco à lista apos encontrar um operador
    if (idx_sn != 0){
    push_float (stk, (float)sn);}
    neg = 1;
    idx_sn = 0;
    memset(string_number,0,strlen(string_number));
  }
  posicao++;
  } // end for outer
return stk;
}

int prcd (char opr1, char opr2){
  int pOpr1, pOpr2;

  if (opr1 == '*' || opr1 == '/')
    pOpr1 = 2;
  else if (opr1 == '+' || opr1 == '-')
    pOpr1 = 1;
  else if (opr1 == '(')
    pOpr1 = -1;
  else if (opr1 == ')')
    pOpr1 = -1;


  if (opr2 == '*' || opr2 == '/')
    pOpr2 = 2;
  else if (opr2 == '+' || opr2 == '-')
    pOpr2 = 1;
  else if (opr2 == '(')
    pOpr2 = 4;
  else if (opr2 == ')')
    pOpr2 = 0;


  return (pOpr1 >= pOpr2);
}

int is_operador ( char c ){
  return ( (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') );
}

void infixa_to_posfixa (char expr[], char exprSaida[]){
  t_pilha *pilha;
  int posIn = 0;
  t_elementPilha t, tt;
  char c, q;
  char *tc;
  // t_elementPilha *tt;
  // tt = (t_elementPilha *)malloc(sizeof(t_elementPilha));
  int posPos = 0;
  pilha = get_pilha ();
  // char par = '(';
  // push_char (pilha, &par);

  do {
    c = expr[posIn];
    q = expr[posIn+1];
    // printf("caractere varrido %c\n", c);
    posIn++;

    if (!(is_operador(c)) ){
      if (c != '\0'){
        // printf("STRING FINAL=%c\n", c);
        exprSaida[posPos++] = c;
      }
    }
    // else if (c == '(') {
    //   push_char (pilha, &c);
    // }
    // else if (c == ')' || c == '\0'){
    //   do{
    //     pop (pilha, &t);
    //     if ( *(t.element.cval) != '(' )
    //       printf("%c", *(t.element.cval));
    //     } while ( *(t.element.cval) != '(');
    //   }
      else if (is_operador(c)){
        if ( is_digit(q) ){
          exprSaida[posPos++] = c;
          c = expr[posIn];
          // printf ("nao mais operador %c\n", c);
          // break;
        } else {

        while ( !empty(pilha) && prcd (*(pilha->stack[pilha->p].element.cval), c) && is_operador (c)){
              // push_char (pilha, t.element.cval);
              // push_char (pilha, &c);
              // printf("PROCEDENCIA %c\n\n",*(pilha->stack[pilha->p].element.cval));
              pop (pilha, &t);
              // printf("STRING FINAL P = %c\n", *(t.element.cval));
              // printf ("LOOP C = %c\n", c);
              exprSaida[posPos++] = ' ';
              exprSaida[posPos++] = *(t.element.cval);
            // push_char (pilha, t.element.cval);
            // else {
            //   printf("%c", *(t.element.cval));
            // } // end else
        // break; // caso a pilha esteja vazia e entre no while devemos sair
      } // end while (1)
      if ( empty (pilha) || (c != ')') ) {
        if (c != ')'){
        // printf("INSERE %c NA PILHA\n", c);
        char *ch = (char *)malloc(sizeof(char));
        *ch = c;
        push_char (pilha, ch);}
      } else { // remove o abre par e descarta ele
        pop (pilha, &tt);
        posIn--;
        // free (&tt);
      }
    } // end
  }// end else is_operador(c)
  } while (c != '\0'); // end outer while
  // printf("QNT ELEMENTOS PILHA = %d\n", top(pilha));
  while ( !(empty(pilha)) ) {
    pop (pilha, &t);
    // printf("STRING FINAL E= %c\n", *(t.element.cval));
    exprSaida[posPos++] = ' ';
    exprSaida[posPos++] = *(t.element.cval);
  }
  // printf("\n");
  free_pilha ( pilha );

  // printf ("\nEXPRESSAO FINAL = %s\n\n", exprSaida);
} // end function
