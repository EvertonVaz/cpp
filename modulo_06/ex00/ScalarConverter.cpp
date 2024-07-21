/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <egeraldo@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:15:52 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/21 20:52:50 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <cstdlib>
#include <limits>
#include <cmath>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::converterToChar(std::string str) {
	try {
		double d = std::strtod(str.c_str(), NULL);

		if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
			throw std::invalid_argument("impossible");
		if (std::isnan(d) || std::isinf(d))
			throw std::invalid_argument("impossible");
		if (!std::isprint(static_cast<char>(d)))
			throw std::invalid_argument("Non displayable");
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	} catch (std::exception &e) {
		std::cout << "char: " << e.what() << std::endl;
	}
}

void ScalarConverter::converterToInt(std::string str) {
	try {
		double num = std::strtod(str.c_str(), NULL);

		if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
			throw std::invalid_argument("impossible");
		if (std::isnan(num) || std::isinf(num))
			throw std::invalid_argument("impossible");

		std::cout << "int: " << static_cast<int>(num) << std::endl;
	} catch (std::exception &e) {
		std::cout << "int: " << e.what() << std::endl;
	}
}

void ScalarConverter::converterToFloat(std::string str) {
	size_t dotPsicion = str.find(".");
	bool zero = false;
	if (str[dotPsicion + 1] == '0' || str[dotPsicion + 1] == 'f')
		zero = true;
	try {
		float f = std::strtof(str.c_str(), NULL);

		if (f < std::numeric_limits<float>::min() || f > std::numeric_limits<float>::max())
			throw std::invalid_argument("impossible");
		if (std::isnan(f) || std::isinf(f))
			throw std::invalid_argument("impossible");
		if (zero)
			std::cout << "float: " << static_cast<float>(f) << ".0f" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(f) << "f" << std::endl;
	} catch (std::exception &e) {
		std::cout << "float: " << e.what() << std::endl;
	}
}

void ScalarConverter::converterToDouble(std::string str) {
	size_t dotPsicion = str.find(".");
	bool zero = false;
	if (str[dotPsicion + 1] == '0' || str[dotPsicion + 1] == 'f')
		zero = true;
	try {
		double d = std::strtod(str.c_str(), NULL);

		if (d < std::numeric_limits<double>::min() || d > std::numeric_limits<double>::max())
			throw std::invalid_argument("impossible");
		if (std::isnan(d) || std::isinf(d))
			throw std::invalid_argument("impossible");
		if (zero)
			std::cout << "double: " << static_cast<double>(d) << ".0" << std::endl;
		else
			std::cout << "double: " << static_cast<double>(d) << std::endl;
	} catch (std::exception &e) {
		std::cout << "double: " << e.what() << std::endl;
	}
}

void ScalarConverter::converter(std::string str) {
	ScalarConverter sc;

	sc.converterToChar(str);
	sc.converterToInt(str);
	sc.converterToFloat(str);
	sc.converterToDouble(str);
}
