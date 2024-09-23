/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:18:02 by irozhkov          #+#    #+#             */
/*   Updated: 2024/08/15 13:31:47 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main() {
    Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
    Point c(0.0f, 5.0f);

    Point point1(1.0f, 1.0f); // Inside the triangle
    Point point2(5.0f, 5.0f); // Outside the triangle
    Point point3(0.0f, 2.5f); // On the edge of the triangle == outside
	Point point4(5.0f, 0.0f); // In the vertex b of the triangle == outside

    bool isInside1 = bsp(a, b, c, point1);
    bool isInside2 = bsp(a, b, c, point2);
    bool isInside3 = bsp(a, b, c, point3);
	bool isInside4 = bsp(a, b, c, point4);

    std::cout << "Point (1.0, 1.0) is " << (isInside1 ? "inside" : "outside") << " the triangle." << std::endl;
    std::cout << "Point (5.0, 5.0) is " << (isInside2 ? "inside" : "outside") << " the triangle." << std::endl;
    std::cout << "Point (0.0, 2.5) is " << (isInside3 ? "inside" : "outside") << " the triangle." << std::endl;
	std::cout << "Point (5.0, 0.0) is " << (isInside4 ? "inside" : "outside") << " the triangle." << std::endl;

    return 0;
}
