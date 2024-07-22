/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:07:53 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/22 14:57:26 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern {
	private:
		AForm *createRobotForm(std::string target);
		AForm *createPresidentialForm(std::string target);
		AForm *createShrubberyForm(std::string target);
		
	public:
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern operator=(const Intern &src);

		AForm *makeForm(const std::string &formName, const std::string &target);

		class FormNotFoundException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif