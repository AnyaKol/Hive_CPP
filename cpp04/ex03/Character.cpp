/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:51:27 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/19 19:51:32 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Default constructor
Character::Character(void) : Character("DefaultCharacter") {}

// Constructor with parameter
Character::Character(const std::string& name) : ICharacter() {
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
}

// Copy constructor
Character::Character(const Character& other) : ICharacter() {

	*this = other;
}

// Copy assignment operator overload
Character&	Character::operator= (const Character& other){

	if (this != &other) {
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = other._inventory[i];
	}

	return (*this);
}

// Destructor
Character::~Character(void) {

}

// Inserion operator overload
std::ostream&	operator<< (std::ostream& output, const Character& other) {
	output << other.getName();

	return (output);
}

// Overridden function
std::string const&	Character::getName() const{
	return (this->_name);
}
void	Character::equip(AMateria* m) {
	int	idx;

	for (idx = 0; idx < 4; idx++) {
		if (this->_inventory[idx] == nullptr)
			break ;
	}
	if (idx == 4) {
		std::cout << *this << ": Inventory is full." << std::endl;
		return ;
	}

	this->_inventory[idx] = m;
	std::cout << *this << ": Materia " << m << " equipped." << std::endl;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;

	if (this->_inventory[idx] == nullptr) {
		std::cout << *this << ": slot " << idx << " is empty." << std::endl;
		return ;
	}

	this->_discardMateria(this->_inventory[idx]);
	std::cout << *this << ": Materia " << this->_inventory[idx]->getType()
		<< " unequipped." << std::endl;
	this->_inventory[idx] = nullptr;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3)
		return ;

	this->_inventory[idx]->AMateria::use(target);
}

void	Character::_discardMateria(AMateria *m) {
	t_AMateria* node = new t_AMateria;

	node->next = nullptr;
	node->data = m;

	if (this->_discarded == nullptr) {
		this->_discarded = node;
		return ;
	}

	t_AMateria*	last = this->_discarded;

	for (last; last->next != nullptr; last = last->next) {}
	last->next = node;
}
