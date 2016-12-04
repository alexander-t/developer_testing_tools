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
   Suite *suite = suite_create("Basic assertions");;
   TCase *test_case = tcase_create("Integer assertions");
   tcase_add_test(test_case, int_eq);
   tcase_add_test(test_case, int_ne);
   tcase_add_test(test_case, int_lt);
   tcase_add_test(test_case, int_le);
   tcase_add_test(test_case, int_gt);
   tcase_add_test(test_case, int_ge);
   suite_add_tcase(suite, test_case);
   return suite;
}

/*
ck_assert(expr)
ck_assert_msg(expr, ...)
ck_abort()
ck_abort_msg(...)

Check the relationship between two strings:
         ck_assert_str_eq
         ck_assert_str_ne
         ck_assert_str_lt
         ck_assert_str_le
         ck_assert_str_gt
         ck_assert_str_ge
Check the relationship between two pointers:
           ck_assert_ptr_eq
         ck_assert_ptr_ne

*/
