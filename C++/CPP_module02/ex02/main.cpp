/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:51:33 by home              #+#    #+#             */
/*   Updated: 2024/01/29 22:52:27 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

int main( void ) 
{ 
	Fixed a;
	Fixed const b ( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << " b = " << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}