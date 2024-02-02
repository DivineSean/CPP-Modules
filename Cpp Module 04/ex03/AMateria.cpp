#include "AMateria.hpp"

AMateria::AMateria(): type("Defualt")
{
    std::cout << "Default Abstract Materia Created" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << type << " Abstract Materia construcor called" << std::endl;
}

AMateria::AMateria(AMateria const &copy) : type(copy.type)
{
	std::cout << "Abstract Materia Copy Constructor Called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return(this->type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "Abstract Materia Used On [" << target.getName() + ']' << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Abstract Materia destroyed" << std::endl;
}