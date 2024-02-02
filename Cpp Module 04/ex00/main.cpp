#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrong_animal = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();

	std::cout << "Dog Type : " << dog->getType() << std::endl;
	std::cout << "Cat Type : " << cat->getType() << std::endl;
    std::cout << "wrong_cat Type : " << wrong_cat->getType() << std::endl;
    std::cout << "wrong_animal Type : " << wrong_animal->getType() << std::endl;
	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	wrong_cat->makeSound();
	wrong_animal->makeSound();

	delete animal;
	delete dog;
	delete cat;
	delete wrong_cat;
	delete wrong_animal;
}