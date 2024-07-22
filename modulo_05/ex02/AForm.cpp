/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:19:13 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/22 12:41:01 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/AForm.hpp"
#include <cstdlib>
#include "../colors.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {
	srand(static_cast<unsigned int>(time(0)));
}

AForm::AForm(const std::string &_name, const int _gradeToSign, const int _gradeToExec) :
		_name(_name), _signed(false), _gradeToSign(_gradeToSign), _gradeToExec(_gradeToExec) {
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw AForm::GradeTooLowException();
	srand(static_cast<unsigned int>(time(0)));
}

AForm::~AForm() {}

const std::string AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExec() const {
	return _gradeToExec;
}

void AForm::beSign(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return RED  "Grade is too high!" END;
}

const char *AForm::GradeTooLowException::what() const throw() {
	return RED "Grade is too low!" END;
}

const char *AForm::FormNotSignedException::what() const throw() {
	return RED "Form is not signed!" END;
}

std::ostream& operator<<(std::ostream &out, const AForm &form) {
    out << "AForm: " << form.getName()
        << ", Signed: " << (form.getSigned() ? "Yes" : "No")
        << ", Grade to Sign: " << form.getGradeToSign()
        << ", Grade to Execute: " << form.getGradeToExec();
    return out;
}