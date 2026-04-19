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

int	main(void) {

	std::cout << "\n\t*** BRAIN CONSTRUCTOR TESTS ***" << std::endl;
	{
		Brain	a;
		std::cout << "Brain A: " << a.getIdea(0) << std::endl;
		a.setIdea(0, "Idea 0");
		std::cout << "Brain A: " << a.getIdea(0) << std::endl;
		std::cout << std::endl;
		Brain	b(a);
		std::cout << "Brain B: " << b.getIdea(0) << std::endl;
		std::cout << std::endl;
		Brain	c = a;
		std::cout << "Brain C: " << c.getIdea(0) << std::endl;
		std::cout << std::endl;
		Brain*	d = new Brain;
		std::cout << std::endl;

		delete d;
		std::cout << std::endl;
	}

	std::cout << "\n\t*** BRAIN TESTS ***" << std::endl;
	{
		Cat	a("Kissa");
		a.makeSound();
		std::cout << a.getBrain() << std::endl;
		a.getBrain()->setIdea(0, "Milk");
		std::cout << "Cat Kissa Brain: " << a.getBrain() << std::endl;
		std::cout << "Cat Kissa idea 0: " << a.getBrain()->getIdea(0) << std::endl;
		std::cout << std::endl;
	
		Cat	b(a);
		b.setName("King");
		b.makeSound();
		std::cout << "Cat King Brain: " << b.getBrain() << std::endl;
		std::cout << "Cat King idea 0: " << b.getBrain()->getIdea(0) << std::endl;
		std::cout << std::endl;

		b = Cat("Queen");
		b.makeSound();
		std::cout << "Cat Queen Brain: " << b.getBrain() << std::endl;
		std::cout << "Cat Queen idea 0: " << b.getBrain()->getIdea(0) << std::endl;
		std::cout << std::endl;
	}

	return 0;
}
