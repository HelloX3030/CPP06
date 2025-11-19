#include "ScalarConverter.hpp"

static bool is_special(float f, double d) {
    return (std::isnan(f) || std::isnan(d) || std::isinf(f) || std::isinf(d));
}

static bool has_after_dot(double d) {
    if (!std::isfinite(d))
        return false;
    double intpart;
    return std::modf(d, &intpart) != 0.0;
}

static bool in_char_range(double d) {
    return std::isfinite(d) &&
           d >= std::numeric_limits<char>::min() &&
           d <= std::numeric_limits<char>::max();
}

static bool in_int_range(double d) {
    return std::isfinite(d) &&
           d >= std::numeric_limits<int>::min() &&
           d <= std::numeric_limits<int>::max();
}

static bool in_float_range(double d) {
    return std::isfinite(d) && 
           d >= -std::numeric_limits<float>::max() &&
           d <=  std::numeric_limits<float>::max();
}

static void print(char c, int i, float f, double d) {
    bool special = is_special(f, d);
    bool after_dot = has_after_dot(f);

    // Char
    if (special || !in_char_range(d))
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    // Int
    if (!special && in_int_range(d))
        std::cout << "int: " << i << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    // Float
    std::cout << "float: ";
    if (!in_float_range(d))
        std::cout << "impossible";
    else if (!after_dot && !special)
        std::cout << f << ".0f";
    else
        std::cout << std::setprecision(std::numeric_limits<float>::max_digits10) << f << "f";
    std::cout << std::endl;

    // Double
    std::cout << "double: ";
    if (!after_dot && !special)
        std::cout << d << ".0";
    else
        std::cout << std::setprecision(std::numeric_limits<double>::max_digits10) << d;
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
