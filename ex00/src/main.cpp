#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    // Base Application
    {
        if (argc != 2) {
            std::cout << "Usage: ./a.out <literal>" << std::endl;
            return 1;
        }
        ScalarConverter::convert(argv[1]);
    }
    // Tests
    {
        ScalarConverter::convert("0");
        ScalarConverter::convert("42");
        ScalarConverter::convert("42.0f");
        ScalarConverter::convert("3.14");
        ScalarConverter::convert("a");
        ScalarConverter::convert("nan");
        ScalarConverter::convert("+inf");
        ScalarConverter::convert("-inf");
        ScalarConverter::convert("inff");
        ScalarConverter::convert("-inff");
        ScalarConverter::convert("+inff");
    }
    return 0;
}
