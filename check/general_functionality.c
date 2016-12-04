#include <check.h>
#include <stdbool.h>
/*
 * Demonstrates the general assertion, the pointers comparison assertions, 
 * and abort functions.
 */
START_TEST (general_assertion)
{
   ck_assert(true == true);
   ck_assert(1 == 2 - 1);
   ck_assert(strcmp("hello", "Hello") > 0);
}
END_TEST

START_TEST (pointer_equality)
{
   char *p1 = "Hello World";
   char *p2 = p1;
   ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST (pointer_inequality)
{
   char *p1 = "Hello World";
   char *p2 = p1;
   p2++;
   ck_assert_ptr_ne(p1, p2);
}
END_TEST


START_TEST (general_assertion_with_message)
{
   ck_assert_msg(true == 0, "True is not 0");
}
END_TEST

START_TEST (abort_test)
{
   ck_abort();
}
END_TEST

START_TEST (abort_test_with_message)
{
   ck_abort_msg("I fail, and tell you that I do");
}
END_TEST


Suite *create_general_functionality_suite(void)
{
   Suite *suite = suite_create("General functionality");
   TCase *assertions_case = tcase_create("General assertions");
   tcase_add_test(assertions_case, general_assertion);
   tcase_add_test(assertions_case, pointer_equality);
   tcase_add_test(assertions_case, pointer_inequality);
   suite_add_tcase(suite, assertions_case);
      
   TCase *failures_case = tcase_create("Failing tests");
   tcase_add_test(failures_case, general_assertion_with_message);
   tcase_add_test(failures_case, abort_test);
   tcase_add_test(failures_case, abort_test_with_message);
   suite_add_tcase(suite, failures_case);
   return suite;
}
