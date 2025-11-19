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

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
