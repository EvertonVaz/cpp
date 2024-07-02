/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:50:23 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/02 17:33:10 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed calculateArea(Point const &a, Point const &b, Point const &c) {
	float termA = a.getFloatX() * (b.getFloatY() - c.getFloatY());
	float termB = b.getFloatX() * (c.getFloatY() - a.getFloatY());
	float termC = c.getFloatX() * (a.getFloatY() - b.getFloatY());
	Fixed area = std::abs((termA + termB + termC) / 2.0f);
	return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed areaABC = calculateArea(a, b, c);
    Fixed areaPAB = calculateArea(point, a, b);
    Fixed areaPBC = calculateArea(point, b, c);
    Fixed areaPCA = calculateArea(point, c, a);

    if (areaPAB == 0 || areaPBC == 0 || areaPCA == 0) {
        return false;
    }
    return (areaPAB + areaPBC + areaPCA).toFloat() == areaABC.toFloat();
}