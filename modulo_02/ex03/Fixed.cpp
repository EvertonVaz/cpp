/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:09:11 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/02 15:27:26 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
}

Fixed::Fixed(const int value) {
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &copy) {
	*this = copy;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &copy) {
	_fixedPointValue = copy.getRawBits();
	return *this;
}

Fixed &Fixed::operator+(const Fixed &copy) {
	_fixedPointValue += copy.getRawBits();
	return *this;
}

Fixed &Fixed::operator-(const Fixed &copy) {
	_fixedPointValue -= copy.getRawBits();
	return *this;
}

Fixed &Fixed::operator*(const Fixed &copy) {
	_fixedPointValue = (_fixedPointValue * copy.getRawBits()) >> _fractionalBits;
	return *this;
}

Fixed &Fixed::operator/(const Fixed &copy) {
	_fixedPointValue = (_fixedPointValue << _fractionalBits) / copy.getRawBits();
	return *this;
}

Fixed &Fixed::operator++() {
	_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--() {
	_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

bool Fixed::operator>(const Fixed &copy) const {
	return _fixedPointValue > copy.getRawBits();
}

bool Fixed::operator>=(const Fixed &copy) const {
	return _fixedPointValue >= copy.getRawBits();
}

bool Fixed::operator<(const Fixed &copy) const {
	return _fixedPointValue < copy.getRawBits();
}

bool Fixed::operator<=(const Fixed &copy) const {
	return _fixedPointValue <= copy.getRawBits();
}

bool Fixed::operator==(const Fixed &copy) const {
	return _fixedPointValue == copy.getRawBits();
}

bool Fixed::operator!=(const Fixed &copy) const {
	return _fixedPointValue != copy.getRawBits();
}

int	Fixed::getRawBits(void) const {
	return _fixedPointValue;
}

void	Fixed::setRawBits(int const raw) {
	_fixedPointValue = raw;
}

float	Fixed::toFloat(void) const {
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

int	Fixed::toInt(void) const {
	return _fixedPointValue >> _fractionalBits;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return out;
}
