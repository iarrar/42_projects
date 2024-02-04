/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_uns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:24:33 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/04 15:27:42 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

// Function to print an unsigned integer in a given base to a specified file descriptor
int ft_putnbru_base(unsigned int n, int fd, char *base)
{
	// Variables to store a character, the length of the base, the index, and the original value of n
	char c;
	unsigned int i;
	unsigned int s;

	// Store the original value of n and the length of the base
	s = n;
	i = (unsigned int)ft_strlen(base);

	// If n is greater than the length of the base - 1, get the last character, call the function recursively, and print the character
	if (n > i - 1)
	{
		c = base[(n % i)];
		n /= i;
		ft_putnbru_base(n, fd, base);
		write(fd, &c, 1);
	}
	else
	{
		// If n is within the range of the base, print the character
		c = base[n];
		write(fd, &c, 1);
	}

	// Return the number of digits in the printed unsigned integer in the specified base
	return (size_unsigned(s, ft_strlen(base)));
}