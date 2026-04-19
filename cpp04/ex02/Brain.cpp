/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 14:26:57 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/19 14:27:00 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if (i >= 100) {
		std::cout << "No idea " + std::to_string(i) + "." << std::endl;
		return (this->_ideas[0]);
	}

	return (this->_ideas[i]);
}

void	Brain::setIdea(unsigned int i, const std::string& idea) {

	if (i >= 100) {
		std::cout << "No room for idea " << i << "." << std::endl;
		return ;
	}

	this->_ideas[i] = idea;
}
