#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int main()
{
	AForm *A = NULL;
	std::cout << "-- ShrubberyCreationForm TEST --" << std::endl;
	try
	{
		Intern someRandomIntern;
		Bureaucrat b("Bender", 1);
		A = someRandomIntern.makeForm("shrubbery creation", "Bender");
		A->beSigned(b);
		A->execute(b);
		delete A;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		delete A;
	}
	std::cout << "-- RobotomyRequestForm TEST --" << std::endl;
	try
	{
		AForm *A = NULL;
		Intern someRandomIntern;
		Bureaucrat b("Bender", 1);
		A = someRandomIntern.makeForm("robotomy request", "Bender");
		A->beSigned(b);
		A->execute(b);
		delete A;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		delete A;
	}
	std::cout << "-- PresidentialPardonForm TEST --" << std::endl;
	try
	{
		AForm *A = NULL;
		Intern someRandomIntern;
		Bureaucrat b("Bender", 1);
		A = someRandomIntern.makeForm("presidential pardon", "Bender");
		A->beSigned(b);
		A->execute(b);
		delete A;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		delete A;
	}
	return 0;	
}