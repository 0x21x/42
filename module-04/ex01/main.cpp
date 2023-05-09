#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    const Animal *animalArray[10];
    const int    size = sizeof(animalArray) / sizeof(*animalArray);

    for (int i = 0; i < size / 2; i++)
        animalArray[i] = new Dog;

    for (int i = size / 2; i < size; i++)
        animalArray[i] = new Cat;

    for (int i = 0; i < size; i++)
        animalArray[i]->makeSound();

    for (int i = 0; i < size; i++)
        delete animalArray[i];

    return 0;
}