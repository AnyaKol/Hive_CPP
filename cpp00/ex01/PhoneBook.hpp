/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:41:35 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/08 18:21:04 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook {
	public:
		// Constructor to initialise private member
		PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void);

	private:
		Contact contacts[8];
		int		count;
		int		max_count;

		void	print_table(void);
		void	print_content(std::string str);
};

#endif
