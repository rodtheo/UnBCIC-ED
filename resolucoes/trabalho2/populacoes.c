#ifndef POPULACOES_H
#define POPULACOES_H

#include <string.h>
#include "arvore.h"

void buscar_caract(char* caracteristica, Tree* raiz) {
  if (raiz != NULL){
    printf("%s\n", raiz->info->carac);
    if (strcmp (raiz->info->carac, caracteristica) == 1){
      return raiz;
    }
    buscar_caract(caracteristica, raiz->left);
    buscar_catact(caracteristica, raiz->right);
  }
}







#endif
