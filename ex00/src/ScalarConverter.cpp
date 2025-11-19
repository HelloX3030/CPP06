#include "ScalarConverter.hpp"

static void print(char c, int i, float f, double d) {
    // Char
    if (std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    // Int
    std::cout << "int: " << i << std::endl;

    // Float
    std::cout << "float: ";
    if (std::floor(f) == f && std::isfinite(f)) // whole number
        std::cout << f << ".0f";
    else
        std::cout << std::defaultfloat << f << "f";
    std::cout << std::endl;

    // Double
    std::cout << "double: ";
    if (std::floor(d) == d && std::isfinite(d))
        std::cout << d << ".0";
    else
        std::cout << std::defaultfloat << d;
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
    char c;
    int i;
    float f;
    double d;

    // Char
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
        print(c, i, f, d);
        return;
    }

    // Double
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

    // Float
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

    // Int
    try
    {
        i = std::stoi(literal);
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
        print(c, i, f, d);
        return;
    } catch(const std::exception& e) {}
    
    // Base Case
    throw std::invalid_argument("[ScalarConverter::convert] Invalid literal");
}
