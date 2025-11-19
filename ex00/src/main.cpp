#include "ScalarConverter.hpp"

void test(const std::string& literal) {
    std::cout << "=======================================================" << std::endl;
    try
    {
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
    {
        test("0");
        test("42");
        test("42.0f");
        test("3.14");
        test("a");
        test("nan");
        test("+inf");
        test("-inf");
        test("inff");
        test("-inff");
        test("+inff");
    }
    return 0;
}
