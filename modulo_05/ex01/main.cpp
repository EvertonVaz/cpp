/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:30:03 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/19 16:32:07 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Bureaucrat.hpp"
#include "class/Form.hpp"
#include "../colors.hpp"

int main() {
	try {
		std::cout << YELLOW "Creating a Bureaucrat with a grade of 0" END<< std::endl;
		Bureaucrat b1("Peter", 0);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << YELLOW "Creating a Bureaucrat with a grade of 151" END<< std::endl;
		Bureaucrat b1("Peter", 151);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << YELLOW "Testing increment grade" END<< std::endl;
		Bureaucrat b1("Peter", 1);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << YELLOW "Testing decrement grade" END<< std::endl;
		Bureaucrat b1("Peter", 150);
		std::cout << b1 << std::endl;
		b1.decrementGrade();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

    try {
		Bureaucrat b1("Peter", 2);
		Form f1("FormA", 3, 50);

		std::cout << b1 << std::endl;
		std::cout << f1 << std::endl;

		b1.signForm(f1);
		std::cout << f1 << std::endl;
		Bureaucrat b2("Parker", 3);
		Form f2("FormB", 2, 50);

		std::cout << b2 << std::endl;
		std::cout << f2 << std::endl;

		b2.signForm(f2);
		std::cout << f2 << std::endl;
	} catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}
