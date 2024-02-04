/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:22:31 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/30 10:54:17 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H
#include <iostream>
#include <cmath>
#include <fstream>

class Fixed
{
	private:
		int	fixed_value;
		static const int _fract_bits;
	public:
		Fixed();
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed& copy);
		~Fixed();
		Fixed &operator=(const Fixed &src);
		float toFloat(void)const;
		int toInt(void)const;
		int getRawBits(void)const;
		void setRawBits(int const raw);
};

std::ostream&	operator<<(std::ostream & out, Fixed const & fixed);

#endif