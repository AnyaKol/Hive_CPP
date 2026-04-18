
#pragma once

#include <iostream>
#include <string>

class WrongAnimal {

public:

	WrongAnimal(void);
	WrongAnimal(std::string name);
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal&	operator= (const WrongAnimal& other);
	virtual ~WrongAnimal(void);

	void				makeSound(void) const;
	const std::string&	getType(void) const;
	const std::string&	getName(void) const;
	void				setName(const std::string& name);

protected:

	WrongAnimal(std::string type, std::string name);

	void	_announce(void) const;

	std::string	_type;
	std::string	_name;

};
