#pragma once
#include <iostream>

class Brain
{
	private:
		std::string	*ideas;
	public:
		Brain();
		Brain(Brain &copy);
		Brain &operator=(const Brain &copy);
		std::string *getIdeas() const;
		~Brain();
};