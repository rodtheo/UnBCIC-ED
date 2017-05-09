/**
 * @file pilha.h
 * @author Rodrigo Theodoro Rocha
 * @date 25 April 2016
 * @brief Arquivo contendo as definições, struct e funções para criar uma
 * estrutura do tipo pilha bem como realizar operações como inserir (push),
 * retirar (pop) e checar se a mesma está vazia (empty).
 */

#ifndef __PILHA_H__
#define __PILHA_H__

#define STACKSIZE 1001
#define NLINES 6
#define SIZEWORD 1000
#define TINT    2
#define TCHAR   3
#define TFLOAT  4


/**
 * @brief Elementos que constituem a pilha genérica.
 *
 * Os elementos podem ser do tipo int, char ou float.
 */
typedef struct elementPilha {
  int etype;
  union {
    char *cval; /* Ponteiro para uma string */
    int ival;
    float fval;
  } element;
} t_elementPilha;

/**
 * @brief Composição da struct pilha Genérica.
 *
 * A pilha é uma struct composta por um vetor de tamanho definido pela macro
 *  STACKSIZE e um inteiro que indicará o topo da pilha.
 */
typedef struct pilha {
  struct elementPilha stack[STACKSIZE];
  int p;
} t_pilha;


/**
 * Função para alocar a memória da pilha e setar o topo igual a zero (zero
 * elementos).
 * @return O ponteiro para o endereço da pilha criada.
 */
t_pilha* get_pilha ();

/**
 * Imprime o índice p do topo da pilha, isto é, a altura da pilha.
 * @param pilha Endereço da pilha criada com get_pilha().
 */
int top (t_pilha *pilha);

/**
 * Insere um elemento do tipo float na pilha genérica.
 * @param  pilha Endereço da pilha.
 * @param  valor Valor a ser inserido.
 * @return       1, se operação foi correta e 0, caso contrário.
 */
int push_float (t_pilha *pilha, float valor);

/**
 * Insere um elemento do tipo inteiro na pilha genérica.
 * @param  pilha Endereço da pilha.
 * @param  valor Inteiro para ser inserido.
 * @return       1, se operação foi correta e 0, caso contrário.
 */
int push_int (t_pilha *pilha, int valor);

/**
 * Insere um caractere na pilha genérica.
 * @param  pilha  Endereço da pilha.
 * @param  pvalor Endereço do caractere.
 * @return        1, se operação foi correta e 0, caso contrário.
 */
int push_char (t_pilha *pilha, char *pvalor);

/**
 * Retira o último elemento da @p pilha e armazena-o no ponteiro de char @p el.
 * @param  pilha Endereço da pilha criada com #get_pilha.
 * @param  el    Ponteiro de char para referenciar o elemento retirado.
 * @return       Retorna -1 se a pilha está vazia ou 1 se a função foi executada
 * com sucesso.
 */
int pop (t_pilha *pilha, t_elementPilha *el);

/**
 * Avalia se a pilha está vazia.
 * @param  pilha Endereço da pilha.
 * @return       True se a pilha é vazia e False caso contrário.
 */
int empty (t_pilha *pilha);

/**
 * Função para desalocar a pilha da memória
 * @param pilha Endereço da pilha a ser apagada.
 */
void free_pilha (t_pilha *pilha);

/**
 * Função para imprimir um elemento da pilha genérica
 * @param se Endereço do elemento
 */
void print_elem (t_elementPilha *se);

/**
 * Imprimir a composição da pilha. Usado na função calculadora.
 * @param  ps Endereço da pilha genérica a ser impressa.
 * @return    1, se válido. 0, caso contrário.
 */
int print_stack (t_pilha *ps);

#endif /* __PILHA_H__ */
