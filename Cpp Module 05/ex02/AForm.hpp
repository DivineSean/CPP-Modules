#pragma once
#include "Bureaucrat.hpp"
#include <iostream>
class Bureaucrat;
class AForm
{
    private:
        const std::string name;
        bool  whether_is_signed;
        const int grade_sign;
        const int grade_exec;
    public:
        AForm();
        AForm( const std::string name, const int grade_sign, const int grade_exec );
        AForm( const AForm &copy );
        class GradeTooHighException : public std::exception
        {
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw();
        };
        class AFormNotSignedException : public std::exception
        {
            virtual const char* what() const throw();
        };
        AForm &operator=(const AForm &copy);
        virtual void        execute(Bureaucrat const & executor) const = 0;
        const               std::string getName() const;
        bool                getWhether_is_signed() const;
        int                 getGrade_sign() const;
        int                 getGrade_exec() const;
        bool                beSigned(const Bureaucrat &b);
        virtual             ~AForm();
};
std::ostream &operator<<(std::ostream &o, AForm &b);