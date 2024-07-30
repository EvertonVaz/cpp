/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <egeraldo@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:59:32 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/30 13:22:55 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <limits>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "../colors.hpp"

BitcoinExchange::BitcoinExchange() {
	loadDataBase("data.csv");
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_exchangeRates = other._exchangeRates;
	}
	return *this;
}

void BitcoinExchange::loadDataBase(const std::string &dataBaseFile) {
	std::ifstream file(dataBaseFile.c_str());
	if (!file.is_open()) {
		throw std::runtime_error("Error: could not open file ");
	}

	std::string line;
	while (std::getline(file, line)) {
		std::stringstream dataStr(line);
		std::string date;
		double rate;

		if (std::isdigit(dataStr.peek()) && getline(dataStr, date, ',')) {
			dataStr >> rate;
			_exchangeRates[date] = rate;
		}
	}
	file.close();
}

double BitcoinExchange::getExchangeRates(const std::string &date) const {
	std::map<std::string, double>::const_iterator it = _exchangeRates.find(date);
	if (it != _exchangeRates.end()) {
		return it->second;
	}

	it = _exchangeRates.lower_bound(date);
	if (it == _exchangeRates.begin()) {
		throw std::runtime_error("date not found ");
	}

	--it;
	return it->second;
}

bool isValidDate(const std::string &date) {
	std::string error = "bad input => ";

	if (date == "date")
		return (false);
	if (date.empty())
		throw std::runtime_error("empty date.");
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		throw std::runtime_error(error + date);
	if (date.substr(0, 4) < "1900" || date.substr(0, 4) > "2024")
		throw std::runtime_error(error + date);
	if (date.substr(5, 2) < "01" || date.substr(5, 2) > "12")
		throw std::runtime_error(error + date);
	if (date.substr(8, 2) < "01" || date.substr(8, 2) > "31")
		throw std::runtime_error(error + date);
	return true;
}

bool isInvalidValue(double value) {
	if (value < 0)
		throw std::runtime_error("not a positive number.");
	if (value > std::numeric_limits<int>::max())
		throw std::runtime_error("too larger a number.");
	return false;
}

void remove_spaces(std::string &date) {
	std::string::iterator end_pos;

	end_pos = std::remove(date.begin(), date.end(), ' ');
	date.erase(end_pos, date.end());
}

void BitcoinExchange::printData(std::string pathInputFile) const {
	std::ifstream file(pathInputFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file ");

	std::string line;
	while (std::getline(file, line)) {
		std::stringstream dataStr(line);
		std::string date;
		double value;

		try {
			getline(dataStr, date, '|');
			remove_spaces(date);
			if (isValidDate(date)) {
				if (!(dataStr >> value))
					throw std::runtime_error("bad input => " + line);
				if (isInvalidValue(value)) throw ;
				double rate = getExchangeRates(date);
				std::cout << date << " => " << rate * value << std::endl;
			}
		} catch (const std::exception &e) {
			std::cerr << "Error: " << RED << e.what() << END << std::endl;
		}
	}
}
