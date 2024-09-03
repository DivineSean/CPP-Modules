#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

class AForm;
class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(RobotomyRequestForm &copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
        const std::string getTarget() const;
        void  execute(Bureaucrat const & executor) const;
        ~RobotomyRequestForm();
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm &b);