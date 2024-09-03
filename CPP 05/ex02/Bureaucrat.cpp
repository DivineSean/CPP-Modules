#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("Bureaucrat Default_Name"), grade(1)
{
    std::cout << "Bureaucrat Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string name, int grade ): name(name)
{
    std::cout << "Bureaucrat " << name << " Constructor Called" << std::endl;
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
    return ("Bureaucrat Grade Too High Exception");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat Grade Too Low Exception");
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

void Bureaucrat::signAForm(AForm &form)
{
    if (form.beSigned(*this))
        std::cout << this->name << " signed " << form.getName() << std::endl;
    else
        std::cout << this->name << " couldn't sign " << form.getName() << " because the grade is too low" << std::endl; 
}

void	Bureaucrat::executeForm(AForm &form) const
{
	if (form.getWhether_is_signed())
		std::cout << this->name << " executes " << form.getName() << std::endl;
	else
		std::cerr << this->name << " couldn't execute " << form.getName() << " because grade is too low." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << name << " Deconstructor Called" << std::endl;
}