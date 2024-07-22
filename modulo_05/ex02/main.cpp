/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:30:03 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/22 12:49:18 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/PresidentialPardonForm.hpp"
#include "class/RobotomyRequestForm.hpp"
#include "class/ShrubberyCreationForm.hpp"
#include "class/Bureaucrat.hpp"
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
		Bureaucrat b2("Parker", 25);
		PresidentialPardonForm f1("Lula");
		RobotomyRequestForm f2("Chuck Norris");
		ShrubberyCreationForm f3("Bob Marley");
		b1.signForm(f1);
		f1.execute(b1);

		b1.signForm(f2);
		f2.execute(b1);

		b2.signForm(f3);
		f3.execute(b1);
		f2.execute(b2);
		f3.execute(b2);
		f1.execute(b2);
	} catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}
