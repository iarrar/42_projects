/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:14:43 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/04 15:27:01 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
// Function to print an integer to a specified file descriptor
int ft_putnbr_fd(int n, int fd)
{
	// Variables to store a character and the original value of n
	char c;
	int s;

	// Store the original value of n
	s = n;

	// Check if n is the minimum possible integer value
	if (n == -2147483648)
		// Print the specific string for the minimum integer value and return the length
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		// If n is negative, print '-' and call the function recursively for the positive value
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		// If n has more than one digit, get the last digit, call the function recursively, and print the digit
		c = (n % 10) + '0';
		n /= 10;
		ft_putnbr_fd(n, fd);
		write(fd, &c, 1);
	}
	else
	{
		// If n is a single digit, print it
		c = n + '0';
		write(fd, &c, 1);
	}

	// Return the length of the printed integer
	return (size_base(s, 10));
}
