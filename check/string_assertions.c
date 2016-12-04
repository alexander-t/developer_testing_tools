#include <check.h>

START_TEST (str_eq)
{
   ck_assert_str_eq("Hello World", "Hello World");
}
END_TEST

START_TEST (str_ne)
{
   ck_assert_str_ne("Hello Check", "Hello World");
}
END_TEST

START_TEST (str_lt)
{
   ck_assert_str_lt("Hello Check", "Hello World");
}
END_TEST

START_TEST (str_le)
{
   ck_assert_str_le("Hello Vorld", "Hello World");
   ck_assert_str_le("Hello World", "Hello World");
}
END_TEST

START_TEST (str_gt)
{
   ck_assert_str_gt("Hello Xorld", "Hello World");
}
END_TEST

START_TEST (str_ge)
{
   ck_assert_str_ge("Hello World", "Hello World");
   ck_assert_str_ge("Hello Xorld", "Hello World");
}
END_TEST

Suite *create_string_assertions_suite(void)
{
   Suite *suite = suite_create("String assertions");
   TCase *eq_case = tcase_create("Equality");
   tcase_add_test(eq_case, str_eq);
   tcase_add_test(eq_case, str_ne);
   suite_add_tcase(suite, eq_case);
   
   TCase *ltgt_case = tcase_create("Less than/Greater than");
   tcase_add_test(ltgt_case, str_lt);
   tcase_add_test(ltgt_case, str_le);
   tcase_add_test(ltgt_case, str_gt);
   tcase_add_test(ltgt_case, str_ge);
   suite_add_tcase(suite, ltgt_case);
   return suite;
}
