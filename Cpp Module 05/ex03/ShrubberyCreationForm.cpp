#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
    this->target = "ShrubberyCreationForm Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string t): AForm("ShrubberyCreationForm", 145, 137)
{
    this->target = t;
    std::cout << "ShrubberyCreationForm Constructor for target " << this->getTarget() << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy)
{
    this->target = copy.getTarget();
	std::cout << "ShrubberyCreationForm Copy Constructor called." << std::endl; 
    AForm::operator=(copy);
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const  ShrubberyCreationForm &copy)
{
    if (this == &copy)
        return (*this);
    target = copy.getTarget(); 
    return (*this);
}

const std::string ShrubberyCreationForm::getTarget() const
{
    return (this->target);
}

const char* ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
    return ("[ERROR]:: File Fail To Open.");
}

void  ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGrade_exec())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getWhether_is_signed() == false)
		throw (AForm::AFormNotSignedException());
	else
    {
        std::ofstream file;
        std::string s = this->target + "_shrubbery";
        file.open(s.c_str());
        if (!file.is_open())
        {
            std::cout << "File Failed To Creat" << std::endl;
            throw FileNotOpenException();
        }
        file << "          .     .  .      +     .      .          .          .\n";
        file << ".      .       .      .     *       .           .             .\n";
        file << ".         .      .         ***            .      .      .     .\n";
        file << ".       .      .   *:. .:@@`@@:.`.:*  .      .                .\n";
        file << ".           .      .  @@@@`***`@@@@  .           .            .\n";
        file << ".        .      *:.    .:*`***`*:.    .:*   .        .        .\n";
        file << ".   .              @@@@@@@@@`@@@@@@@@@         .        .     .\n";
        file << ".         .     *:.   @@@@`***`@@@@   .:*    .       .        .\n";
        file << ".      .     .   @@@@@@@``@@`@@``@@@@@@@                   .  .\n";
        file << ".                 . @@`@@@@@`@@@@@ @@            .      .     .\n";
        file << ".     .    *:. ...  .:@@`***`***`@@:.  ... .:*      .         .\n";
        file << ".       .      @@@@@@@`@@`@@@@@`@@`@@@@@@@       .     .      .\n";
        file << ".    .    .      @@@@@``@@@@@@@``@@@@@     .      .           .\n";
        file << ".             .            111           .     .              .\n";
        file << ".        .         .   .   111     .        .       .         .\n";
        file << "........................11AAA11................................\n";
        file.close();
        std::cout << "File Has Been Created Succefully" <<std::endl;
    }
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm &b)
{
	o << "ShrubberyCreationForm " << b.getName() << " stats are ->" << " grade Exec : " << b.getGrade_exec() << " grade sign : " << b.getGrade_sign() << " if signed : " << b.getWhether_is_signed() << " target : " << b.getTarget();
    return (o);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Deconstructor for target " << this->getTarget() << " called" << std::endl;
}