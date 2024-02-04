/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adresse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:15:09 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/04 15:23:54 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function to convert a pointer to a base and print the result
int ft_base_add(void *ptr, char *str)
{
	// Variable to hold the converted base string
	char *dest;

	// Loop counter and variables for result, modulo, and remaining value
	size_t i;
	size_t res;
	size_t mod;

	// Initialize loop counter and set res to the integer value of the pointer
	i = 0;
	res = (size_t)ptr;

	// Allocate memory for the destination string
	dest = ft_calloc(sizeof(char), (size_base(res, ft_strlen(str)) + 1));

	// Loop to convert the value to the specified base
	while (res >= (size_t)ft_strlen(str))
	{
		mod = res % (ft_strlen(str));
		dest[i] = str[mod];
		res = res / (ft_strlen(str));
		i++;
	}

	// Add the last character to the destination string
	dest[i] = str[res];
	res = i;

	// Print the converted value in reverse order
	while (i > 0)
	{
		ft_putchar_fd(dest[i], 1);
		i--;
	}

	// Print the first character of the destination string
	ft_putchar_fd(dest[0], 1);

	// Free the allocated memory for the destination string
	free(dest);

	// Return the length of the converted string
	return ((int)res + 1);
}

// Function to print the address of a pointer in hexadecimal format
int ft_adresse(void *ptr)
{
	// Variable to hold the return value
	int i;

	// Initialize the return value
	i = 0;

	// Check if the pointer is NULL
	if (!ptr)
	{
		// Print "(nil)" and return the length
		write(1, "(nil)", 5);
		return (5);
	}

	// Print "0x" prefix for hexadecimal addresses
	ft_putstr_fd("0x", 1);

	// Call the base conversion function for hexadecimal representation
	i = ft_base_add(ptr, "0123456789abcdef");

	// Return the total length of the printed address
	return (i + 2);
}
