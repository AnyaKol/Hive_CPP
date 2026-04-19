/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:18:55 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/18 20:46:39 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

// Can create A_Animal pointer
int	main(void) {

	std::cout << "\n\t*** ANIMAL TESTS ***" << std::endl;
	{
		const AAnimal* dog = new Dog();
		const AAnimal* cat = new Cat();
		std::cout << std::endl;
		//AAnimal a;
		//AAnimal* b = new A_Animal();

		delete dog;//should not create a leak
		delete cat;
		std::cout << std::endl;
	}

	return 0;
}
