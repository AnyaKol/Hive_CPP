/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:04:47 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/12 10:01:17 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ScalarConverter {

public:

	ScalarConverter&	operator= (const ScalarConverter& other);
	~ScalarConverter(void);

	static void	convert(std::string val);

private:

	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& other);

};
