#include "Base.hpp"

int main(void) {
    Base *base = generate();
    std::cout << "Identifying by pointer:" << std::endl;
    identify(base);
    Base &ref = *base;
    std::cout << "Identifying by reference:" << std::endl;
    identify(ref);
    delete base;
}
