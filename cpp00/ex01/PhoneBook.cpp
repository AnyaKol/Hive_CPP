/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:45:24 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/08 19:50:16 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Constructor
PhoneBook::PhoneBook(void)
	: count(0)
	: max_count(0) {}

void	add(void) {
	if (this->count == 8)
		this->count = 0;
	this->contacts[count] = Contact contact;
	this->count++;
	if (this->max_count < 8)
		this->max_count++;
}

void	search(void) {
	std::string	input;
	int			index;

	print_table();
	std::cin >> input;
	if (!input) {
		std::cout << "No input." << std::endl;
		return ;
	}
	index = stoi(input);
	if (input != to_string(index)) {
		std::cout << "Wrong input. Expected number." << std::endl;
		return ;
	}
	if (index < 1 || index > 8) {
		std::cout << "Number out of range. Expected number in range [1, 8]." << std::endl;
		return ;
	}
	if (index > this->max_count) {
		std::cout << "No contact with this index." << std::endl;
		return ;
	}
	this->contacts[index].print_contact();
}

void	print_table(void) {
	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|"
		<< print_content("Index") << "|"
		<< print_content("First name") << "|" 
		<< print_content("Last name") << "|" 
		<< print_content("Nickname") << "|"
		<< std::endl;
	std::cout << "_____________________________________________" << std::endl;
	for (int i = 0; i < this->max_count; i++) {
		std::cout << "|"
			<< print_content(to_string(i)) << "|"
			<< print_content(this->contacts[i].firstName) << "|" 
			<< print_content(this->contacts[i].lastName) << "|" 
			<< print_content(this->contacts[i].nickname) << "|"
			<< std::endl;
		std::cout << "_____________________________________________" << std::endl;
	}
}

void	print_content(std::string str) {
	if (!str)
		return ;
	if (str.length <= 10)
		std::cout << std::string(10 - std::strlen(str), ' ') << str;
	else
		std::cout << str.substr(0, 9) << ".";
}
