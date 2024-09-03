#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("PresidentialPardonForm Default")
{
    std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm Constructor for target " << this->getTarget() << " called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy): AForm(copy), target(copy.getTarget())
{
	std::cout << "PresidentialPardonForm Copy Constructor called." << std::endl;
    AForm::operator=(copy);
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    if (this == &copy)
        return (*this);
    target = copy.getTarget();
    return (*this);
}

const std::string PresidentialPardonForm::getTarget() const
{
    return (this->target);
}

void  PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGrade_exec())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getWhether_is_signed() == false)
		throw (AForm::AFormNotSignedException());
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm &b)
{
	o << "PresidentialPardonForm " << b.getName() << " stats are ->" << " grade Exec : " << b.getGrade_exec() << " grade sign : " << b.getGrade_sign() << " if signed : " << b.getWhether_is_signed() << " target : " << b.getTarget();
    return (o);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Deconstructor for target " << this->getTarget() << " called" << std::endl;
}