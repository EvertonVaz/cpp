/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:37:05 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/24 14:13:44 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> vec;
	for (int i = 0; i < 99; i++)
		vec.push_back(i);

	try {
		std::vector<int>::iterator it;
		std::cout << "Vector:\n";

		for (it = vec.begin(); it != vec.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "easyfind(vec, 3): ";
		std::vector<int>::iterator element = easyfind(vec, 3);
		std::cout << "Found " << *element << std::endl;

		std::cout << "easyfind(vec, 42): ";
		element = easyfind(vec, 42);
		std::cout << "Found " << *element << std::endl;

		std::cout << "easyfind(vec, 99): ";
		element = easyfind(vec, 99);
		std::cout << "Found " << *element << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}