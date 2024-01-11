#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        bool guard_Gate;
    public:
    	ScavTrap();
		ScavTrap(const ScavTrap &copy);
        ScavTrap &operator=(const ScavTrap &copy);
		ScavTrap(std::string name);
        void attack( const std::string &target );
		void guardGate(void);
        ~ScavTrap();
};