/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:30:03 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/22 16:32:55 by egeraldo         ###   ########.fr       */
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
		PresidentialPardonForm f1("Presidential");
		RobotomyRequestForm f2("Robotmy");
		ShrubberyCreationForm f3("Shrubbery");
		std::cout << "\n\n" << b1 << std::endl;
		b1.signForm(f1);
		b1.executeForm(f1);
		b1.signForm(f2);
		b1.executeForm(f2);
		b1.signForm(f3);
		b1.executeForm(f3);

		std::cout << "\n\n" << b2 << std::endl;
		b2.signForm(f3);
		b2.executeForm(f2);
		b2.executeForm(f3);
		b2.executeForm(f1);
	} catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
