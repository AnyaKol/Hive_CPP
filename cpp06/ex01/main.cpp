/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:18:55 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/20 19:39:30 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

#include <iostream>
#include <typeinfo>

int	main(void) {

	//Serializer a;
	//Serializer b(a);
	//b = a;
	//Serializer *c = new Serializer();
	//delete c;

	std::cout << "\n\t*** TESTS ***\n" << std::endl;

	Data data(13);
	Data* ptr = &data;

	std::cout << "ptr type: " << typeid(ptr).name() << std::endl;
	std::cout << "Adress held by ptr: " << ptr << std::endl;
	std::cout << "Value from ptr: " << ptr->getValue() << std::endl;
	data.setValue(123);
	std::cout << "Value from ptr: " << ptr->getValue() << std::endl;

	uintptr_t uint_ptr = Serializer::serialize(ptr);
	
	std::cout << "\n\tAfter serialization:\n" << std::endl;
	std::cout << "ptr type: " << typeid(uint_ptr).name()  << std::endl;
	std::cout << "Adress held by ptr: " << uint_ptr << std::endl;

	Data* new_ptr = Serializer::deserialize(uint_ptr);

	std::cout << "\n\tAfter deserialization:\n" << std::endl;
	std::cout << "ptr type: " << typeid(new_ptr).name() << std::endl;
	std::cout << "Adress held by ptr: " << new_ptr << std::endl;
	std::cout << "Value from ptr: " << new_ptr->getValue() << std::endl;
	data.setValue(45);
	std::cout << "Value from ptr: " << ptr->getValue() << std::endl;

	return 0;
}
