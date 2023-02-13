#pragma once

#include <stdexcept>
#include <string>

struct Pet {
    Pet(const std::string &name) : name(name) { }
    virtual std::string bark() const {
        throw std::runtime_error("Not implemented");
    }
    std::string name;
};

