#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	this->Hit_Points = 100;
	this->Energy_Points = 50;
	this->Attack_Damage = 20;
	this->guard_Gate = false;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
	this->guard_Gate = copy.guard_Gate;
}

void    ScavTrap::attack( const std::string &target )
{
    if (this->Hit_Points == 0)
        std::cout << "ScavTrap Cant Attack." << name << " is DEAD!" << std::endl;
    else if (this->Energy_Points == 0)
        std::cout << name << " ScavTrap No Energy to Attack With (Exhausted)!" << std::endl;
    else
    {
        std::cout << name << " ScavTrap Attack " << target << " ,causing " << Attack_Damage << " points of damage!"<< std::endl;
        this->Energy_Points--;
    }
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	this->name = copy.name;
	this->Hit_Points = copy.Hit_Points;
	this->Energy_Points = copy.Energy_Points;
	this->Attack_Damage = copy.Attack_Damage;
	this->guard_Gate = copy.guard_Gate;
	return *this;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << this->name << " Constructor called" << std::endl;
	this->Hit_Points = 100;
	this->Energy_Points = 50;
	this->Attack_Damage = 20;
	this->guard_Gate = false;
}

void	ScavTrap::guardGate(void)
{
	if (this->guard_Gate == false)
	{
		this->guard_Gate = true;
		std::cout << this->name << "  is now in Gatekeeper mode." << std::endl;
	}
	else
		std::cout << this->name << " is already in Gatekeeper mode." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Deconstructor for " << this->name << " called" << std::endl;
}