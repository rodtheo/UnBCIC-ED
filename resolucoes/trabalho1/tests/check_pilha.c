#include <stdlib.h>
#include <check.h>
#include "../include/pilha.h"

START_TEST(test_behaviour_stack)
{
  t_pilha *pilha = get_pilha();
  char elPushed='a';
  char *elPoped;

  // Checar se a pilha está vazia, deve retornar verdadeiro
  ck_assert_int_eq(empty (pilha), 1);
  // Inserimos o elemento elPushed na pilha
  push (pilha, elPushed);
  // Retiramos o elemento da pilha
  pop (pilha, elPoped);
  // Check if the element popped is 'a'
  ck_assert_str_eq(elPoped, "a");
  // We free the stack's allocated memory
  free_pilha(pilha);
}
END_TEST

int main(void){
  return 0;
}
