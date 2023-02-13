from cmake_example import Pet, Dog, reproducer

assert issubclass(Dog, Pet)

dog = Dog("steve")

print(dog.bark())

reproducer()
