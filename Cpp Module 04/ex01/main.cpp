#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	delete j;
	delete i;

	system("leaks World_On_Fire");
	return 0;
}