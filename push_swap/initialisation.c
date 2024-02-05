/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:45:42 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/05 22:54:45 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: index_max
** --------------------
** Finds and returns the index of the maximum element in the given integer
** array 'tab'.
**
** tab:  The integer array in which the maximum element is to be found.
** size: The number of elements in the array.
**
** Returns: The index of the maximum element in the array.
*/
int	index_max(int *tab, int size)
{
	// Variables to iterate through the array and track maximum values.
	int i = 0;
	int max = tab[0];
	int index = 0;

	// Iterate through the array to find the maximum element and its index.
	while (i < size)
	{
		if (tab[i] >= max)
		{
			max = tab[i];
			index = i;
		}
		i++;
	}

	// Return the index of the maximum element in the array.
	return (index);
}

/*
** Function: index_max
** --------------------
** Finds and returns the index of the maximum element in the given integer
** array 'tab'.
**
** tab:  The integer array in which the maximum element is to be found.
** size: The number of elements in the array.
**
** Returns: The index of the maximum element in the array.
*/
int	index_max(int *tab, int size)
{
	// Variables to iterate through the array and track maximum values.
	int i = 0;
	int max = tab[0];
	int index = 0;

	// Iterate through the array to find the maximum element and its index.
	while (i < size)
	{
		if (tab[i] >= max)
		{
			max = tab[i];
			index = i;
		}
		i++;
	}

	// Return the index of the maximum element in the array.
	return (index);
}

/*
** Function: index_min
** --------------------
** Finds and returns the index of the minimum element in the given integer
** array 'tab'.
**
** tab:  The integer array in which the minimum element is to be found.
** size: The number of elements in the array.
**
** Returns: The index of the minimum element in the array.
*/
int	index_min(int *tab, int size)
{
	// Variables to iterate through the array and track minimum values.
	int i = 0;
	int min = tab[0];
	int index = 0;

	// Iterate through the array to find the minimum element and its index.
	while (i < size)
	{
		if (tab[i] <= min)
		{
			min = tab[i];
			index = i;
		}
		i++;
	}

	// Return the index of the minimum element in the array.
	return (index);
}

/*
** Function: max
** --------------------
** Finds and returns the maximum element in the given integer array 'tab'.
**
** tab:  The integer array in which the maximum element is to be found.
** size: The number of elements in the array.
**
** Returns: The maximum element in the array.
*/
int max(int *tab, int size)
{
	// Variables to iterate through the array and track the maximum value.
	int i = 0;
	int max = tab[0];

	// Iterate through the array to find the maximum element.
	while (i < size)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}

	// Return the maximum element in the array.
	return max;
}

/*
** Function: ft_all_equal
** -----------------------
** Checks if all elements in the given integer array 'tab' are equal.
**
** tab:  The integer array to check for equality.
** size: The number of elements in the array.
**
** Returns: 0 if all elements are equal, 1 otherwise.
*/
int ft_all_equal(int *tab, int size)
{
	// Variable to iterate through the array.
	int i = 0;

	// Iterate through the array to check if all elements are equal.
	while (i < size - 1)
	{
		if (tab[i] == tab[i + 1])
			i++;
		else
			return 1; // Return 1 if not all elements are equal.
	}

	// Return 0 if all elements in the array are equal.
	return 0;
}

