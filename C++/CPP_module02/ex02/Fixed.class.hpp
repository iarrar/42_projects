/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:22:57 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/30 00:06:06 by iarrar           ###   ########.fr       */
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
		int fixed_value;
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
		bool				operator>(Fixed fixed) const;
		bool				operator>=(Fixed fixed) const;
		bool				operator<=(Fixed fixed) const;
		bool				operator<(Fixed fixed) const;
		bool				operator==(Fixed fixed) const;
		bool				operator!=(Fixed fixed) const;
		float				operator+(Fixed fixed) const;
		float				operator-(Fixed fixed) const;
		float				operator/(Fixed fixed) const;
		float				operator*(Fixed fixed) const;
		static Fixed &		min(Fixed &a, Fixed &b);
		static const Fixed &min(Fixed const &a, Fixed const &b);
		static Fixed &		max(Fixed &a, Fixed &b);
		static const Fixed &max(Fixed const &a, const Fixed &b);
		Fixed				operator++();
		Fixed				operator--();
		Fixed				operator++(int);
		Fixed				operator--(int);


};


std::ostream&	operator<<(std::ostream & out, Fixed const & fixed);

#endif