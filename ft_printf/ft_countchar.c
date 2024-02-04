/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:21:25 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/04 15:25:23 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

// Function to count occurrences of a character in a string
int ft_countchar(const char *str, char c)
{
	// Loop counter and variable to store the count
	int i;
	int s;

	// Initialize the count
	s = 0;
	i = 0;

	// Loop through the string and count occurrences of the specified character
	while (str[i])
	{
		if (str[i] == c)
			s++;
		i++;
	}

	// Return the count
	return (s);
}