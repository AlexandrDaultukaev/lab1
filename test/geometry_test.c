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

CTEST(numbers_suite, incorrect_entry1)
{
    double a = 0, b = -1, c = 10;
    const int result = perimeter_t(a, b, c);
    const int expected = -2;
    ASSERT_EQUAL(expected, result);
}
