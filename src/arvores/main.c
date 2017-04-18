#include <stdio.h>
#include <stdlib.h>

#include "lista_arvore.h"
#include "arvores.h"


// Recebe a raiz r de uma árvore binária e
// imprime os conteúdos dos seus nós
// em ordem e-r-d.
// void erd_i (arvore r) {
//    criapilha ();  // pilha de nós
//    empilha (r);
//    while (1) {
//       x = desempilha ();
//       if (x != NULL) {
//          empilha (x);
//          empilha (x->esq);
//       }
//       else {
//          if (pilhavazia ()) break;
//          x = desempilha ();
//          printf ("%d\n", x->conteudo);
//          empilha (x->dir);
//       }
//    }
//    liberapilha ();
// }

int main(){
  t_node *arvore, *p, *q;
  int number;

  scanf("%d", &number);
  arvore = criano(number);

  while (number != -1){
    scanf("%d", &number);
    // p e q serao utilizados no percurso da árvore. p aponta
    // para um nó pai e q aponta seu filho direito ou esquerdo
    p = q = arvore;
    // a árvore é percorrida até encontrar a primeira ocorrência
    // do número anteriormente digitado ou encontrar um ponteiro
    // esquero ou direito NULL
    while ((p->info != number) && (q != NULL)){
      p = q;
      if (number < p->info)
        q = p->esquerda;
      else
        q = p->direita;
    }
    // se o laço foi interrompido devido a (number == p->info), deve
    // indicar que o número já ocorreu antes
    if (number == p->info)
      printf ("%d já ocorreu.\n Digite:\n", number);
    // Se o laço foi interrompido devido a q == NULL, a árvore foi
    // toda percorrida e o número não foi encontrado. Nesse caso,
    // deve ser incluído como filho direito ou esquero de p
    else if (number < p->info){
      setleft (p, number);
    }
    else {
      setright (p, number);
    }
  }
  // setleft(arvore, 4);
  // setright(arvore, 6);
  printf("-----------------------------------------------------------\n");
  em_ordem (arvore);
  printf("-----------------------------------------------------------\n");
  em_largura (arvore);

  return 0;
}
