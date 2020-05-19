#include <ctest.h>
#include <main.h>

CTEST(numbers_suite, incorrect_entry)
{
    double a = 0, b = -1, c = 10;
    double p = a + b + c;
    const int result = area_t(a, b, c, p);
    const int expected = -2;
    ASSERT_EQUAL(expected, result);
}

CTEST(numbers_suite, incorrect_entry_1)
{
    double a = 0, b = -1, c = 10;
    const int result = perimeter_t(a, b, c);
    const int expected = -2;
    ASSERT_EQUAL(expected, result);
}

CTEST(number_suite, incorrect_entry_2)
{
    double r = -1;
    const int result = area(r);
    const int expected = -2;
    ASSERT_EQUAL(expected, result);
}

CTEST(number_suite, incorrect_entry_3)
{
    double r = -1;
    const int result = perimeter(r);
    const int expected = -2;
    ASSERT_EQUAL(expected, result);
}

CTEST(numbers_suite, incorrect_entry_4)
{
    double a = 0, b = -1, c = 10;
    const int result = check_to_existence_t(a, b, c);
    const int expected = -2;
    ASSERT_EQUAL(expected, result);
}

CTEST(numbers_suite, incorrect_entry_5)
{
    double a = 1, b = 2, c = 334;
    const int result = check_to_existence_t(a, b, c);
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}
