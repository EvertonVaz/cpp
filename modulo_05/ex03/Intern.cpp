/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:09:23 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/22 16:39:31 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Intern.hpp"
#include "class/PresidentialPardonForm.hpp"
#include "class/RobotomyRequestForm.hpp"
#include "class/ShrubberyCreationForm.hpp"
#include "../colors.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern::~Intern() {}

Intern Intern::operator=(const Intern &src) {
	(void)src;
	return *this;
}

AForm *Intern::createRobotForm(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialForm(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::createShrubberyForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
	std::string name[3] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};
	AForm *(Intern::*forms[3])(std::string) = {
		&Intern::createRobotForm,
		&Intern::createPresidentialForm,
		&Intern::createShrubberyForm
	};

	int i;
	for (i = 0; i < 3; i++) {
		if (name[i] == formName) {
			std::cout << CYAN "Intern creates " << formName << " Form." END << std::endl;
			return (this->*forms[i])(target);
		}
	}
	std::cerr << formName << ": ";
	throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
	return RED "Form not found" END;
}