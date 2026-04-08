/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:43:17 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/08 19:42:46 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {
	public:
		string	firstName;
		string	lastName;
		string	nickname;
		string	phoneNumber;
		string	darkestSecret;

		Contact(void);
		~Contact(void);

	private:
		void		create(void);
		std::string	get_input(void);
};

#endif
