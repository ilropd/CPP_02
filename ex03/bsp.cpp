/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:01:17 by irozhkov          #+#    #+#             */
/*   Updated: 2024/08/15 13:24:09 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

float	bsp_cross( Point const p1, Point const p2, Point const p3)
{
	return ((p2.getPX().toFloat() - p1.getPX().toFloat()) * (p3.getPY().toFloat() - p1.getPY().toFloat()) - (p2.getPY().toFloat() - p1.getPY().toFloat()) * (p3.getPX().toFloat() - p1.getPX().toFloat()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if ((point == a) || (point == b) || (point == c)) return false;

	float	cross_p1 = bsp_cross(a, b, point);
	float	cross_p2 = bsp_cross(b, c, point);
	float	cross_p3 = bsp_cross(c, a, point);

//	std::cout << "cross_p1: " << cross_p1 << " | cross_p2: " << cross_p2 << " | cross_p3: " << cross_p3 << std::endl; 
	bool	zero = (cross_p1 == 0.0f || cross_p2 == 0.0f || cross_p3 == 0.0f);
	bool	pos = (cross_p1 > 0) || (cross_p2 > 0) || (cross_p3 > 0);
	bool	neg = (cross_p1 < 0) || (cross_p2 < 0) || (cross_p3 < 0);

	return !(zero || (pos && neg));
}
