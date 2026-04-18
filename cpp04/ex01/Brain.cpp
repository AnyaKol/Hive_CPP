
#include "Brain.hpp"

// Default constructor
Brain::Brain(void) {
	std::cout << "Brain created." << std::endl;
}

// Copy constructor
Brain::Brain(const Brain& other) {
	std::cout << "Brain calls copy constructor." << std::endl;

	*this = other;
}

// Copy assignment operator overload
Brain&	Brain::operator= (const Brain& other) {
	std::cout << "Brain calls copy assignment operator." << std::endl;

	if (this != &other) {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}

	return (*this);
}

// Destructor
Brain::~Brain(void) {
	std::cout << "Brain destroyed." << std::endl;
}

// Brain function
const std::string&	Brain::getIdea(unsigned int i) const {
	if (i >= 100)
		return ("No idea.");

	return (this->_ideas[i]);
}

void	Brain::setIdea(unsigned int i, const std::string& idea) {
	if (i >= 100)
		return ;

	this->_ideas[i] = idea;
}