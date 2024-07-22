/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:00:25 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/22 16:09:45 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
# define FORM_HPP

class Form;

#include "Bureaucrat.hpp"
#include <iostream>

class Form {
	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExec;
		bool _signed;

	public:
		Form();
		Form(const std::string &name, const int gradeToSign, const int gradeToExec);
		Form(const Form &src);
		~Form();
		Form operator=(const Form &src);

		const std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;

		void beSign(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif