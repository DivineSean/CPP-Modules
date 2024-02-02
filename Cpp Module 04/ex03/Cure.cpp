#include "Cure.hpp"

Cure::Cure() : type("cure")
{
	std::cout << this->type << " Created" << std::endl;
}

Cure::Cure(Cure const &copy) : type(copy.getType())
{
	std::cout << this->type << " Copy Constructure Called" << std::endl;
}

Cure &Cure::operator=(const Cure &copy)
{
	std::cout << "Assignement Operator Called For " << type << std::endl;
	this->type = copy.type;
	return (*this);
}

std::string const &Cure::getType() const
{
	return (this->type);
}

Cure *Cure::clone() const
{
	Cure	*p = new Cure;
	return (p);
}

void Cure::use(ICharacter &target)
{
	std::cout << " Using cure Potion To Heal " << target.getName() << std::endl;
}

Cure::~Cure()
{
	std::cout << this->type << " Destroyed" << std::endl;
}