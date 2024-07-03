/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:35:22 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/03 09:22:23 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "../colors.hpp"

void	check_point(bool bsp) {
	if (bsp) {
		std::cout << GREEN "The point is inside the triangle." END << std::endl;
	} else {
		std::cout << RED "The point is outside the triangle." END << std::endl;
	}
}

int main( void ) {
	Point a(2.0f, 2.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);
    Point inside1(3.0f, 3.0f);
    Point inside2(1.0f, 7.0f);
    Point outside1(1.0f, 9.0f);
    Point outside2(-1.0f, -1.0f);

    check_point(bsp(a, b, c, inside1));
	check_point(bsp(a, b, c, inside2));
	check_point(bsp(a, b, c, outside1));
	check_point(bsp(a, b, c, outside2));

	std::cout << CYAN "\nAll points inside the triangle" END << std::endl;
	for(int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++){
			if(bsp(a, b, c, Point((float)x, (float)y))) {
				std::cout << GREEN "The point x: " << x;
				std::cout << ", y: " << y << " is inside the triangle." END << std::endl;
			}
		}
	}
	check_point(bsp(a, b, c, Point(8.0f, 2.0f)));
    return 0;
}
