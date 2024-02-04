/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:14:43 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/04 15:27:20 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

// Function to calculate the number of digits required to represent an unsigned integer in a given base
int size_unsigned(unsigned int n, unsigned int base)
{
	// Variables for loop counter and the result of division
	int i;
	unsigned int div;

	// Initialize loop counter and set div to the value of n
	i = 0;
	div = n;

	// If n is smaller than the base, return 1
	if (div < base)
		return (i + 1);

	// Loop to calculate the number of digits required
	while (div >= base)
	{
		div = div / base;
		i++;
	}

	// Return the total number of digits
	return (i + 1);
}

// Function to print an unsigned integer to a specified file descriptor
int ft_putnbru_fd(unsigned int n, int fd)
{
	// Variables to store a character and the original value of n
	char c;
	unsigned int s;

	// Store the original value of n
	s = n;

	// If n has more than one digit, get the last digit, call the function recursively, and print the digit
	if (n > 9)
	{
		c = (n % 10) + '0';
		n /= 10;
		ft_putnbru_fd(n, fd);
		write(fd, &c, 1);
	}
	else
	{
		// If n is a single digit, print it
		c = n + '0';
		write(fd, &c, 1);
	}

	// Return the number of digits in the printed unsigned integer
	return (size_unsigned(s, 10));
}
