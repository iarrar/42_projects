/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:22:26 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/30 10:54:50 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed(): fixed_value(0)
{
	std::cout << "Fixed Default Constructor called" << std::endl;
}

Fixed::Fixed(const int input)
{
	std::cout << "Fixed Int Constructor called" << std::endl;
	this->fixed_value = input << this->_fract_bits;
}

Fixed::Fixed(const float input)
{
	std::cout << "Fixed Float Constructor called" << std::endl;
	this->fixed_value = roundf(input * (1 << this->_fract_bits));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Fixed Copy Constructor called" << std::endl;
	this->fixed_value = copy.getRawBits() ;
}

Fixed::~Fixed()
{
	std::cout << "Fixed Deconstructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Fixed Assignation operator called" << std::endl;
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

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}

