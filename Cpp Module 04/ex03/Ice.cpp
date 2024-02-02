#include "Ice.hpp"

Ice::Ice() : type("ice")
{
	std::cout << this->type << " Created" << std::endl;
}

Ice::Ice(Ice const &copy) : type(copy.getType())
{
	std::cout << this->type << " Copy Constructure Called" << std::endl;
}

Ice &Ice::operator=(const Ice &copy)
{
	std::cout << "Assignement Operator Called For " << type << std::endl;
	this->type = copy.type;
	return (*this);
}

std::string const &Ice::getType() const
{
	return (this->type);
}

Ice *Ice::clone() const
{
	Ice	*p = new Ice;
	return (p);
}

void Ice::use(ICharacter& target)
{
    std::cout << " Using ice Bolt To Shoot " << target.getName() << std::endl;
}

Ice::~Ice()
{
	std::cout << this->type << " Destroyed" << std::endl;
}