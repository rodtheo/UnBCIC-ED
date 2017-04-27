# UNIT TEST

Existem 2 modos de executar o `make test` para imprimir mensagens de erro na tela quando usadas funcoes como `printf` ou `ck_assert_msg`.

1. `make test CTEST_OUTPUT_ON_FAILURE=1`
2. ctest --verbose
