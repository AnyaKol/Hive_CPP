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
	this->_discarded = nullptr;

	for (int i = 0; i < 4; i++) {
	 	this->_inventory[i] = nullptr;
	}

	std::cout << "Character " << *this << " created." << std::endl;
}

// Copy constructor
Character::Character(const Character& other) : ICharacter() {
	std::cout << "Character " << *this << " created from " << other << "."
		<< std::endl;
	*this = other;
}

// Copy assignment operator overload
Character&	Character::operator= (const Character& other){
	std::cout << "Character " << *this << " copies " << other << "."
		<< std::endl;

	if (this != &other) {
		this->_name = other._name;
		for (int i = 0; i < 4; i++) {
			this->_inventory[i] = other._inventory[i];
		}
	}

	return (*this);
}

// Destructor
Character::~Character(void) {
	int			i;

	std::cout << "Character " << *this << " cleaning inventory..." << std::endl;
	for (i = 0; i < 4; i++) {
		if (this->_inventory[i] != nullptr) {
			std::cout << " [" << i << "] deleting " << *this->_inventory[i]
				<< "..." << std::endl;
			delete this->_inventory[i];
		}
	}
	std::cout << "Character " << *this << " cleaning discarded..." << std::endl;

	t_AMateria*	node = this->_discarded;
	t_AMateria*	temp;

	i = 0;
	while (node != nullptr) {
		if (node->data != nullptr) {
			std::cout << " [" << i << "] deleting " << *node->data << "..."
				<< std::endl;
			delete node->data;
			temp = node->next;
			delete node;
			node = temp;
			i++;
		}
	}
	std::cout << "Character " << *this << " destroyed." << std::endl;
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

	if (m == nullptr) {
		return ;
	}

	int	i;

	for (i = 0; i < 4; i++) {
		if (this->_inventory[i] == nullptr) {
			break ;
		}
	}
	if (i == 4) {
		std::cout << *this << ": Inventory is full." << std::endl;
		this->_discardMateria(m);
		return ;
	}

	this->_inventory[i] = m;
	std::cout << *this << ": " << *m << " equipped in slot " << i << "."
		<< std::endl;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		return ;
	}

	if (this->_inventory[idx] == nullptr) {
		std::cout << *this << " can't unequip: slot " << idx << " is empty." << std::endl;
		return ;
	}

	this->_discardMateria(this->_inventory[idx]);
	std::cout << *this << ": " << *this->_inventory[idx]
		<< " unequipped from slot " << idx << "." << std::endl;
	this->_inventory[idx] = nullptr;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3) {
		return ;
	}

	if (this->_inventory[idx] == nullptr) {
		std::cout << *this << " can't use: slot " << idx << " is empty." << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}

void	Character::_discardMateria(AMateria *m) {
	t_AMateria* node = new t_AMateria;

	node->next = nullptr;
	node->data = m;

	if (this->_discarded == nullptr) {
		this->_discarded = node;
		return ;
	}

	t_AMateria*	last;

	for (last = this->_discarded; last->next != nullptr; last = last->next) {}
	last->next = node;
}
