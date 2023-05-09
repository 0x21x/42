#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    const Animal* animal = new Dog();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    WrongAnimal* wrongCat = new WrongCat;
    std::cout << "Animal type : " << animal->getType() << std::endl;
    std::cout << "Dog type : " << dog->getType() << std::endl;
    std::cout << "Cat type : " << cat->getType() << std::endl;
    std::cout << "Wrong Cat type : " << wrongCat->getType() << std::endl;
    animal->makeSound();
    dog->makeSound();
    cat->makeSound();
    wrongCat->makeSound();
    delete animal;
    delete dog;
    delete cat;
    delete wrongCat;
    return 0;
}