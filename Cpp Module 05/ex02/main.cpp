#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int main()
{
	std::cout << "-- ShrubberyCreationForm TEST --" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Bureaucrat", 1);
		ShrubberyCreationForm form("Home");
		// form.beSigned(bureaucrat);
		form.execute(bureaucrat);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// std::cout << "-- RobotomyRequestForm TEST --" << std::endl;
	// try
	// {
	// 	Bureaucrat bureaucrat("Bureaucrat", 5);
	// 	RobotomyRequestForm form("Home");
	// 	form.beSigned(bureaucrat);
	// 	form.execute(bureaucrat);
	// }
	// catch(std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << "-- PresidentialPardonForm TEST --" << std::endl;
	// try
	// {
	// 	Bureaucrat bureaucrat("Bureaucrat", 1);
	// 	PresidentialPardonForm form("Home");
	// 	form.beSigned(bureaucrat);
	// 	form.execute(bureaucrat);
	// }
	// catch(std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	return 0;	
}