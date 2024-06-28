/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:57:55 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/28 11:06:04 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;

	std::cout << "Address of the string: " << &str << std::endl;
	std::cout << "Address of the string using strPTR: " << strPTR << std::endl;
	std::cout << "Address of the string using strREF: " << &strREF << std::endl;

	std::cout << "String: " << str << std::endl;
	std::cout << "String using *strPTR: " << *strPTR << std::endl;
	std::cout << "String using strREF: " << strREF << std::endl;
}