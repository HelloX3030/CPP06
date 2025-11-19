#pragma once

#include <cstdint>

class Data;

class Serializer
{
private:

public:
        Serializer() = delete;
        Serializer(const Serializer& other) = delete;
        Serializer& operator=(const Serializer& other) = delete;
        ~Serializer() = delete;

        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};
