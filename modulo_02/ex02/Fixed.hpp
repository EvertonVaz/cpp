/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:01:11 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/02 15:24:04 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed				&operator=(const Fixed &copy);
		Fixed				&operator+(const Fixed &copy);
		Fixed				&operator-(const Fixed &copy);
		Fixed				&operator*(const Fixed &copy);
		Fixed				&operator/(const Fixed &copy);
		Fixed				&operator++();
		Fixed				operator++(int);
		Fixed				&operator--();
		Fixed				operator--(int);
		bool				operator>(const Fixed &copy) const;
		bool				operator>=(const Fixed &copy) const;
		bool				operator<(const Fixed &copy) const;
		bool				operator<=(const Fixed &copy) const;
		bool				operator==(const Fixed &copy) const;
		bool				operator!=(const Fixed &copy) const;
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a,const Fixed &b);
		static const Fixed	&max(const Fixed &a,const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif