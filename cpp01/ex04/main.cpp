/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:19:48 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/14 13:27:28 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int	main(int argc, char** argv) {
	Replacer replacer;

	if (!replacer.checkArgs(argc, argv))
		return (1);
	replacer.replace((std::string)argv[1], (std::string) argv[2],
		(std::string) argv[3]);
	return (0);
}
