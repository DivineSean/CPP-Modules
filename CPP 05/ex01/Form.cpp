#include "Form.hpp"

Form::Form():name("Form Default_Name"), grade_sign(1), grade_exec(1)
{
    std::cout << "Form Constructor Called" << std::endl;
    whether_is_signed = false;
}

Form::Form( const std::string name, const int grade_sign, const int grade_exec ):name(name), grade_sign(grade_sign), grade_exec(grade_exec)
{
    std::cout << "Form " << name << " Constructor Called" << std::endl;
    whether_is_signed = false;
    if (grade_sign > 150 || grade_exec > 150)
        throw GradeTooLowException();
    else if (grade_sign < 1 || grade_exec < 1)
        throw GradeTooHighException();
}

Form &Form::operator=(const Form &copy)
{
    if (this == &copy)
        return (*this);
    (std::string&)this->name = copy.name;
    (int&)this->grade_sign = copy.grade_sign;
    (int&)this->grade_exec = copy.grade_exec;
    this->whether_is_signed = copy.whether_is_signed;
    return (*this);
}

Form::Form( const Form &copy ):name(copy.name), grade_sign(copy.grade_sign), grade_exec(copy.grade_exec)
{
    std::cout << "Copy " << name << " Form Called" << std::endl;
    if (grade_sign > 150 || grade_exec > 150)
        throw GradeTooLowException();
    else if (grade_sign < 1 || grade_exec < 1)
        throw GradeTooHighException();
    *this = copy;
}

const char*         Form::GradeTooHighException::what() const throw()
{
    return ("Form Grade Too High Exception");
}

const char*         Form::GradeTooLowException::what() const throw()
{
    return ("Form Grade Too Low Exception");
}

const               std::string Form::getName() const
{
    return(name);
}

bool                Form::getWhether_is_signed() const
{
    return(whether_is_signed);
}

int           Form::getGrade_sign() const
{
    return(grade_sign);
}

int           Form::getGrade_exec() const
{
    return(grade_exec);
}

bool                Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= grade_sign)
        return (true);
    return (false);
}

std::ostream        &operator<<(std::ostream &o, Form &b)
{
    o << b.getName() << ", Form grade require to sign it: " << b.getGrade_sign() << ", and grade require to execute it: " << b.getGrade_exec() << ", and whether sign status: " << b.getWhether_is_signed();
    return (o);
}

Form::~Form()
{
    std::cout << "Form " << name << " Deconstructor called" << std::endl;
}