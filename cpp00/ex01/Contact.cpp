/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:33:53 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/08 19:55:36 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Constructor
Contact::Contact(void) {
	create();
}

void	create(void) {
	this->firstName = get_input("the first name");
	this->lastName = get_input("the last name");
	this->nickname = get_input("the nickname");
	this->phoneNumber = get_input("the phone number");
	this->darkestSecret = get_input("the darkest secret");
}

std::string	get_input(std::string field) {
	std::string	input;

	input = "";
	while (input.empty()) {
		std::cout << "Please enter " << field << ":" << std::endl;
		std::cin >> input;
	}
	return (input);
}
