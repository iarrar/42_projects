/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:07:35 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/04 15:28:06 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function to calculate the length of a string
int ft_strlen(const char *str)
{
	// Loop counter
	int i;

	// Initialize loop counter
	i = 0;

	// Loop through the string and count the characters
	while (str[i])
		i++;

	// Return the length of the string
	return (i);
}