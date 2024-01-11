#pragma once
#include "FragTrap.hpp"

class   DiamondTrap : public FragTrap , public ScavTrap
{
    private:
        std::string name;
    public:
        DiamondTrap();
		DiamondTrap(const DiamondTrap &copy);
        DiamondTrap &operator=(const DiamondTrap &copy);
		DiamondTrap(std::string name);
        void attack(const std::string &target);
		void whoAmI(void);
        ~DiamondTrap();
};