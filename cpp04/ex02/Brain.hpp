/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 14:27:07 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/19 14:27:11 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Brain {

public:

	Brain(void);
	Brain(const Brain& other);
	Brain&	operator= (const Brain& other);
	~Brain(void);

	const std::string&	getIdea(unsigned int i) const;
	void				setIdea(unsigned int i, const std::string& idea);

private:

	std::string	_ideas[100];

};
