
#ifndef __FILA_H__
#define __FILA_H__

#include "arvore.h"

#define VAZIA -1

typedef struct fila{
    t_no **item;
    int tamanho;
    int inicio, fim;
} t_fila;


t_fila* getFila(int tamanho);
void    liberaFila(t_fila* fila);

void    inserirFila(t_fila* fila, t_no* elemento);
t_no*   removerFila(t_fila* fila);

int     filaVazia(t_fila* fila);
//int     filaCheia(t_fila* fila);

void    imprimirFila(t_fila* fila);




#endif
