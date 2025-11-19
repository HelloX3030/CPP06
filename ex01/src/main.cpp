#include "Data.hpp"
#include "Serializer.hpp"

#include <iostream>

int main(void) {
    Data data(3, 4);
    std::cout << "Before Serialize: " << data.toString() << std::endl;
    uintptr_t raw = Serializer::serialize(&data);
    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "After Deserialize: " << deserializedData->toString() << std::endl;
    return 0;
}
