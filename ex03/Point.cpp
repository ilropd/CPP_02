/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:36:23 by irozhkov          #+#    #+#             */
/*   Updated: 2024/08/15 13:20:17 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _px(0), _py(0)
{
//  std::cout << "Default Point constructor called" << std::endl;
}

Point::Point(const float px, const float py) : _px(px), _py(py)
{
//  std::cout << "Float Point constructor called" << std::endl;
}

Point::Point(const Point& copy) : _px(copy.getPX()), _py(copy.getPY())
{
//  std::cout << "Copy Point constructor called" << std::endl;
}

Point &Point::operator=(const Point& src)
{
//  std::cout << "Copy assignment Point operator called" << std::endl;
	if (this != &src)
	{
		this->_px = src.getPX();
		this->_py = src.getPY();
	}
	return (*this);
}

Point::~Point()
{
//  std::cout << "Destructor Point called" << std::endl;
}

const Fixed &Point::getPX(void)const
{
	return (this->_px);
}

const Fixed &Point::getPY(void)const
{
    return (this->_py);
}

bool Point::operator==(const Point& pointA) const
{
	return ((this->_px == pointA._px) && (this->_py == pointA._py));
}

std::ostream &operator<<(std::ostream &os, const Point& obj)
{
	os << "_px: " << obj.getPX() << " | _py: " << obj.getPY() << std::endl;
	return (os);
}
