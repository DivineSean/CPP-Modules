#include "AForm.hpp"

AForm::AForm():name("AForm Default_Name"), grade_sign(1), grade_exec(1)
{
    std::cout << "AForm Constructor Called" << std::endl;
    whether_is_signed = false;
}

AForm::AForm( const std::string name, const int grade_sign, const int grade_exec ):name(name), grade_sign(grade_sign), grade_exec(grade_exec)
{
    std::cout << "AForm " << name << " Constructor Called" << std::endl;
    whether_is_signed = false;
    if (grade_sign > 150 || grade_exec > 150)
        throw GradeTooLowException();
    else if (grade_sign < 1 || grade_exec < 1)
        throw GradeTooHighException();
}

AForm &AForm::operator=(const AForm &copy)
{
    if (this == &copy)
        return (*this);
    (std::string&)this->name = copy.name;
    (int&)this->grade_sign = copy.grade_sign;
    (int&)this->grade_exec = copy.grade_exec;
    this->whether_is_signed = copy.whether_is_signed;
    return (*this);
}

AForm::AForm( const AForm &copy ):name(copy.name), grade_sign(copy.grade_sign), grade_exec(copy.grade_exec)
{
    std::cout << "Copy " << name << " AForm Called" << std::endl;
    if (grade_sign > 150 || grade_exec > 150)
        throw GradeTooLowException();
    else if (grade_sign < 1 || grade_exec < 1)
        throw GradeTooHighException();
    *this = copy;
}

const char*         AForm::GradeTooHighException::what() const throw()
{
    return ("AForm Grade Too High Exception");
}

const char*         AForm::GradeTooLowException::what() const throw()
{
    return ("AForm Grade Too Low Exception");
}

const char*         AForm::AFormNotSignedException::what() const throw()
{
    return ("AForm Not Signed Before executing");
}

const               std::string AForm::getName() const
{
    return(name);
}

bool                AForm::getWhether_is_signed() const
{
    return(whether_is_signed);
}

int                 AForm::getGrade_sign() const
{
    return(grade_sign);
}

int                 AForm::getGrade_exec() const
{
    return(grade_exec);
}

bool                AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= grade_sign)
    {
        whether_is_signed = true;
        return (true);
    }
    return (false);
}

std::ostream        &operator<<(std::ostream &o, AForm &b)
{
    o << b.getName() << ", AForm grade require to sign it: " << b.getGrade_sign() << ", and grade require to execute it: " << b.getGrade_exec() << ", and whether sign status: " << b.getWhether_is_signed();
    return (o);
}

AForm::~AForm()
{
    std::cout << "AForm " << name << " Deconstructor called" << std::endl;
}