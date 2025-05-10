#include "test_main.h"

int main() {
  int failed = 0, total = 0;

  Suite *Tests[] = {get_suite_s21_create_matrix(),
                    get_suite_s21_remove_matrix(),
                    get_suite_s21_eq_matrix(),
                    get_suite_s21_sum_matrix(),
                    get_suite_s21_sub_matrix(),
                    get_suite_s21_mult_matrix(),
                    get_suite_s21_mult_number(),
                    get_suite_s21_transpose(),
                    get_suite_s21_determinant(),
                    get_suite_s21_calc_complements(),
                    get_suite_s21_inverse_matrix(),
                    get_suite_s21_get_minor(),
                    NULL};
  for (int i = 0; Tests[i] != NULL; i++) {
    SRunner *sr = srunner_create(Tests[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    int current_failed = srunner_ntests_failed(sr);
    if (current_failed > 0) {
      failed += current_failed;
      printf(DARK_RED "================ FAILED =================\n" NOCOLOR);
    } else {
      printf(LIGHT_GREEN "================ SUCCESS ================\n" NOCOLOR);
    }

    total += srunner_ntests_run(sr);
    srunner_free(sr);
  }

  printf("\nTEST RESULT " LIGHT_GREEN "\nTOTAL:\t%d" DARK_RED
         "\nFAILED:\t%d" NOCOLOR "\n",
         total, failed);

  return failed == 0 ? 0 : 1;
}

void fill_matrix_from_array(matrix_t *m, const double *values) {
  int index = 0;
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->columns; j++) {
      m->matrix[i][j] = values[index++];
    }
  }
}

int matrix_equals_array(matrix_t *m, const double *values) {
  if (!m || !m->matrix || !values) return 0;

  double *ptr = m->matrix[0];  // доступ к плоскому массиву
  int total = m->rows * m->columns;

  for (int i = 0; i < total; i++) {
    if (fabs(ptr[i] - values[i]) > 1e-7) {
      return 0;  // несовпадение
    }
  }
  return 1;  // всё совпало
}

void fill_sequential(matrix_t *m) {
  int val = 1;
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->columns; j++) {
      m->matrix[i][j] = val++;
    }
  }
}
