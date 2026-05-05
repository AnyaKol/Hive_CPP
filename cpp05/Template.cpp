/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:10:45 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/17 17:17:10 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Template.hpp"

// Default constructor
Template::Template(void) : Template("DefaultName") {}

// Constructor with parameter
Template::Template(std::string name) {}

// Copy constructor
Template::Template(const Template& other) {
	*this = other;
}

// Copy assignment operator overload
Template&	Template::operator= (const Template& other) {

	//if (this != &other) {}

	return (*this);
}

// Destructor
Template::~Template(void) {}

