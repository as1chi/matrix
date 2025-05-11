#include "s21_tests.h"

int main(void) {
  int failed = 0;
  int total = 0;

  // Массив с наборами тестов
  Suite *suites[] = {create_remove_suite(),
                     eq_matrix_suite(),
                     sum_matrix_suite(),
                     sub_matrix_suite(),
                     mult_number_suite(),
                     mult_matrix_suite(),
                     transpose_suite(),
                     determinant_suite(),
                     calc_complements_suite(),
                     inverse_matrix_suite(),
                     NULL};

  // Запуск всех тестов
  for (int i = 0; suites[i] != NULL; i++) {
    SRunner *sr = srunner_create(suites[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    total += srunner_ntests_run(sr);
    srunner_free(sr);
  }

  // Вывод результатов
  printf("\n");
  printf("\033[33mTOTAL  : %-3d\033[0m\n", total);
  printf("\033[32mSUCCESS: %-3d\033[0m\n", total - failed);
  printf("\033[31mFAILED : %-3d\033[0m\n", failed);
  printf("\n");

  return failed == 0 ? 0 : 1;
}

void s21_init_matrix(double number, matrix_t *A) {
  for (int x = 0; x < A->rows; x += 1) {
    for (int y = 0; y < A->columns; number += 1.0, y += 1)
      A->matrix[x][y] = number;
  }
}
