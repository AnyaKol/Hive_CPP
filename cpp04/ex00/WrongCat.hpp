
#pragma once

#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal {

public:

	WrongCat(void);
	WrongCat(std::string name);
	WrongCat(const WrongCat& other);
	WrongCat&	operator= (const WrongCat& other);
	~WrongCat(void);

	void	makeSound(void) const;

};
