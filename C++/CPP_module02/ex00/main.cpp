/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:51:33 by home              #+#    #+#             */
/*   Updated: 2024/01/22 16:40:48 by home             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Fixed.class.hpp"

int main( void ) 
{
  Fixed a;
  Fixed b( a );
  Fixed c;
	c = b;
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
return 0; 
}