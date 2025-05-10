#include "./test_main.h"

START_TEST(test_remove_valid_matrix) {
  matrix_t m;
  ck_assert_int_eq(s21_create_matrix(3, 3, &m), 0);

  s21_remove_matrix(&m);

  ck_assert_ptr_null(m.matrix);
  ck_assert_int_eq(m.rows, 0);
  ck_assert_int_eq(m.columns, 0);
}
END_TEST

START_TEST(test_remove_null_matrix_pointer) {
  matrix_t *m = NULL;

  // Должен просто ничего не делать
  s21_remove_matrix(m);

  ck_assert_ptr_null(m);  // m и так NULL — просто убедимся, что не крашится
}
END_TEST

START_TEST(test_double_free_safe) {
  matrix_t m;
  ck_assert_int_eq(s21_create_matrix(2, 2, &m), 0);

  s21_remove_matrix(&m);
  s21_remove_matrix(&m);  // Повторный вызов — должен быть безопасен

  ck_assert_ptr_null(m.matrix);
  ck_assert_int_eq(m.rows, 0);
  ck_assert_int_eq(m.columns, 0);
}
END_TEST

Suite *get_suite_s21_remove_matrix(void) {
  Suite *s = suite_create("Remove matrix");

  TCase *tc = tcase_create("Core");
  tcase_add_test(tc, test_remove_valid_matrix);
  tcase_add_test(tc, test_remove_null_matrix_pointer);
  tcase_add_test(tc, test_double_free_safe);
  suite_add_tcase(s, tc);

  return s;
}
