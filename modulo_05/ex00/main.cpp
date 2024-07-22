/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:30:03 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/19 15:49:50 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Bureaucrat.hpp"

int main(void) {
	Bureaucrat b1("Peter", 1);
	Bureaucrat b2("Jane", 150);

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;

	try {
		Bureaucrat b3("Error1", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b4("Error2", 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		b1.decrementGrade();
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		b2.incrementGrade();
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;
		b2.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}