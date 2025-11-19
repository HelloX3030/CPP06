#pragma once

#include <string>
#include <iostream>

class ScalarConverter
{
private:

public:
        ScalarConverter() = delete;
        ScalarConverter(const ScalarConverter& other) = delete;
        ScalarConverter& operator=(const ScalarConverter& other) = delete;
        ~ScalarConverter() = delete;

        // Functions
        static void convert(const std::string& literal);
};
