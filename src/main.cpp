#include "Pet.hpp"
#include <pybind11/pybind11.h>

namespace py = pybind11;

void reproducer() {
  py::object dog_class = py::module_::import("cmake_example").attr("Dog");

  py::object dog = dog_class("timmy");

  auto dog_cpp = dog.cast<Pet>();

  dog_cpp.bark();
}

#include "Dog.hpp"

PYBIND11_MODULE(cmake_example, m) {

  py::class_<Pet>(m, "Pet")
      .def(py::init<const std::string &>())
      .def_readwrite("name", &Pet::name)
      .def("bark", &Pet::bark);

  py::class_<Dog, Pet>(m, "Dog")
      .def(py::init<const std::string &>())
      .def("bark", &Dog::bark);

  m.def("reproducer", &reproducer);
}
