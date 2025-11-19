#include "ScalarConverter.hpp"

// Detect NaN or Inf for either type
static bool is_special(double d) {
    return std::isnan(d) || std::isinf(d);
}

// Correct “after decimal” logic: use DOUBLE, not float
static bool has_after_dot(double d) {
    if (!std::isfinite(d))
        return false;
    double intpart;
    return std::modf(d, &intpart) != 0.0;
}

// Range checks
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

// Correct float overflow check: casting must not change finite→inf
static bool can_cast_to_float(double d) {
    float f2 = static_cast<float>(d);
    if (std::isfinite(d) && !std::isfinite(f2))
        return false; // overflow occurred
    return true;
}

static void print(char c, int i, float f, double d) {
    bool special = is_special(d);          // use canonical value
    bool after_dot = has_after_dot(d);     // use canonical value

    // CHAR
    if (!in_char_range(d) || special) {
        std::cout << "char: impossible" << std::endl;
    } else if (std::isprint(static_cast<unsigned char>(c))) {
        std::cout << "char: " << c << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }

    // INT
    if (!special && in_int_range(d))
        std::cout << "int: " << i << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    // FLOAT
    std::cout << "float: ";
    if (!can_cast_to_float(d))
        std::cout << "impossible";
    else if (!after_dot && !special)
        std::cout << f << ".0f";
    else
        std::cout << std::setprecision(std::numeric_limits<float>::max_digits10) << f << "f";
    std::cout << std::endl;

    // DOUBLE — always representable, even inf/nan
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

    // CHAR literal
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
        print(c, i, f, d);
        return;
    }

    // DOUBLE
    try {
        d = std::stod(literal);               // may return inf silently
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);           // may overflow to inf
        print(c, i, f, d);
        return;
    } catch (...) {}

    // FLOAT
    try {
        f = std::stof(literal);
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
        print(c, i, f, d);
        return;
    } catch (...) {}

    // INT
    try {
        i = std::stoi(literal);
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
        print(c, i, f, d);
        return;
    } catch (...) {}

    throw std::invalid_argument("[ScalarConverter::convert] Invalid literal");
}
