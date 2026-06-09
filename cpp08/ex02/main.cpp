/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:53:51 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/26 17:08:53 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.tpp"

#include <iostream>
#include <list>

int main( void ) {

	std::cout << "\n\t*** SUBJECT TESTS ***\n" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "\n\t*** LIST TESTS ***\n" << std::endl;
	{
		std::list<int> l;

		l.push_back(5);
		l.push_back(17);

		std::cout << l.front() << std::endl;

		l.pop_back();

		std::cout << l.size() << std::endl;

		l.push_back(3);
		l.push_back(5);
		l.push_back(737);
		//[...]
		l.push_back(0);

		std::list<int>::iterator it = l.begin();
		std::list<int>::iterator ite = l.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	return (0); 
}

