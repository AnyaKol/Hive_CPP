/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 18:30:54 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/19 18:30:56 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Default constructor
MateriaSource::MateriaSource(void) : IMateriaSource() {}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource() {

	*this = other;
}

// Copy assignment operator overload
MateriaSource&	MateriaSource::operator= (const MateriaSource& other){

	if (this != &other) {

	}

	return (*this);
}

// Destructor
MateriaSource::~MateriaSource(void) {

}

// Overridden function
void	MateriaSource::learnMateria(AMateria*) {

}

AMateria*	MateriaSource::createMateria(std::string const & type) {

}