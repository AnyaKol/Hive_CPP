/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:41:35 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/11 18:49:59 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {

public:
	// Constructor to initialise private member
	PhoneBook(void);
	~PhoneBook(void);

	void	add(void);
	void	search(void);

private:
	Contact	_contacts[8];
	int		_count;
	int		_maxCount;

	void		_printTable(void);
	std::string	_printContent(std::string str);
};

#endif
