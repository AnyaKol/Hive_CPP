/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:50:25 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/14 14:00:07 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(void) {}

Replacer::~Replacer(void) {}

void	Replacer::replace(std::string filename, std::string s1, std::string s2) {
	std::string	line;

	(void)s1;
	(void)s2;
	try {
		std::ifstream input(filename);
		if (!input.is_open()) {
			throw
				""
		}
	}
	std::ofstream output(filename + ".replace");
	while (getline(input, line)) {
		std::cout << line + "\n";
		output << line + "\n";
	}
	input.close();
	output.close();
}

bool	Replacer::checkArgs(int argc, char** argv) {
	if (argc != 4) {
		std::cerr << "Wrong number of arguments.\n"
			<< "Use: <filename> <find> <replace with>." << std::endl;
		return (false);
	}
	if (((std::string) argv[1]).empty()) {
		std::cerr << "Filename can't be empty." << std::endl;
		return (false);
	}
	if (((std::string) argv[2]).empty()) {
		std::cerr << "String to find can't be empty." << std::endl;
		return (false);
	}
	return (true);
}
