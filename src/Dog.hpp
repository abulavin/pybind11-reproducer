#pragma once

#include <string>
#include "Pet.hpp"

struct Dog : Pet {
    Dog(const std::string &name) : Pet(name) { }
    std::string bark() const override  { return "woof!"; }
};
