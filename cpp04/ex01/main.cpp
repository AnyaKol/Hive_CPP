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
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << std::endl;

		std::cout << i->getType() << " " << std::endl;
		std::cout << std::endl;
		i->makeSound(); //will output the WrongAnimal sound!
		meta->makeSound();
		std::cout << std::endl;

		delete meta;
		delete i;
	}

	std::cout << "\n\t*** ANIMAL TESTS ***" << std::endl;
	{
		Animal	a("Alpha");
		std::cout << std::endl;
	
		Animal	b(a);
		b.makeSound();
		std::cout << std::endl;

		b = Animal("Beta");
		b.makeSound();
		std::cout << std::endl;
	
		Animal	c;
		c = a;
		c.makeSound();
		c.setName("Gamma");
		c.makeSound();
		std::cout << std::endl;
	}
	std::cout << "\n\t*** CAT TESTS ***" << std::endl;
	{
		Cat	a("Kisonyka");
		std::cout << std::endl;
	
		Cat	b(a);
		b.makeSound();
		std::cout << std::endl;

		b = Cat("Kitty-Kitty");
		b.makeSound();
		std::cout << std::endl;
	
		Cat	c;
		c = a;
		c.makeSound();
		c.setName("Koska");
		c.makeSound();
		std::cout << std::endl;
	}
	std::cout << "\n\t*** DOG TESTS ***" << std::endl;
	{
		Dog	a("Goodboi");
		std::cout << std::endl;
	
		Dog	b(a);
		b.makeSound();
		std::cout << std::endl;

		b = Dog("Buddy");
		b.makeSound();
		std::cout << std::endl;
	
		Dog	c;
		c = a;
		c.makeSound();
		c.setName("Lady");
		c.makeSound();
		std::cout << std::endl;
	}

	return 0;
}
