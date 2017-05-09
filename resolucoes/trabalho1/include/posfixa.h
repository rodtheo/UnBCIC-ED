/**
 * @file posfixa.h
 * @author Rodrigo Theodoro Rocha
 * @date 25 April 2016
 * @brief Arquivo contendo as assinaturas das funções implementadas para executar as operações de validação das expressões infixa (usual), conversão das expressões infixas para posfixas, avaliação do resultado das expressões posfixa. O arquivo também contem implmentações das funções auxiliares como por exemplo substituir chaves e colchetes por parênteses ( replace() ).
 */
#ifndef __POSFIXA_H__
#define __POSFIXA_H__

#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

/**
 * Função que avalia se uma expressão passada no parâmetro @p linha é uma
 * expressão infixa (usual) válida. Avalia se os parênteses são restrições
 * válidas.
 *
 * @param pilha Endereço da estrutura da pilha *vazia* para auxiliar
 * na determinação da validade da expressão.
 * @param linha Ponteiro para ponteiro da forma char referenciando uma expressão
 *  da forma infixa (usual).
 */
int check_infixa (char *expr);

/**
 * Função auxiliar para testar se o caractere @p c é um digito (entre 0-9).
 * @param  c Caractere de entrada.
 * @return   1, se @p c é um digito.
 */
int is_digit (char c);

/**
 * Dada uma expressão na forma infixa calcula o resultado da mesma.
 * @param  expr Entrada na forma infixa respeitando-se as notações no manual.
 * @return      Endereço de uma pilha onde o único elemento, no topo, é um float.
 */
t_pilha* avalia_posfixa (char *expr);

/**
 * Estabelece a procedência dos operadores e parênteses para converter
 * corretamente a expressão para a forma posfixa.
 * @param  opr1 Operador
 * @param  opr2 Operador
 * @return      1, se o @p opr1 tem maior ou igual procedência ao operador @p opr2.
 */
int prcd (char opr1, char opr2);

/**
 * Converte uma expressão na forma posfixa para a infixa.
 * @param expr      Entrada da expressão infixa.
 * @param exprSaida Endereço da expressão final.
 */
void infixa_to_posfixa (char expr[], char exprSaida[]);

/**
 * Avalia se o caractere é um operador.
 * @param  c Caractere
 * @return   1, se @p c é operador. 0, caso contrário.
 */
int is_operador ( char c );

/**
 * Avalia se o caractere é um ponto. Para permitir números fracionados.
 * @param  c Caractere.
 * @return   1, se @p c é um ponto. 0, cc.
 */
int is_point (char c);

/**
 * Remove caractere de nova linha \n de uma string.
 * @param source Endereço da string.
 */
void RemoveNewLines(char* source);

/**
 * Substitui chaves ({,}), colchetes ([,]) pelo parêntese correspondente.
 * @param  s String.
 * @return   Endereço da string com as substituições.
 */
char *replace(const char *s);

#endif // __POSFIXA_H__
