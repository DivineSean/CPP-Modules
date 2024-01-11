#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap Default Constructor called" << std::endl;
	this->Hit_Points = 100;
	this->Energy_Points = 100;
	this->Attack_Damage = 30;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	this->name = copy.name;
	this->Hit_Points = copy.Hit_Points;
	this->Energy_Points = copy.Energy_Points;
	this->Attack_Damage = copy.Attack_Damage;
	return *this;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << this->name << " Constructor FragTrap called" << std::endl;
	this->Hit_Points = 100;
	this->Energy_Points = 100;
	this->Attack_Damage = 30;
}

void	FragTrap::highFivesGuys(void)
{
    std::cout << this->name << " High Five." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << this->name << " Deconstructor FragTrap called" << std::endl;
}