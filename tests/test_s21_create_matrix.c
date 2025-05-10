#include "./test_main.h"

START_TEST(test_valid_create_and_compare_with_array) {
  matrix_t m;
  double data[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};

  ck_assert_int_eq(s21_create_matrix(2, 3, &m), 0);
  fill_matrix_from_array(&m, data);
  ck_assert_int_eq(matrix_equals_array(&m, data), 1);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_zero_rows) {
  matrix_t m;
  ck_assert_int_eq(s21_create_matrix(0, 3, &m), 1);
}
END_TEST

START_TEST(test_zero_columns) {
  matrix_t m;
  ck_assert_int_eq(s21_create_matrix(3, 0, &m), 1);
}
END_TEST

START_TEST(test_negative_size) {
  matrix_t m;
  ck_assert_int_eq(s21_create_matrix(-2, -2, &m), 1);
}
END_TEST

START_TEST(test_null_result_pointer) {
  ck_assert_int_eq(s21_create_matrix(2, 2, NULL), 1);
}
END_TEST

START_TEST(test_minimal_matrix) {
  matrix_t m;
  ck_assert_int_eq(s21_create_matrix(1, 1, &m), 0);
  m.matrix[0][0] = 42.0;
  ck_assert_double_eq(m.matrix[0][0], 42.0);
  s21_remove_matrix(&m);
}
END_TEST

Suite *get_suite_s21_create_matrix(void) {
  Suite *s = suite_create("Create matrix");

  TCase *tc = tcase_create("Basic creation");
  tcase_add_test(tc, test_valid_create_and_compare_with_array);
  tcase_add_test(tc, test_zero_rows);
  tcase_add_test(tc, test_zero_columns);
  tcase_add_test(tc, test_negative_size);
  tcase_add_test(tc, test_null_result_pointer);
  tcase_add_test(tc, test_minimal_matrix);
  suite_add_tcase(s, tc);

  return s;
}
