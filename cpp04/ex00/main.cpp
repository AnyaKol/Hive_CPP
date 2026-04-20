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
#include "WrongCat.hpp"

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
		const WrongAnimal* a = new WrongAnimal();
		const WrongAnimal* b = new WrongCat();
		const WrongCat* c = new WrongCat();
		std::cout << std::endl;

		std::cout << "B: " << b->getType() << " " << std::endl;
		std::cout << "C: " << c->getType() << " " << std::endl;
		std::cout << std::endl;

		std::cout << "B: ";
		b->makeSound(); //will output the WrongAnimal sound!
		std::cout << "C: ";
		c->makeSound(); //will output the WrongCat sound
		std::cout << "A: ";
		a->makeSound();
		std::cout << std::endl;

		delete a;
		delete b;
		delete c;
	}

	std::cout << "\n\t*** ANIMAL TESTS ***" << std::endl;
	{
		std::cout << "A: " << std::endl;
		Animal	a;
		std::cout << std::endl;

		std::cout << "B: " << std::endl;
		Animal	b(a);
		b.makeSound();
		std::cout << std::endl;

		b = Animal();
		b.makeSound();
		std::cout << std::endl;

		std::cout << "C: " << std::endl;
		Animal	c;
		c = a;
		c.makeSound();
		std::cout << std::endl;
	}
	std::cout << "\n\t*** CAT TESTS ***" << std::endl;
	{
		std::cout << "A: " << std::endl;
		Cat	a;
		std::cout << std::endl;

		std::cout << "B: " << std::endl;
		Cat	b(a);
		b.makeSound();
		std::cout << std::endl;

		b = Cat();
		b.makeSound();
		std::cout << std::endl;

		std::cout << "C: " << std::endl;
		Cat	c;
		c = a;
		c.makeSound();
		std::cout << std::endl;
	}
	std::cout << "\n\t*** DOG TESTS ***" << std::endl;
	{
		std::cout << "A: " << std::endl;
		Dog	a;
		std::cout << std::endl;

		std::cout << "B: " << std::endl;
		Dog	b(a);
		b.makeSound();
		std::cout << std::endl;

		b = Dog();
		b.makeSound();
		std::cout << std::endl;

		std::cout << "C: " << std::endl;
		Dog	c;
		c = a;
		c.makeSound();
		std::cout << std::endl;
	}

	return 0;
}
