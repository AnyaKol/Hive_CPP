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

	std::cout << "\n\t*** ARRAY TESTS ***" << std::endl;
	{
		Animal* arr[4];
		int		n = 4;

		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				arr[i] = new Dog();
			} else {
				arr[i] = new Cat();
			}
		}
		std::cout << std::endl;

		for (int i = 0; i < n; i++) {
			delete arr[i];
		}
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
		std::cout << "A:" << std::endl;
		Cat	a;
		a.makeSound();
		a.getBrain()->setIdea(0, "Meat");
		std::cout << std::endl;
	
		std::cout << "B:" << std::endl;
		Cat	b(a);
		b.makeSound();
		std::cout << std::endl;

		std::cout << "A Brain: " << a.getBrain()
			<< " A idea 0: " << a.getBrain()->getIdea(0) << std::endl;
		std::cout << "B Brain: " << b.getBrain()
			<< " B idea 0: " << b.getBrain()->getIdea(0) << std::endl;

		std::cout << std::endl;
		b = Cat();
		b.makeSound();
		std::cout << std::endl;

		std::cout << "B Brain: " << b.getBrain()
			<< " B idea 0: " << b.getBrain()->getIdea(0) << std::endl;
		std::cout << std::endl;
	}

	std::cout << "\n\t*** DOG BRAIN TESTS ***" << std::endl;
	{
		std::cout << "A:" << std::endl;
		Dog	a;
		a.makeSound();
		a.getBrain()->setIdea(0, "Meat");
		std::cout << std::endl;
	
		std::cout << "B:" << std::endl;
		Dog	b(a);
		b.makeSound();
		std::cout << std::endl;

		std::cout << "A Brain: " << a.getBrain()
			<< " A idea 0: " << a.getBrain()->getIdea(0) << std::endl;
		std::cout << "B Brain: " << b.getBrain()
			<< " B idea 0: " << b.getBrain()->getIdea(0) << std::endl;

		std::cout << std::endl;
		b = Dog();
		b.makeSound();
		std::cout << std::endl;

		std::cout << "B Brain: " << b.getBrain()
			<< " B idea 0: " << b.getBrain()->getIdea(0) << std::endl;
		std::cout << std::endl;
	}

	std::cout << "\n\t*** BRAIN POINTER TESTS ***" << std::endl;
	{
		Animal *cat = new Cat();
		Animal *dog = new Dog();
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
