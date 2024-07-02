/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:08:05 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/02 16:49:09 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::Point(Point const &copy) : _x(copy._x), _y(copy._y) {}

Point::~Point() {}

Point &Point::operator=(const Point &copy) {
	(Fixed)this->_x = copy._x;
	(Fixed)this->_y = copy._y;
    return *this;
}

float Point::getFloatX() const {
	return _x.toFloat();
}

float Point::getFloatY() const {
	return _y.toFloat();
}

