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

	std::cout << "\n\t*** SUBJECT TESTS ***" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << std::endl;

		delete j;//should not create a leak
		delete i;
		std::cout << std::endl;
	}

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
		Brain	c;
		std::cout << "Brain C: " << c.getIdea(0) << std::endl;
		c = a;
		std::cout << "Brain C: " << c.getIdea(0) << std::endl;
		std::cout << std::endl;
		Brain*	d = new Brain;
		std::cout << "Brain D: " << d->getIdea(0) << std::endl;
		std::cout << std::endl;

		delete d;
		std::cout << std::endl;
	}

	std::cout << "\n\t*** CAT BRAIN TESTS ***" << std::endl;
	{
		Cat	a("Kissa");
		a.makeSound();
		a.getBrain()->setIdea(0, "Milk");
		std::cout << std::endl;
	
		Cat	b(a);
		b.setName("King");
		b.makeSound();
		std::cout << std::endl;

		std::cout << "Kissa Brain: " << a.getBrain()
			<< " Kissa idea 0: " << a.getBrain()->getIdea(0) << std::endl;
		std::cout << "King Brain: " << b.getBrain()
			<< " King idea 0: " << b.getBrain()->getIdea(0) << std::endl;

		std::cout << std::endl;
		b = Cat("Queen");
		b.makeSound();
		std::cout << std::endl;

		std::cout << "Queen Brain: " << b.getBrain()
			<< " Queen idea 0: " << b.getBrain()->getIdea(0) << std::endl;
		std::cout << std::endl;
	}

	std::cout << "\n\t*** DOG BRAIN TESTS ***" << std::endl;
	{
		Dog	a("Lassie");
		a.makeSound();
		a.getBrain()->setIdea(0, "Meat");
		std::cout << std::endl;
	
		Dog	b(a);
		b.setName("Snowball");
		b.makeSound();
		std::cout << std::endl;

		std::cout << "Lassie Brain: " << a.getBrain()
			<< " Lassie idea 0: " << a.getBrain()->getIdea(0) << std::endl;
		std::cout << "Snowball Brain: " << b.getBrain()
			<< " Snowball idea 0: " << b.getBrain()->getIdea(0) << std::endl;

		std::cout << std::endl;
		b = Dog("Duke");
		b.makeSound();
		std::cout << std::endl;

		std::cout << "Duke Brain: " << b.getBrain()
			<< " Duke idea 0: " << b.getBrain()->getIdea(0) << std::endl;
		std::cout << std::endl;
	}

	std::cout << "\n\t*** BRAIN POINTER TESTS ***" << std::endl;
	{
		Animal *cat = new Cat("Kot");
		Animal *dog = new Dog("Sobaka");
		std::cout << std::endl;

		cat->makeSound();
		dog->makeSound();
		//cat->getBrain();
		std::cout << std::endl;

		delete cat;
		delete dog;
		std::cout << std::endl;
	}

	return 0;
}
