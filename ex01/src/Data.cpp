#include "Data.hpp"
#include <cmath>
#include <sstream>

void Data::updateMagnitude() {
    magnitude = static_cast<int>(std::round(std::sqrt(x * x + y * y)));
}

Data::Data() : x(0), y(0), magnitude(0) {}

Data::Data(const Data& other) : x(other.x), y(other.y), magnitude(other.magnitude) {}

Data& Data::operator=(const Data& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        magnitude = other.magnitude;
    }
    return *this;
}

Data::~Data() {}

Data::Data(int xVal, int yVal) : x(xVal), y(yVal) {
    updateMagnitude();
}

std::string Data::toString() const {
    std::ostringstream oss;
    oss << "Data(x=" << x << ", y=" << y << ", magnitude=" << magnitude << ")";
    return oss.str();
}
