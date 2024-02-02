#include "Character.hpp"

Character::Character() : name("Default")
{
    std::cout << "Default Character is Created Succesfully" << std::endl;
    for(int i = 0; i < 4; i++)
		this->inventory[i] = 0;
}

Character::Character( std::string name ) : name(name)
{
    std::cout << name << " Character is Created Succesfully" << std::endl;
    for(int i = 0; i < 4; i++)
		this->inventory[i] = 0;
}

Character::Character(Character const &copy) : name(copy.getName())
{
    for(int i = 0; i < 4; i++)
    {
        if (copy.inventory[i])
            this->inventory[i] = copy.inventory[i]->clone();
    }
	std::cout << name << " is created from copy of " << copy.name << std::endl;
}

void Character::equip(AMateria* materia)
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
        std::cout << name << " Cant Equip More Than 4 Materia" << std::endl;
        return ;
    }
    this->inventory[i] = materia;
    std::cout << this->name << " Equiped " << materia->getType() << " in slot number " << i << std::endl;
}

void Character::unequip(int slot_index)
{
	if (slot_index < 0)
		std::cout << " Slot Number Given Is Negative For This Character " << this->name << ". Please Select Between [0-3]" << std::endl;
    else if (slot_index > 3)
        std::cout << " Slot Number Given Is Not Compatible to Inventory For This Character " << this->name << ". Please Select Between [0-3]" << std::endl;
	else if (!this->inventory[slot_index])
		std::cout << this->name << "  Inventory On Slot Number " << slot_index << " Is Empty Cant Unequip it" << std::endl;
	else
	{
		AMateria *tmp = this->inventory[slot_index];
		std::cout << this->name << " Unequip " << tmp->getType() << " On Slot "<< slot_index << std::endl;
		this->inventory[slot_index] = 0;
	}
}

void Character::use(int slot_index, ICharacter &target)
{
	if (slot_index < 0)
		std::cout << " Slot Number Given Is Negative For This Character " << this->name << ". Please Select Between [0-3]" << std::endl;
    else if (slot_index > 3)
        std::cout << " Slot Number Given Is Not Compatible to Inventory For This Character " << this->name << ". Please Select Between [0-3]" << std::endl;
	else if (!this->inventory[slot_index])
		std::cout << this->name << "  Inventory On Slot Number " << slot_index << " Is Empty Cant Use it" << std::endl;
	else
    {
        std::cout << this->name;
        (this->inventory[slot_index])->use(target);
    }
}

Character &Character::operator=(Character const &copy)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		if (copy.inventory[i])
			this->inventory[i] = copy.inventory[i]->clone();
	}
	return (*this);
}

const std::string &Character::getName() const
{
	return (this->name);
}

AMateria *Character::SelectToDrop(int idx) const
{
    return (this->inventory[idx]);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
	std::cout << name << " Character is Deleted Succesfully" << std::endl;
}