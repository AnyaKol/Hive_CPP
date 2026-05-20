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

	~ScalarConverter(void) {};

	static void	convert(const std::string_view val);

private:

	ScalarConverter(void) = delete;
	ScalarConverter(const ScalarConverter& other) = delete;
	// Move constructor
	ScalarConverter(ScalarConverter&& other) noexcept = delete;
	ScalarConverter&	operator= (const ScalarConverter& other);
	// Move assignment
	ScalarConverter&	operator= (ScalarConverter&& other) noexcept = delete;

};
