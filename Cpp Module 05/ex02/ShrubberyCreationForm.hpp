#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class AForm;
class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string t);
        ShrubberyCreationForm(ShrubberyCreationForm const &copy);
        class FileNotOpenException : public std::exception
        {
            virtual const char* what() const throw();
        };
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
        const std::string getTarget() const;
        void  execute(Bureaucrat const &executor) const;
        ~ShrubberyCreationForm();
};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm &b);