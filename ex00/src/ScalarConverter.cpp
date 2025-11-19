#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal)
{
    char c;
    int i;
    float f;
    double d;

    if (literal.length() == 1) {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    else {
        throw std::invalid_argument("[ScalarConverter::convert] Invalid literal");
    }

    if (std::isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;
}

