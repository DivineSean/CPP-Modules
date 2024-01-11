#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Default_ClapTrap")
{
    this->name = "Default DiamondTrap";
	this->Hit_Points = FragTrap::Hit_Points;
	this->Energy_Points = ScavTrap::Energy_Points;
	this->Attack_Damage = FragTrap::Attack_Damage;
	std::cout << "DiamondTrap " << this->name << " Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
    *this = copy;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name + "_ClapTrap")
{
    this->name = name;
	this->Hit_Points = FragTrap::Hit_Points;
	this->Energy_Points = ScavTrap::Energy_Points;
	this->Attack_Damage = FragTrap::Attack_Damage;
	std::cout << this->name << " Constructor DiamondTrap called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    std::cout << "DiamondTrap Assignation operator called" << std::endl;
	this->name = copy.name;
	this->Hit_Points = copy.Hit_Points;
	this->Energy_Points = copy.Energy_Points;
	this->Attack_Damage = copy.Attack_Damage;
	return *this;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
    std::cout << "I AM " << this->name << " From DiamondTrap. And This is My Base Name " << ClapTrap::name + "." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " Deconstructor called" << std::endl;
}