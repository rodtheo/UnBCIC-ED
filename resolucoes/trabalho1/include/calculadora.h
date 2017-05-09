/**
 * @file calculadora.h
 * @author Rodrigo Theodoro Rocha
 * @date 25 April 2016
 * @brief Arquivo contendo as funções para implementar o funcionamento da
 *  calculadora.
 */
#ifndef __CALCULADORA_H__
#define __CALCULADORA_H__

#include <stdio.h>
#include <stdlib.h>
#include "../include/pilha.h"

/**
 * Aplica uma das 4 operações primárias nos 2 últimos elementos da pilha @p stk.
 * @param stk Endereço da pilha stk
 * @param c   Caractere do operador para executar
 */
void apply_operacao (t_pilha *stk, char c);

/**
 * Função usada na repetição de N vezes o elemento.
 * @param stk pilha
 */
void apply_copia_el (t_pilha *stk);

/**
 * Aplica recursivamente a operação especificada pelo caractere c.
 * @param stk pilha
 * @param c   operador
 */
void apply_repeticao (t_pilha *stk, char c);

/**
 * Aplica a operação c nos 2 operandos especificados
 * @param  fopnd1 operando 1
 * @param  fopnd2 operando 2
 * @param  c      operador
 * @return        Retorna o valor.
 */
int apply_operador (float fopnd1, float fopnd2, char c);

#endif
