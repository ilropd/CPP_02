/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:24:19 by irozhkov          #+#    #+#             */
/*   Updated: 2024/08/13 15:03:46 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int                 _fp_val;
		static const int    _fract_bits;

	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float fl);
		Fixed(const Fixed& copy);
		Fixed& operator = (const Fixed& src);
		~Fixed();
	
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
    int		toInt( void ) const;
	static	Fixed& min(Fixed& first, Fixed& second);
	static const Fixed& min(const Fixed& first, const Fixed& second);
	static Fixed& max(Fixed& first, Fixed& second);
	static const Fixed& max(const Fixed& first, const Fixed& second);

	bool operator>(const Fixed& fixedA) const;
	bool operator<(const Fixed& fixedA) const;
	bool operator>=(const Fixed& fixedA) const;
	bool operator<=(const Fixed& fixedA) const;
	bool operator==(const Fixed& fixedA) const;
	bool operator!=(const Fixed& fixedA) const;

	Fixed operator+(const Fixed& fixedA) const;
	Fixed operator-(const Fixed& fixedA) const;
	Fixed operator*(const Fixed& fixedA) const;
	Fixed operator/(const Fixed& fixedA) const;

	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);
};

std::ostream &operator<<(std::ostream &os, const Fixed& obj);

#endif
