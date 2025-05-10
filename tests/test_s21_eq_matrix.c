#include "./test_main.h"

START_TEST(test_equal_matrices) {
  matrix_t A, B;
  double vals[] = {1.0, 2.0, 3.0, 4.0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  fill_matrix_from_array(&A, vals);
  fill_matrix_from_array(&B, vals);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_different_values) {
  matrix_t A, B;
  double a_vals[] = {1.0, 2.0, 3.0, 4.0};
  double b_vals[] = {1.0, 2.0, 3.0, 5.0};  // Последний элемент отличается

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  fill_matrix_from_array(&A, a_vals);
  fill_matrix_from_array(&B, b_vals);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_different_sizes) {
  matrix_t A, B;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 2, &B);  // Размер отличается

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_null_matrices) {
  matrix_t *A = NULL;
  matrix_t B;

  s21_create_matrix(2, 2, &B);

  ck_assert_int_eq(s21_eq_matrix(A, &B), FAILURE);
  ck_assert_int_eq(s21_eq_matrix(&B, NULL), FAILURE);
  ck_assert_int_eq(s21_eq_matrix(NULL, NULL), FAILURE);

  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_self_comparison) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  fill_sequential(&A);

  ck_assert_int_eq(s21_eq_matrix(&A, &A), SUCCESS);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_almost_equal_within_precision) {
  matrix_t A, B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  double values[] = {1.000001, 2.000001, 3.000001, 4.000001, 5.000001,
                     6.000001, 7.000001, 8.000001, 9.000001};

  fill_matrix_from_array(&A, values);
  fill_matrix_from_array(&B, values);

  // Вносим микро-изменение в один элемент (в пределах 1e-7)
  B.matrix[1][1] += 1e-8;

  ck_assert_int_eq(s21_eq_matrix(&A, &B),
                   SUCCESS);  // всё равно должны считаться равными

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *get_suite_s21_eq_matrix(void) {
  Suite *s = suite_create("Equal matrix");

  TCase *tc = tcase_create("Comparison");
  tcase_add_test(tc, test_equal_matrices);
  tcase_add_test(tc, test_different_values);
  tcase_add_test(tc, test_different_sizes);
  tcase_add_test(tc, test_null_matrices);
  tcase_add_test(tc, test_self_comparison);
  tcase_add_test(tc, test_almost_equal_within_precision);
  suite_add_tcase(s, tc);

  return s;
}
