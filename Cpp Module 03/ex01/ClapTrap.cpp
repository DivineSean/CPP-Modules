#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("Default"), Hit_Points(10), Energy_Points(10), Attack_Damage(0)
{
	std::cout << name << " Spawned To the Game!!" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : name(name) , Hit_Points(10), Energy_Points(10), Attack_Damage(0)
{
    std::cout << name << " Spawned To the Game!!" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &copy )
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=( const ClapTrap &copy )
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	this->name = copy.name;
	this->Hit_Points = copy.Hit_Points;
	this->Energy_Points = copy.Energy_Points;
	this->Attack_Damage = copy.Attack_Damage;
	return *this;
}

void    ClapTrap::attack( const std::string &target )
{
    if (this->Hit_Points == 0)
        std::cout << "Cant Attack." << name << " is DEAD!" << std::endl;
    else if (this->Energy_Points == 0)
        std::cout << name << " No Energy to Attack With (Exhausted)!" << std::endl;
    else
    {
        std::cout << name << " Attack " << target << " ,causing " << Attack_Damage << " points of damage!"<< std::endl;
        this->Energy_Points--;
    }
}

void    ClapTrap::takeDamage( unsigned int amount )
{
    if (this->Hit_Points > amount)
    {
        std::cout << name << " Damaged And Lost "<< amount << " of HP!" << std::endl;
        this->Hit_Points -= amount;
        std::cout << name << " Now Have " << Hit_Points << "/100 HP" << std::endl;
    }
    else if (this->Hit_Points <= amount && !this->Hit_Points)
    {
        std::cout << name << " Has Killed By this Heavy Attack. Lost him " << amount << " HP!" << std::endl;
        this->Hit_Points = 0;
    }
    else
    {
        if (!amount)
            std::cout << " Cant Be Damaged With 0 Attack Damage!" << std::endl;
        else
            std::cout << " Is Already DEAD!" << std::endl;
    }
}

void    ClapTrap::beRepaired( unsigned int amount )
{
    if (this->Hit_Points == 100)
        std::cout << name << " Already Full HP 100/100" << std::endl;
    else if (this->Hit_Points == 0)
        std::cout << "Cant Heal." << name << " is Already DEAD!" << std::endl;
    else if (this->Energy_Points == 0)
        std::cout << name << " No Energy to Heal With (Exhausted)!" << std::endl;
    else
    {
        if (this->Hit_Points + amount > 100)
        {
            std::cout << "Reducing The Amount " << amount << " To " << 100 - Hit_Points << " For Maximum Health Bar!" <<std::endl;
            amount = 100 - Hit_Points;
        }
        std::cout << name << " Heal " << amount << " Hit_Points!"<< std::endl;
        this->Energy_Points--;
        this->Hit_Points += amount;
        std::cout << name << " Now Have " << this->Hit_Points << "/100 HP" << std::endl;
    }
}

ClapTrap::~ClapTrap()
{
    std::cout << name << " Quit the Game!!" << std::endl;
}