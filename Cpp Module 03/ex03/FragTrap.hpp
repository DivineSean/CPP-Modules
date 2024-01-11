#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public virtual ClapTrap
{
    private:
    public:
    	FragTrap();
		FragTrap(const FragTrap &copy);
        FragTrap &operator=(const FragTrap &copy);
		FragTrap(std::string name);
        void highFivesGuys(void);
        ~FragTrap();
};