#include <check.h>
#include <stdlib.h>
#include "tests.h"

int main(void)
{
   int number_failed;
   SRunner *runner = srunner_create(create_integer_assertions_suite());
   srunner_add_suite(runner, create_string_assertions_suite());
   srunner_add_suite(runner, create_general_functionality_suite());
   srunner_run_all(runner, CK_NORMAL);
   number_failed = srunner_ntests_failed(runner);
   srunner_free(runner);
   return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
