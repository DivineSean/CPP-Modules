#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("Default_Name"), grade(1)
{
    std::cout << "Bureaucrat Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string name, int grade ): name(name)
{
    std::cout << "Bureaucrat Constructor Called" << std::endl;
    this->grade = grade;
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this == &copy)
        return (*this);
    (std::string&)this->name = copy.name;
    this->grade = copy.grade;
    return (*this);
}

Bureaucrat::Bureaucrat( const Bureaucrat &copy )
{
    std::cout << "Copy " << copy.getName() << " Bureaucrat Called" << std::endl;
    if (copy.getGrade() > 150)
        throw GradeTooLowException();
    else if (copy.getGrade() < 1)
        throw GradeTooHighException();
    *this = copy;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade Too High Exception");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low Exception");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &b)
{
    o << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (o);
}

const std::string Bureaucrat::getName() const
{
    return(name);
}

int Bureaucrat::getGrade() const
{
    return(grade);
}

void    Bureaucrat::decrement()
{
    this->grade += 1;
    if (this->grade > 150)
        throw GradeTooLowException();
}

void    Bureaucrat::increment()
{
    this->grade -= 1;
    if (this->grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Deconstructor Called" << std::endl;
}