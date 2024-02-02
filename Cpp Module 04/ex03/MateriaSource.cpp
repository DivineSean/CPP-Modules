#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource is Created Succesfully" << std::endl;
	for(int i = 0; i < 4; i++)
		this->inventory[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
    for(int i = 0; i < 4; i++)
    {
        if (copy.inventory[i])
            (this->inventory)[i] = (copy.inventory[i])->clone();
    }
	std::cout << "MateriaSource is created from copy" << std::endl;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &copy)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		if (copy.inventory[i])
			this->inventory[i] = (copy.inventory[i])->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia)
{
    int i = 0;
    if (!materia)
        return ;
    while (i < 4)
    {
        if (!this->inventory[i])
            break;
        i++;
    }
    if (i == 4)
    {
        std::cout << "MateriaSource : Cant Learn More Than 4 Materia" << std::endl;
        return ;
    }
    this->inventory[i] = materia;
    std::cout << "MateriaSource Learned " << materia->getType() << " And Put it in Slot Number " << i << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	int i = 0;

	while (this->inventory[i] && this->inventory[i]->getType() != type && i < 4)
		i++;
	if (i == 4 || !this->inventory[i])
	{
		std::cout << type << " Materia Not Found in Inventory" << std::endl;
		return (NULL);
	}
	std::cout << "Materia " << type << " created\n";
	return (this->inventory[i]->clone());
}

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
	std::cout << "MateriaSource is Deleted Succesfully" << std::endl;
}