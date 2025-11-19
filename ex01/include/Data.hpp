#pragma once

#include <string>

class Data
{
private:
    int x;
    int y;
    int magnitude;

    void updateMagnitude();

public:
    // Constructors
    Data();
    Data(const Data& other);
    Data& operator=(const Data& other);
    ~Data();

    // Special Constructors
    Data(int x, int y);

    // Functions
    std::string toString() const;
};
