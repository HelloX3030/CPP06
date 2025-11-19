#include "ScalarConverter.hpp"

void test(const std::string& literal) {
    std::cout << "=======================================================" << std::endl;
    try
    {
        std::cout << "Testing literal: " << literal << std::endl;
        ScalarConverter::convert(literal);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main(int argc, char **argv)
{
    // Base Application
    {
        if (argc != 2) {
            std::cout << "Usage: ./a.out <literal>" << std::endl;
            return 1;
        }
        try
        {
            ScalarConverter::convert(argv[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    // Tests
// {
//     // Original tests
//     test("0");
//     test("42");
//     test("42.0f");
//     test("3.14");
//     test("a");
//     test("nan");
//     test("nanf");
//     test("+inf");
//     test("-inf");
//     test("inff");
//     test("-inff");
//     test("+inff");

//     // Integer boundary values
//     test("1");
//     test("-1");
//     test("2147483647");      // INT_MAX
//     test("-2147483648");     // INT_MIN
//     test("9999999999");      // int overflow

//     // Normal floating-point numbers
//     test("42.0");
//     test("1.23456789f");
//     test("123456.789");
//     test("3.141592653589793");   // long double precision region

//     // Scientific notation
//     test("1e10");
//     test("1e-10");
//     test("1e38f");                // near float overflow
//     test("1e309");                // overflow to inf

//     // Additional IEEE variants
//     test("NaN");
//     test("NAN");
//     test("-nan");
//     test("inf");
//     test("Infinity");             // usually invalid — confirm behavior

//     // Character variations
//     test("~");
//     test(" ");                    // space char
//     test("\t");                   // non-displayable tab
//     test("\x7F");                 // DEL character

//     // Malformed / invalid inputs
//     test("");
//     test("   ");
//     test("--1");
//     test("++1");
//     test("4.2.1");
//     test("abc");
//     test("123f4");
//     test("12f3");
//     test("nan nan");
//     test("inff2");
//     test("3.14foo");

//     // With whitespace
//     test("   42");
//     test("42   ");
//     test("   3.14f   ");

//     // Sign-only
//     test("+");
//     test("-");
//     test("+f");
//     test("-f");

//     // Edge-case numeric forms
//     test(".5");
//     test("5.");
//     test(".5f");
//     test("5.f");
// }
    return 0;
}
