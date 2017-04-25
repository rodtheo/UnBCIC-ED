#ifndef __POSFIXA_H__
#define __POSFIXA_H__

#include <stdlib.h>
#include <stdio.h>

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
void check_infixa (t_pilha *pilha, char ** linha);

int is_digit (char c);

float avalia_posfixa (char **expr);
