/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:50:25 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/14 17:12:14 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(void) {}

Replacer::~Replacer(void) {}

void	Replacer::replace(std::string filename, std::string s1, std::string s2) {
	std::string		line;
	std::ifstream	input(filename);

	if (!input) {
		std::cerr << "Failde to open file" << std::endl;
		return ;
	}
	std::ofstream output(filename + ".replace");
	while (getline(input, line)) {
		size_t	start;
		size_t	end;

		line += "\n";
		start = 0;
		end = 0;
		while (1) {
			end = line.find(s1, start);
			if (end == std::string::npos) {
				output << line.substr(start);
				break ;
			}
			output << line.substr(start, end - start) << s2;
			start = end + s1.length();
		}
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
