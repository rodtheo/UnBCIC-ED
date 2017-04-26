#include <stdlib.h>
#include <check.h>
#include "../include/pilha.h"

START_TEST(test_behaviour_stack)
{
  t_pilha *pilha = get_pilha();
  char elCharPushed='a';
  char elStringPushed[3] = "abc";
  int elIntPushed=100;
  float elFloatPushed=1.54;
  t_elementPilha elPoped;

  // Checar se a pilha está vazia, deve retornar verdadeiro
  ck_assert_int_eq(empty (pilha), 1);
  // Inserimos o elemento elPushed na pilha
  push_char (pilha, &elCharPushed);

  push_int (pilha, elIntPushed);

  push_float (pilha, elFloatPushed);

  ck_assert_int_eq(top(pilha), 102932);
  // Retiramos o elemento da pilha
  pop (pilha, &elPoped);
  ck_assert_int_eq(top(pilha), 1);
  ck_assert_float_eq(elPoped.element.fval, 1.54);

  pop (pilha, &elPoped);
  ck_assert_int_eq(top(pilha), 0);
  ck_assert_int_eq(elPoped.element.ival, 100);

  // Check if the element popped is 'a'
  pop (pilha, &elPoped);
  ck_assert_int_eq(empty(pilha), 1);
  ck_assert_str_eq(elPoped.element.cval, "a");

  // We free the stack's allocated memory
  free_pilha(pilha);
}
END_TEST

Suite * pilha_suite (void){
  Suite *s;
  TCase *tc_core;

  s = suite_create ("Pilha");

  tc_core = tcase_create ("Core");

  tcase_add_test (tc_core, test_behaviour_stack);
  suite_add_tcase (s, tc_core);

  return s;
}

int main(void){
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = pilha_suite ();
  sr = srunner_create (s);

  srunner_run_all (sr, CK_NORMAL);
  number_failed = srunner_ntests_failed (sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
