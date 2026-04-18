
#pragma once

#include <iostream>
#include <string>

class Brain {

public:

	Brain(void);
	Brain(const Brain& other);
	Brain&	operator= (const Brain& other);
	~Brain(void);

	const std::string&	Brain::getIdea(unsigned int i) const;
	void				Brain::setIdea(unsigned int i, const std::string& idea);

private:

	std::string[100]	_ideas;

};
