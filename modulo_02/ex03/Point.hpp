/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:02:16 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/02 16:50:19 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point();
		Point(float const x, float const y);
		Point(Point const &copy);
		~Point();

		Point &operator=(Point const &copy);

		float getFloatX() const;
		float getFloatY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif