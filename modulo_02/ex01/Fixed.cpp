/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:09:11 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/02 12:22:50 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy) {
	std::cout << "Assignation operator called" << std::endl;
	_fixedPointValue = copy.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
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

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return out;
}
