/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:39:53 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/04 15:24:29 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function to zero out a block of memory
void ft_bzero(void *s, size_t n)
{
	// Loop counter and pointer to unsigned char
	size_t i;
	unsigned char *s1;

	// Cast the input pointer to unsigned char
	s1 = (unsigned char *)s;

	// Loop through the memory block and set each byte to zero
	i = 0;
	while (i < n)
	{
		s1[i] = '\0';
		i++;
	}
}
