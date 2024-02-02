#pragma once

#include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource
{
    private:
        AMateria *inventory[4];
    public:
		MateriaSource();
		MateriaSource(MateriaSource const &copy);
		MateriaSource &operator=(MateriaSource const &copy);
		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const &type);
		~MateriaSource();
};