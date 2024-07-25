/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:22:59 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/25 15:29:58 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

Span::Span() : _N(0), _size(0) {}

Span::Span(unsigned int N) : _N(N), _size(0) {
	srand(static_cast<unsigned int>(time(0)));
	_vec.reserve(N);
}

Span::Span(Span const &src) {
	*this = src;
}

Span::~Span() {}

Span &Span::operator=(Span const &rhs) {
	if (this != &rhs) {
		_N = rhs._N;
		_size = rhs._size;
		_vec = rhs._vec;
	}
	return *this;
}

void Span::addNumber(int n) {
	if (_size >= _N)
		throw std::out_of_range("Span is full");
	_vec.push_back(n);
	_size++;
}

int generateRandomNumber(int min, int max) {
    return min + std::rand() % (max - min + 1);
}

void Span::addRandomNumbers(unsigned int count, int min, int max) {
    if (_size + count > _N)
        throw std::range_error("Range exceeds the limit");
    for (unsigned int i = 0; i < count; i++)
		_vec.push_back(generateRandomNumber(min, max));
    _size += count;
}

int Span::shortestSpan(void) {
	if (_size <= 1)
		throw std::range_error("Span is empty or has only one element");
	std::sort(_vec.begin(), _vec.end());

	int min = _vec[1] - _vec[0];
	int shortest = min;
	for (unsigned int i = 2; i < _size; i++) {
		min = _vec[i] - _vec[i - 1];
		if (min < shortest)
			shortest = min;
	}
	return shortest;
}

int Span::longestSpan(void) {
	if (_size <= 1)
		throw std::range_error("Span is empty or has only one element");
	std::sort(_vec.begin(), _vec.end());
	return _vec[_size - 1] - _vec[0];
}
