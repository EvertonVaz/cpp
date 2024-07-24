/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:18:22 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/24 11:23:49 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include "Fixed.hpp"

template <typename T>
void printElement(const T& element) {
    std::cout << element << " | ";
}

int main(void) {
	int intArray[] = {1, 2, 3, 4, 5};
    std::string strArray[] = {"one", "two", "three"};
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	Fixed fixedArray[] = {Fixed(1), Fixed(2), Fixed(3)};

	std::cout << "intArray: | ";
    ::iter(intArray, 5, printElement<int>);
	std::cout << std::endl << "stringArray: | ";
    ::iter(strArray, 3, printElement<std::string>);
	std::cout << std::endl << "charArray: | ";
	::iter(charArray, 5, printElement<char>);
	std::cout << std::endl << "floatArray: | ";
	::iter(floatArray, 5, printElement<float>);
	std::cout << std::endl << "fixedArray: | ";
	::iter(fixedArray, 3, printElement<Fixed>);
}