#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, 2);

    int r = dist(gen);
    if (r == 0) return new A();
    else if (r == 1) return new B();
    else return new C();
}


void identify(Base* p) {

}

void identify(Base& p) {

}
