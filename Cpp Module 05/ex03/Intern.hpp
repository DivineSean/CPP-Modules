#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		std::string name;
	public:
		Intern();
		Intern(std::string n);
		Intern(Intern const &copy);
		Intern &operator=(Intern const &copy);
		class FormDoesNotExistException : public std::exception
		{
			virtual const char* what() const throw();
		};
        std::string getName() const;
		AForm *makeForm(std::string form_name, std::string form_target);
		~Intern();
};