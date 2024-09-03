#pragma once
#include "AForm.hpp"
#include <iostream>

class AForm;
class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat( const std::string name, int grade );
        Bureaucrat( const Bureaucrat &copy );
        class GradeTooHighException : public std::exception
        {
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw();
        };
        Bureaucrat &operator=(const Bureaucrat &copy);
        const   std::string getName() const;
        int     getGrade() const;
        void    increment();
        void    decrement();
        void    signAForm(AForm &form);
        void    executeForm(AForm &form) const;
        ~Bureaucrat();
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &b);