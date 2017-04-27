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

int is_digit (char c);

t_pilha* avalia_posfixa (char *expr);

void infixa_to_posfixa (char *expr, char *exprSaida);

#endif // __POSFIXA_H__
