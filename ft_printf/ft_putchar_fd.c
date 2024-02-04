/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:52:39 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/04 15:26:31 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

// Function to print a single character to a specified file descriptor
int ft_putchar_fd(char c, int fd)
{
	// Write the character to the specified file descriptor
	write(fd, &c, 1);

	// Check if the character is '%' and return 3, else return 1
	if (c == '%')
		return (3);
	else
		return (1);
}
