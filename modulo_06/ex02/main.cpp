/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:46:41 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/23 10:58:09 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {
	srand(time(NULL));
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;

	std::cout << "\nType not defined" << std::endl;
	identify(NULL);
	return 0;
}