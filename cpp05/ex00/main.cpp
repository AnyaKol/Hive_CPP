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

#include "Name.hpp"

int	main(void) {

	std::cout << "\n\t*** SUBJECT TESTS ***" << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << std::endl;

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		std::cout << std::endl;

		delete meta;
		delete j;
		delete i;
	}

	std::cout << "\n\t*** WRONG ANIMAL TESTS ***" << std::endl;
	{
		const WrongAnimal* a = new WrongAnimal("WAnimal");
		const WrongAnimal* b = new WrongCat("WAnimalCat");
		const WrongCat* c = new WrongCat("WCat");
		std::cout << std::endl;

		std::cout << b->getType() << " " << std::endl;
		std::cout << c->getType() << " " << std::endl;
		std::cout << std::endl;
		b->makeSound(); //will output the WrongAnimal sound!
		c->makeSound(); //will output the WrongCat sound
		a->makeSound();
		std::cout << std::endl;

		delete a;
		delete b;
		delete c;
	}

	return 0;
}
