/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:01:03 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/04 15:24:54 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

// Function to allocate memory and zero it out
void *ft_calloc(size_t nmemb, size_t size)
{
	// Variable to hold the destination memory address
	void *dest;

	// Check for zero size or zero number of members
	if (nmemb == 0 || size == 0)
		return (malloc(0));

	// Check for potential overflow in the multiplication
	if (nmemb * size / size != nmemb)
		return (NULL);

	// Allocate memory for the destination with the specified size
	dest = malloc(nmemb * size);

	// Check if memory allocation was successful
	if (!dest)
		return (NULL);

	// Zero out the allocated memory block
	ft_bzero(dest, (nmemb * size));

	// Return the pointer to the allocated and zeroed memory
	return (dest);
}
