#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default Inter constructor called" << std::endl;
}

Intern::Intern(std::string n) : name(n)
{
	std::cout << "Intern Constructor called" << std::endl;
}

Intern::Intern(Intern const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

std::string Intern::getName() const
{
    return(this->name);
}

Intern &Intern::operator=(Intern const &copy)
{
	if (this == &copy)
	    return (*this);
	this->name = copy.getName();
    return (*this);
}

const char* Intern::FormDoesNotExistException::what() const throw()
{
	return ("Form does not exist");
}

AForm *Intern::makeForm(std::string Form_name, std::string Form_target)
{
	int i = 0;
	AForm *form;

	std::string Forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (i = 0; i < 3; i++)
    {	
		if (Forms[i] == Form_name)
			break;
	}
	switch (i)
	{
		case 0:
			form = new ShrubberyCreationForm(Form_target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		case 1:
			form = new RobotomyRequestForm(Form_target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		case 2:
			form = new PresidentialPardonForm(Form_target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		default:
			throw (FormDoesNotExistException());
	}
	throw (FormDoesNotExistException());
	return NULL;
}

Intern::~Intern()
{
	std::cout << "Intern Deconstructor called" << std::endl;
}