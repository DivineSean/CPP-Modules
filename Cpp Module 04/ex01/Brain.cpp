#include "Brain.hpp"

Brain::Brain()
{
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Meals Meals";
	std::cout << "Brain Constructor Called" << std::endl;
}

Brain::Brain(Brain &copy)
{
	std::string *s = copy.getIdeas();
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = s[i];
	std::cout << "Brain copy constructed called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	return (*this);
}

std::string *Brain::getIdeas() const
{
	return (this->ideas);
}

Brain::~Brain()
{
	delete [] (this->ideas);
	std::cout << "Brain Deconstructor called" << std::endl;
}