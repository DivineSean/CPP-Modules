#pragma once
#include "Bureaucrat.hpp"
#include <iostream>
class Bureaucrat;
class Form
{
    private:
        const std::string name;
        bool  whether_is_signed;
        const int grade_sign;
        const int grade_exec;
    public:
        Form();
        Form( const std::string name, const int grade_sign, const int grade_exec );
        Form( const Form &copy );
        class GradeTooHighException : public std::exception
        {
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw();
        };
        Form &operator=(const Form &copy);
        const   std::string getName() const;
        bool                getWhether_is_signed() const;
        int                 getGrade_sign() const;
        int                 getGrade_exec() const;
        bool                beSigned(const Bureaucrat &b);
        ~Form();
};
std::ostream &operator<<(std::ostream &o, Form &b);