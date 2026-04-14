/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:19:48 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/14 20:39:46 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
// Library to work with files
# include <fstream>
# include <string>

static void	replace(const std::string filename, const std::string s1,
			const std::string s2);
static bool	checkArgNum(int argc);
static bool	checkArgs(const std::string filename, const std::string s1);
static bool	checkOpen(const std::string& filename);

int	main(int argc, char** argv) {
	if (!checkArgNum(argc))
		return (1);
	if (!checkArgs((std::string)argv[1], (std::string)argv[2]))
		return (1);
	replace((std::string)argv[1], (std::string)argv[2], (std::string)argv[3]);
	return (0);
}

static void	replace(const std::string filename, const std::string s1,
			const std::string s2) {
	std::string		line;
	std::ifstream	input(filename);
	std::ofstream	output(filename + ".replace");

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

static bool	checkArgNum(int argc) {
	if (argc != 4) {
		std::cerr << "Wrong number of arguments.\n"
			<< "Use: <filename> <find> <replace with>." << std::endl;
		return (false);
	}
	return (true);
}

static bool	checkArgs(const std::string filename, const std::string s1) {
	if (filename.empty()) {
		std::cerr << "Filename can't be empty." << std::endl;
		return (false);
	}
	if (s1.empty()) {
		std::cerr << "String to find can't be empty." << std::endl;
		return (false);
	}
	if (!checkOpen(filename))
		return (false);
	return (true);
}

static bool	checkOpen(const std::string& filename) {
	std::ifstream	input(filename);

	if (!input) {
		std::cerr << "Failde to open file" << std::endl;
		return (false);
	}
	input.close();
	return (true);
}
