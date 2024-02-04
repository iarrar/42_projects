/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:57:24 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/04 15:26:46 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

// Function to print a string followed by a newline to a specified file descriptor
void ft_putendl_fd(char *s, int fd)
{
	// Print the string to the specified file descriptor
	ft_putstr_fd(s, fd);

	// Print a newline character to the specified file descriptor
	ft_putchar_fd('\n', fd);
}