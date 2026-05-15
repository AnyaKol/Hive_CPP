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

#include <string>

class ScalarConverter {

public:

	ScalarConverter&	operator= (const ScalarConverter& other);
	// Move assignment
	ScalarConverter&	operator= (ScalarConverter&& other) noexcept = default;
	~ScalarConverter(void) {};

	static void	convert(const std::string& val);

private:

	ScalarConverter(void) {};
	ScalarConverter(const ScalarConverter& other);
	// Move constructor
	ScalarConverter(ScalarConverter&& other) noexcept = default;

};
