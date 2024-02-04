/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:54:13 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/04 15:27:55 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

// Function to print a string to a specified file descriptor
int ft_putstr_fd(char *s, int fd)
{
	// Loop counter
	int i;

	// Initialize loop counter
	i = 0;

	// Check if the string is NULL
	if (!s)
	{
		// Print "(null)" and return the length
		write(1, "(null)", 6);
		return (6);
	}

	// Loop through the string and print each character to the specified file descriptor
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}

	// Return the length of the printed string
	return (ft_strlen(s));
}