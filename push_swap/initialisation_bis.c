/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:15:46 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/05 21:41:28 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: ft_init_stack
** -----------------------
** Initializes and allocates memory for a stack in the push_swap program.
**
** size: Size of the stack to be initialized.
**
** Returns: A pointer to the initialized stack (t_data structure).
*/
t_data	*ft_init_stack(int size)
{
	// Allocate memory for the t_data structure representing the stack.
	t_data	*stack = malloc(sizeof(t_data));

	// Allocate memory for the integer array representing the stack.
	stack->tab = malloc(sizeof(int) * size);

	// Allocate memory for the sorted array used for optimization.
	stack->sort = malloc(sizeof(int) * size);

	// Initialize the size of the stack to zero.
	stack->size = 0;

	// Initialize the bit_max to zero.
	stack->bit_max = 0;

	// Return a pointer to the initialized stack.
	return (stack);
}

/*
** Function: ft_init_oneparam
** ---------------------------
** Initializes a string parameter by splitting it into an array of strings
** using space as a delimiter.
**
** str: The input string parameter to be processed.
**
** Returns: A dynamically allocated array of strings (char**) resulting from
** splitting the input string.
*/
char	**ft_init_oneparam(char *str)
{
	// Iterate through the characters of the input string.
	int	i = 0;
	while (str[i])
	{
		// Replace characters with ASCII values between 7 and 13 (inclusive)
		// with space character (ASCII 32).
		if (str[i] >= 7 && str[i] <= 13)
			str[i] = 32;
		i++;
	}

	// Split the modified string into an array of strings using space as a delimiter.
	char	**tab = ft_split(str, ' ');

	// Return the dynamically allocated array of strings.
	return (tab);
}

/*
** Function: ft_index_tab
** -----------------------
** Assigns indices to elements in the 'sort' array of a stack based on the
** descending order of elements in the 'tab' array. The 'tab' array is updated
** to mark processed elements as -2147483648 to avoid reusing them.
**
** stack: The stack data structure containing 'tab' and 'sort' arrays.
*/
void	ft_index_tab(t_data *stack)
{
	// Variables to track the iteration, fill value, and index.
	int i = 0;
	int fill = stack->size - 1;
	int index;

	// Mark the minimum element in the 'tab' array with index 0.
	stack->sort[index_min(stack->tab, stack->size)] = 0;

	// Iterate through the 'tab' array to assign indices based on descending order.
	while (i < stack->size - 1)
	{
		// If not all elements are equal, exit the loop.
		if (ft_all_equal(stack->tab, stack->size) == 0)
			break;

		// Find the index of the maximum element in the 'tab' array.
		index = index_max(stack->tab, stack->size);

		// Assign the fill value to the corresponding index in the 'sort' array.
		stack->sort[index] = fill;

		// Mark the processed element in the 'tab' array to avoid reusing it.
		stack->tab[index] = -2147483648;

		// Increment the iteration and decrement the fill value.
		i++;
		fill--;
	}
}

/*
** Function: ft_init_params
** -------------------------
** Initializes a 't_data' structure with parameters obtained from the input
** string array. It creates and fills the 'tab' and 'sort' arrays, calculates
** the 'bit_max' value, and sets the 'size' attribute.
**
** str:  The input string array containing integer representations.
** size: The number of elements in the input array.
**
** Returns: A pointer to the newly initialized 't_data' structure.
*/
t_data	*ft_init_params(char **str, int size)
{
	// Variables to iterate through the input and initialize 't_data'.
	int i = 0;
	t_data *data;

	// Allocate memory for 't_data' structure and its arrays.
	data = malloc(sizeof(t_data));
	data->tab = malloc(sizeof(int) * size);
	data->sort = malloc(sizeof(int) * size);
	data->size = size;

	// Fill the 'tab' array with integers converted from the input string array.
	while (size >= 1)
	{
		data->tab[size - 1] = ft_atoi(str[i]);
		size--;
		i++;
	}

	// Initialize the 'sort' array based on descending order of 'tab'.
	ft_index_tab(data);

	// Calculate the 'bit_max' value based on the maximum element in 'sort'.
	data->bit_max = ft_count_bits(max(data->sort, data->size));

	// Return a pointer to the initialized 't_data' structure.
	return (data);
}



