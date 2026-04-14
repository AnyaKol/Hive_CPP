/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:23:24 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/14 13:28:03 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef REPLACER_HPP
# define REPLACER_HPP

# include <iostream>
// Library to work with files
# include <fstream>
# include <string>

class Replacer {

public:
	Replacer(void);
	~Replacer(void);

	void	replace(std::string filename, std::string s1, std::string s2);
	bool	checkArgs(int argc, char** argv);

private:

};

#endif
