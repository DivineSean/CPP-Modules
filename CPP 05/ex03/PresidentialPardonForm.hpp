#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;
class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(PresidentialPardonForm &copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
        const std::string getTarget() const;
        void  execute(Bureaucrat const & executor) const;
        ~PresidentialPardonForm();
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm &b);