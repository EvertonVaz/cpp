/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:39:05 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/23 11:13:57 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base *generate(void) {
	int random = rand() % 3;

	switch (random) {
		case 0:
			std::cout << "A class generated" << std::endl;
			return new A;
		case 1:
			std::cout << "B class generated" << std::endl;
			return new B;
		case 2:
			std::cout << "C class generated" << std::endl;
			return new C;
		default:
			return NULL;
	}
}

void identify(Base *p) {
	if (p == NULL) {
		std::cout << "Type: Unknown" << std::endl;
		return ;
	}
	identify(*p);
}

void identify(Base &p) {
	std::string type = "Unknown";
	try {
        (void)dynamic_cast<A&>(p);
        type = "A";
    } catch (std::exception &e) {}

    try {
        (void)dynamic_cast<B&>(p);
        type = "B";
    } catch (std::exception &e) {}

    try {
        (void)dynamic_cast<C&>(p);
		type = "C";
    } catch (std::exception &e) {}

	std::cout << "Type: " << type << std::endl;
}