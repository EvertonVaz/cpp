/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:19:13 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/19 16:19:52 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Form.hpp"
#include "../colors.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {}

Form::Form(const std::string &_name, const int _gradeToSign, const int _gradeToExec) :
		_name(_name), _signed(false), _gradeToSign(_gradeToSign), _gradeToExec(_gradeToExec) {
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src) :
	_name(src._name), _signed(src._signed),
	_gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {
	*this = src;

}

Form::~Form() {}

Form Form::operator=(const Form &src) {
	if (this != &src) {
		_signed = src._signed;
	}
	return *this;
}

const std::string Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExec() const {
	return _gradeToExec;
}

void Form::beSign(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return RED "Grade is too high!" END;
}

const char *Form::GradeTooLowException::what() const throw() {
	return RED "Grade is too low!" END;
}

std::ostream& operator<<(std::ostream &out, const Form &form) {
    out << "Form: " << form.getName()
        << ", Signed: " << (form.getSigned() ? "Yes" : "No")
        << ", Grade to Sign: " << form.getGradeToSign()
        << ", Grade to Execute: " << form.getGradeToExec();
    return out;
}