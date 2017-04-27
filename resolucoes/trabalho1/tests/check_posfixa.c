#include <stdlib.h>
#include <check.h>
#include "../include/posfixa.h"
#include "../include/pilha.h"

START_TEST(test_behaviour_posfixa)
{

  char expr1[50] = "a+(b*c)-2-a"; // forma infixa correta
  char expr2[50] = "(a+b*(2-c)-2+a)*2"; // forma infixa correta
  char expr3[50] = "(a*b-(2+c)";// forma infixa INcorreta
  char expr4[50] = "2*(3-a))";// forma infixa INcorreta
  char expr5[50] = ")3+b*(2-c)(";// forma infixa INcorreta

  // Checar validade das expressoes propostas acima
  ck_assert_int_eq( check_infixa ( expr1), 1);
  ck_assert_int_eq( check_infixa ( expr2), 1);
  ck_assert_int_eq( check_infixa ( expr3), 0);
  ck_assert_int_eq( check_infixa ( expr4), 0);
  ck_assert_int_eq( check_infixa ( expr5), 0);

  // Avaliar o resultado das expressoes posfixas
  char expr1Pos[50] = "6 2 3 + *";
  t_pilha *pilha;

  pilha = avalia_posfixa (expr1Pos);
  //ck_assert_msg ((pilha->stack[0].element.fval == 30),
  //                "Result %d", pilha->stack[0].element.fval);


}
END_TEST

Suite * posfixa_suite (void){
  Suite *s;
  TCase *tc_core;

  s = suite_create ("Posfixa");

  tc_core = tcase_create ("Core");

  tcase_add_test (tc_core, test_behaviour_posfixa);
  suite_add_tcase (s, tc_core);

  return s;
}

int main(void){
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = posfixa_suite ();
  sr = srunner_create (s);

  srunner_run_all (sr, CK_NORMAL);
  number_failed = srunner_ntests_failed (sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
