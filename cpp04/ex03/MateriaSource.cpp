/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 18:30:54 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/19 19:27:27 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Default constructor
MateriaSource::MateriaSource(void) : IMateriaSource(), _lastIdx(0) {

	for (int i = 0; i < 4; i++)
		this->_memory[i] = nullptr;
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource() {

	*this = other;
}

// Copy assignment operator overload
MateriaSource&	MateriaSource::operator= (const MateriaSource& other){

	if (this != &other) {
		this->_lastIdx = other._lastIdx;
		for (int i = 0; i < 4; i++) {
			if (this->_memory[i] != nullptr)
				delete this->_memory[i];
			if (other._memory[i] != nullptr)
				this->_memory[i] = other._memory[i]->clone();
		}
	}

	return (*this);
}

// Destructor
MateriaSource::~MateriaSource(void) {

		for (int i = 0; i < 4; i++) {
			if (this->_memory[i] != nullptr)
				delete this->_memory[i];
		}
}

// Overridden function
void	MateriaSource::learnMateria(AMateria* m) {

	if (m == nullptr)
		return ;

	int	i;

	for (i = 0; i < 4; i++) {
		if (this->_memory[i] == nullptr)
			break ;
	}
	if (i == 4) {
		if (this->_lastIdx == 4)
			this->_lastIdx = 0;
		delete this->_memory[0];
		i = 0;
	}

	this->_memory[i] = m->clone();
	std::cout << "New materia " << *m << " learned." << std::endl;

}

AMateria*	MateriaSource::createMateria(std::string const& type) {

	int	i;

	for (i = 0; i < 4; i++) {
		if (this->_memory[i]->getType() == type)
			break ;
	}
	if (i == 4) {
		std::cout << "Type " << type << " is unknown." << std::endl;
		return (0);
	}

	return ( this->_memory[i]->clone() );
}
