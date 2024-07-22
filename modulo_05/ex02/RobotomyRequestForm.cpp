/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:58:42 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/22 13:03:44 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/RobotomyRequestForm.hpp"
#include "../colors.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
	AForm("RobotomyRequestForm", 72, 45), _target(src._target) {
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	if (this != &src) {
		_target = src._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {

	if (this->getSigned() == false) {
		std::cout << this->getName() << ": ";
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExec()) {
		std::cout << this->getName() << ": ";
		throw AForm::GradeTooLowException();
	}
	std::cout << "Brrrrrrrrr~~~~~   Brrrrrrrrr~~~~~   Brrrrrrrrr~~~~~" << std::endl;
	if (rand() % 2 == 1)
		std::cout << GREEN << _target << ": has been robotomized successfully" << END << std::endl;
	else
		std::cout << UNDER_YELLOW << _target << ": The robotomy is failed" << END << std::endl;
}