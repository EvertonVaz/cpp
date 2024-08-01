/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:38:50 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/31 11:01:45 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
	try {
		std::cout << "\nTest 1 - add random number" << std::endl;
		Span sp = Span(5);
		sp.addRandomNumbers(5);
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "\nTest 2 - add random number" << std::endl;
		Span sp = Span(25);
		sp.addRandomNumbers(25, -500, 500);
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "\nTest 3" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	Span sp = Span(1);
	try {
		std::cout << "\nTest 4 - empty span" << std::endl;
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "\nTest 5 - exceed limit" << std::endl;
		sp.addRandomNumbers(6);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "\nTest 6 - span is full" << std::endl;
		sp.addNumber(42);
		sp.addNumber(42);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
