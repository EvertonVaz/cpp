/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:08:09 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/22 16:35:22 by egeraldo         ###   ########.fr       */
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
	if (this->getSigned() == false)
		throw PresidentialPardonForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw PresidentialPardonForm::GradeTooLowException();

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
