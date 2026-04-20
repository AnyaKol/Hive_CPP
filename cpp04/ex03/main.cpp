/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:46:47 by akolupae          #+#    #+#             */
/*   Updated: 2026/04/19 16:47:08 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main(void) {
	std::cout << "\n\t*** SUBJECT TESTS ***" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		std::cout << std::endl;

		src->learnMateria(new Cure());
		std::cout << "---" << std::endl;
		src->learnMateria(new Ice());
		std::cout << "---" << std::endl;
		std::cout << std::endl;

		ICharacter* me = new Character("me");
		std::cout << std::endl;

		AMateria* tmp;
		
		tmp = src->createMateria("ice");
		me->equip(tmp);
		std::cout << "---" << std::endl;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << std::endl;

		ICharacter* bob = new Character("bob");
		std::cout << std::endl;

		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << std::endl;

		delete bob;
		std::cout << std::endl;
		delete me;
		std::cout << std::endl;
		delete src;
		std::cout << std::endl;
	}

	std::cout << "\n\t*** EXPANDED TESTS ***" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		std::cout << std::endl;
		src->learnMateria(new Cure());
		std::cout << "---" << std::endl;
		src->learnMateria(new Cure());
		std::cout << "---" << std::endl;
		src->learnMateria(new Cure());
		std::cout << "---" << std::endl;
		src->learnMateria(new Cure());
		std::cout << "---" << std::endl;
		src->learnMateria(new Ice());
		std::cout << "---" << std::endl;
		src->learnMateria(new Cure());
		std::cout << std::endl;

		ICharacter* me = new Character("me");
		std::cout << std::endl;

		AMateria* tmp;
		
		tmp = src->createMateria("ice");
		me->equip(tmp);
		std::cout << "---" << std::endl;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << "---" << std::endl;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << "---" << std::endl;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << "---" << std::endl;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << "---" << std::endl;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << "---" << std::endl;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << std::endl;

		ICharacter* bob = new Character("bob");
		std::cout << std::endl;

		ICharacter* steve = new Character("Steve");
		*steve = *me;
		std::cout << std::endl;

		me->use(0, *bob);
		me->use(1, *steve);
		steve->use(1, *me);
		std::cout << std::endl;

		delete steve;
		std::cout << std::endl;
		delete bob;
		std::cout << std::endl;
		delete me;
		std::cout << std::endl;
		delete src;
		std::cout << std::endl;
	}
	std::cout << "\n\t*** COPY TESTS ***" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		std::cout << std::endl;
		src->learnMateria(new Cure());
		std::cout << "---" << std::endl;
		src->learnMateria(new Cure());
		std::cout << "---" << std::endl;
		src->learnMateria(new Cure());
		std::cout << "---" << std::endl;
		src->learnMateria(new Cure());
		std::cout << "---" << std::endl;
		src->learnMateria(new Ice());
		std::cout << "---" << std::endl;
		src->learnMateria(new Cure());
		std::cout << std::endl;

		Character me ("me");
		std::cout << std::endl;

		AMateria* tmp;
		
		tmp = src->createMateria("ice");
		me.equip(tmp);
		std::cout << "---" << std::endl;
		tmp = src->createMateria("cure");
		me.equip(tmp);
		std::cout << "---" << std::endl;
		tmp = src->createMateria("cure");
		me.equip(tmp);
		std::cout << "---" << std::endl;
		tmp = src->createMateria("cure");
		me.equip(tmp);
		std::cout << "---" << std::endl;
		tmp = src->createMateria("cure");
		me.equip(tmp);
		std::cout << "---" << std::endl;
		tmp = src->createMateria("cure");
		me.equip(tmp);
		std::cout << "---" << std::endl;
		tmp = src->createMateria("cure");
		me.equip(tmp);
		std::cout << std::endl;

		ICharacter* bob = new Character("bob");
		std::cout << std::endl;

		Character steve ("Steve");
		steve = me;
		std::cout << std::endl;

		me.use(0, *bob);
		me.use(1, steve);
		steve.use(1, me);
		std::cout << std::endl;

		delete bob;
		std::cout << std::endl;
		delete src;
		std::cout << std::endl;
	}
	return (0);
}
