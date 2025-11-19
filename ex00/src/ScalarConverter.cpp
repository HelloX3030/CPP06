#include "ScalarConverter.hpp"

static void print(char c, int i, float f, double d) {
    if (std::isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;
}

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
        print(c, i, f, d);
        return;
    }
    try
    {
        i = std::stoi(literal);
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
        print(c, i, f, d);
        return;
    } catch(const std::exception& e) {}

    try
    {
        f = std::stof(literal);
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
        print(c, i, f, d);
        return;
    }
    catch(const std::exception& e) {}

    try
    {
        d = std::stod(literal);
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
        print(c, i, f, d);
        return;
    }
    catch(const std::exception& e) {}
    
    // Base Case
    throw std::invalid_argument("[ScalarConverter::convert] Invalid literal");
}
