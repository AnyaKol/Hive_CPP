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
		static Contact	contacts[8];
		static int		count;
		static int		max_count;

		void	print_table(void);
		void	print_content(std::string str);
};

#endif
