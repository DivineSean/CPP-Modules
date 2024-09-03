#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("RobotomyRequestForm Default")
{
    std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm Constructor for target " << this->getTarget() << " called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy): AForm(copy), target(copy.getTarget())
{
	std::cout << "RobotomyRequestForm Copy Constructor called." << std::endl;
    AForm::operator=(copy);
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    if (this == &copy)
        return (*this);
    target = copy.getTarget(); 
    return (*this);
}

const std::string RobotomyRequestForm::getTarget() const
{
    return (this->target);
}

void  RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGrade_exec())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getWhether_is_signed() == false)
		throw (AForm::AFormNotSignedException());
	else
    {
        srand(time(NULL)); 
      	if (rand() % 2)
            std::cout << this->target << " has been robotomized successfully" << std::endl;
        else
            std::cout << this->target << " has not been robotomized successfully (FAIL)" << std::endl;  
    }
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm &b)
{
	o << "RobotomyRequestForm " << b.getName() << " stats are ->" << " grade Exec : " << b.getGrade_exec() << " grade sign : " << b.getGrade_sign() << " if signed : " << b.getWhether_is_signed() << " target : " << b.getTarget();
    return (o);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Deconstructor for target " << this->getTarget() << " called" << std::endl;
}