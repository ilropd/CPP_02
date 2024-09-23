/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:49:22 by irozhkov          #+#    #+#             */
/*   Updated: 2024/08/13 16:49:43 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fract_bits = 8;

Fixed::Fixed() : _fp_val(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) : _fp_val(i * (1 << (this->_fract_bits)))
{
//	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fl) : _fp_val(roundf(fl * (1 << this->_fract_bits)))
{
//	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator = (const Fixed &src)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_fp_val = src.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
//	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fp_val);
}

void	Fixed::setRawBits( int const raw )
{
	this->_fp_val = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_fp_val / (float)(1 << this->_fract_bits));
}

int		Fixed::toInt( void ) const
{
	return (this->_fp_val / (1 << this->_fract_bits));
}

Fixed	&Fixed::min(Fixed& first, Fixed& second)
{
	if (first.toFloat() <= second.toFloat()) return first;
	else return second;
}

const Fixed   &Fixed::min(const Fixed& first, const Fixed& second)
{
    if (first.toFloat() <= second.toFloat()) return first;
	else return second;
}

Fixed   &Fixed::max(Fixed& first, Fixed& second)
{
    if (first.toFloat() >= second.toFloat()) return first;
	else return second;
}

const Fixed   &Fixed::max(const Fixed& first, const Fixed& second)
{
	if (first.toFloat() >= second.toFloat()) return first;
    else return second;
}

bool	Fixed::operator>(const Fixed& fixedA) const
{
	return (this->toFloat() > fixedA.toFloat());
}

bool    Fixed::operator<(const Fixed& fixedA) const
{
    return (this->toFloat() < fixedA.toFloat());
}

bool    Fixed::operator>=(const Fixed& fixedA) const
{
    return (this->toFloat() >= fixedA.toFloat());
}

bool    Fixed::operator<=(const Fixed& fixedA) const
{
    return (this->toFloat() <= fixedA.toFloat());
}

bool    Fixed::operator==(const Fixed& fixedA) const
{
    return (this->toFloat() == fixedA.toFloat());
}

bool    Fixed::operator!=(const Fixed& fixedA) const
{
    return (this->toFloat() != fixedA.toFloat());
}

Fixed	Fixed::operator+(const Fixed& fixedA) const
{
	return (Fixed(this->toFloat() + fixedA.toFloat()));
}

Fixed   Fixed::operator-(const Fixed& fixedA) const
{
    return (Fixed(this->toFloat() - fixedA.toFloat()));
}

Fixed   Fixed::operator*(const Fixed& fixedA) const
{
    return (Fixed(this->toFloat() * fixedA.toFloat()));
}

Fixed   Fixed::operator/(const Fixed& fixedA) const
{
	if (fixedA.toFloat() != 0)
		return (Fixed(this->toFloat() / fixedA.toFloat()));
	else
	{
		std::cout << "It cannot be divided by zero" << std::endl;
		return (Fixed());
	}
}

Fixed	Fixed::operator++()
{
	this->_fp_val++;
	return (*this);
}

Fixed   Fixed::operator++(int)
{
	Fixed temp = *this;
    this->_fp_val++;
    return (temp);
}

Fixed   Fixed::operator--()
{
    this->_fp_val--;
    return (*this);
}

Fixed   Fixed::operator--(int)
{
    Fixed temp = *this;
    this->_fp_val--;
    return (temp);
}


std::ostream &operator<<(std::ostream &os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
