#include <check.h>

START_TEST (int_eq)
{
   ck_assert_int_eq(42, 42);
}
END_TEST

START_TEST (int_ne)
{
   ck_assert_int_ne(42, 21);
}
END_TEST

START_TEST (int_lt)
{
   ck_assert_int_lt(41, 42);
}
END_TEST

START_TEST (int_le)
{
   ck_assert_int_le(41, 42);
   ck_assert_int_le(42, 42);
}
END_TEST

START_TEST (int_gt)
{
   ck_assert_int_gt(43, 42);
}
END_TEST

START_TEST (int_ge)
{
   ck_assert_int_ge(42, 42);
   ck_assert_int_ge(43, 42);
}
END_TEST

Suite *create_integer_assertions_suite(void)
{
   Suite *suite = suite_create("Integer assertions");
   TCase *eq_case = tcase_create("Equality");
   tcase_add_test(eq_case, int_eq);
   tcase_add_test(eq_case, int_ne);

   TCase *ltgt_case = tcase_create("Less than/Greater than");
   tcase_add_test(ltgt_case, int_lt);
   tcase_add_test(ltgt_case, int_le);
   tcase_add_test(ltgt_case, int_gt);
   tcase_add_test(ltgt_case, int_ge);
   suite_add_tcase(suite, ltgt_case);
   return suite;
}
