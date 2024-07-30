/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <egeraldo@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:30:16 by etovaz            #+#    #+#             */
/*   Updated: 2024/07/30 17:22:35 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdexcept>
#include <sstream>
#include <cstdlib>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &rpn) {
	*this = rpn;
}

RPN &RPN::operator=(const RPN &rpn) {
	if (this != &rpn) {
		_stack = rpn._stack;
	}
	return *this;
}

bool RPN::_isOperator(const std::string &token) const {
	return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::_applyOperator(const std::string &op, int a, int b) const {
	if (op == "+") return a + b;
	if (op == "-") return a - b;
	if (op == "*") return a * b;
	if (op == "/") {
		if (b == 0) throw std::invalid_argument("Division by zero");
		return a / b;
	}
	throw std::invalid_argument("Invalid operator");
}

int RPN::_getTop(void) {
	if (_stack.empty())
		throw std::invalid_argument("Invalid expression");
	int top = _stack.top();
	_stack.pop();
	return top;
}

int RPN::evaluate(const std::string &expression) {
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (std::isdigit(token[0])) {
			_stack.push(std::atoi(token.c_str()));
			continue;
		}
		if (_isOperator(token)) {
			if (_stack.size() < 2)
				throw std::invalid_argument("Invalid expression");
			int b = _getTop();
			int a = _getTop();
			int result = _applyOperator(token, a, b);
			_stack.push(result);
		} else {
			throw std::invalid_argument("Invalid operator");
		}
	}
	if (_stack.size() != 1)
		throw std::invalid_argument("Invalid expression");
	return _stack.top();
}