/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:19:57 by irozhkov          #+#    #+#             */
/*   Updated: 2024/08/14 18:06:08 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>
# include <string>

class Point
{
	private:
		Fixed	_px;
		Fixed	_py;

	public:
		Point();
		Point(const float px, const float py);
		Point(const Point& copy);
		Point& operator=(const Point& src);
		~Point();

		const Fixed &getPX(void)const;
		const Fixed &getPY(void)const;

		bool operator==(const Point& pointA) const;
};

std::ostream &operator<<(std::ostream &os, const Point& obj);

#endif
