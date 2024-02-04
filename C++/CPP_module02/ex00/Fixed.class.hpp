/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:22:07 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/29 21:22:08 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H
#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed();
		Fixed& operator=(Fixed const & src);
		int	getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int value;
		static const int n;

};

#endif