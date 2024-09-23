/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:24:19 by irozhkov          #+#    #+#             */
/*   Updated: 2024/08/10 14:13:32 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int                 _fp_val;
		static const int    _fract_bits;

	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator = (const Fixed& src);
		~Fixed();
	
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif
