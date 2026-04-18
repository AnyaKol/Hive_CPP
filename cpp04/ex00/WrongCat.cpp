
#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat(void) : WrongCat("DefaultWrongCat") {}

// Constructor with parameter
WrongCat::WrongCat(std::string name) : WrongAnimal(name, "WrongCat") {}

// Copy constructor
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {}

// Copy assignment operator overload
WrongCat&	WrongCat::operator= (const WrongCat& other){

	this->WrongAnimal::operator=(other);

	return (*this);
}

// Destructor
WrongCat::~WrongCat(void) {}

// Not overridden function
void	WrongCat::makeSound(void) const {
	this->_announce();
	std::cout << "This Cat sounds Wrong." << std::endl;
}
