/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:22:52 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/30 11:01:01 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed(): fixed_value(0)
{
}

Fixed::Fixed(const int input)
{
	this->fixed_value = input << this->_fract_bits;
}

Fixed::Fixed(const float input)
{
	this->fixed_value = roundf(input * (1 << this->_fract_bits));
}

Fixed::Fixed(const Fixed &copy)
{
	this->fixed_value = copy.getRawBits();
	return ;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		this->fixed_value = src.getRawBits();

	return *this;
}

float	Fixed::toFloat(void)const
{
	return ((float)this->fixed_value / (float)(1 << this->_fract_bits));
}

int	Fixed::toInt(void)const
{
	return (this->fixed_value >> this->_fract_bits);
}

int	Fixed::getRawBits(void)const
{
	return (this->fixed_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_value = raw;
}

bool	Fixed::operator>(Fixed fixed) const
{
	return(this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed) const
{
	return(this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<(Fixed fixed) const
{
	return(this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed) const
{
	return(this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed) const
{
	return(this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed) const
{
	return(this->toFloat() != fixed.toFloat());
}

float	Fixed::operator+(Fixed fixed) const
{
	return(this->toFloat() + fixed.toFloat());
}



float	Fixed::operator-(Fixed fixed) const
{
	return(this->toFloat() - fixed.toFloat());
}

float	Fixed::operator/(Fixed fixed) const
{
	return(this->toFloat() / fixed.toFloat());
}

float	Fixed::operator*(Fixed fixed) const
{
	return(this->toFloat() * fixed.toFloat());
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	else
		return (b);
}

Fixed	Fixed::operator++()
{
	this->fixed_value++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->fixed_value--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed buff = *this;
	++this->fixed_value;
	return (buff);
}

Fixed	Fixed::operator--(int)
{
	Fixed buff = *this;
	--this->fixed_value;
	return (buff);
}

std::ostream	&operator<<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
}