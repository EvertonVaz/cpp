/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:15:52 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/22 17:13:26 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
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

int	countAfterDot(std::string str) {

	if (str.find('f') != std::string::npos)
		return (str.size() - str.find('.') - 2);
	return (str.size() - str.find('.') - 1);
}

void ScalarConverter::converterToFloat(std::string str) {
    try {
		int precision = countAfterDot(str);
		precision = (precision == 0) ? 1 : precision;
        float f = std::strtof(str.c_str(), NULL);

        if (f < -std::numeric_limits<float>::max() || f > std::numeric_limits<float>::max())
            throw std::invalid_argument("impossible");
        if (std::isnan(f) || std::isinf(f))
            throw std::invalid_argument("nanf");

        std::cout << "float: ";
        std::cout << std::fixed << std::setprecision(precision) << f << "f" << std::endl;
    } catch (std::exception &e) {
        std::cout << "float: " << e.what() << std::endl;
    }
}

void ScalarConverter::converterToDouble(std::string str) {
	try {
		int precision = countAfterDot(str);
		precision = (precision == 0) ? 1 : precision;
		double d = std::strtod(str.c_str(), NULL);

		if (d < -std::numeric_limits<double>::max() || d > std::numeric_limits<double>::max())
			throw std::invalid_argument("impossible");
		if (std::isnan(d) || std::isinf(d))
			throw std::invalid_argument("nan");

		std::cout << "double: ";
		std::cout << std::fixed << std::setprecision(precision)<< static_cast<double>(d) << std::endl;
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
