/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:13:49 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/04 15:25:40 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

// Main printf function that handles format specifiers
int ft_printf(const char *str, ...)
{
	// Variable argument list and loop counters
	va_list args;
	int i;
	int res;

	// Initialize variables
	res = 0;
	i = 0;

	// Start variable argument processing
	va_start(args, str);

	// Loop through the format string
	while (str[i])
	{
		// Check for format specifier '%'
		if (str[i] == '%')
		{
			// Move to the next character after '%'
			i++;

			// Add the length of the processed format specifier to the result
			res = res + ft_which_sign(&args, str[i]);

			// Move to the next character after the format specifier
			i++;
		}
		else
		{
			// Print non-format specifier character
			ft_putchar_fd(str[i], 1);

			// Move to the next character
			i++;
		}
	}

	// End variable argument processing
	va_end(args);

	// Return the total length of the printed string
	return (ft_strlen(str) + res - (2 * ft_countchar(str, '%')));
}