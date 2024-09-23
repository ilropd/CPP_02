/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:24:19 by irozhkov          #+#    #+#             */
/*   Updated: 2024/08/12 17:56:59 by irozhkov         ###   ########.fr       */
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
};

std::ostream &operator<<(std::ostream &os, const Fixed& obj); 

#endif
