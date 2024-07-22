/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:08:09 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/22 12:30:14 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("default", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :
	AForm("PresidentialPardonForm", 25, 5), _target(src._target) {
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	if (this != &src) {
		this->_target = src._target;
	}
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (this->getSigned() == false) {
		std::cout << this->getName() << ": ";
		throw PresidentialPardonForm::FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExec()) {
		std::cout << this->getName() << ": ";
		throw PresidentialPardonForm::GradeTooLowException();
	}
	std::cout << "Informs that, " << _target;
	std::cout << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
