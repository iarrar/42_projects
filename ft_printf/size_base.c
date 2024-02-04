/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:22:59 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/04 15:28:35 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

// Function to calculate the number of digits required to represent an integer in a given base
int size_base(int n, int base)
{
	// Variables for loop counter, divisor, and original value of n
	int i;
	int div;

	// Initialize loop counter and set div to the value of n
	i = 0;
	div = n;

	// Check if n is the minimum possible integer value
	if (n == -2147483648)
		return (11);

	// If n is negative, set div to its absolute value and increment the loop counter
	if (n < 0)
	{
		div = -n;
		i++;
	}

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

