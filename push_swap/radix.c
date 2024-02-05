/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:20:46 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/05 23:12:11 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: ft_count_bits
** ------------------------
** Counts the number of bits required to represent a given integer.
**
** n: The integer for which bits are to be counted.
**
** Returns: The number of bits required to represent the integer 'n'.
*/
int ft_count_bits(int n)
{
	int bits = 0;  // Variable to store the count of bits

	// Loop until all bits of 'n' are processed
	while ((n >> bits) > 0)
		bits++;  // Increment the count for each processed bit

	return bits;  // Return the total count of bits
}

/*
** Function: ft_dry_stack
** -----------------------
** Transfers all elements from stack B to stack A using push operations.
**
** stack_a: The destination stack.
** stack_b: The source stack.
*/
void ft_dry_stack(t_data *stack_a, t_data *stack_b)
{
	// Continue the loop until all elements from stack B are transferred to stack A
	while (stack_b->size >= 1)
		ft_push_pa(stack_a, stack_b);  // Push an element from stack B to stack A
}

/*
** Function: ft_sort
** -----------------
** Sorts the stack using different sorting algorithms based on the size.
**
** s_a: The main stack to be sorted.
** s_b: The auxiliary stack used in some sorting algorithms.
*/
void ft_sort(t_data *s_a, t_data *s_b)
{
	// Check if the main stack is already sorted
	if (ft_is_sorted(s_a->sort, s_a->size) == 0)
		return;

	// Choose sorting algorithm based on the size of the stack
	if (s_a->size == 2)
	{
		// If the stack has 2 elements, perform swap if needed
		if (s_a->sort[1] > s_a->sort[0])
		{
			ft_swap(s_a);
			ft_printf("sa\n");
			return;
		}
	}
	else if (s_a->size == 3)
	{
		// If the stack has 3 elements, use the three-element sorting algorithm
		ft_sort_three(s_a, s_a->sort[0], s_a->sort[1], s_a->sort[2]);
	}
	else if (s_a->size == 4)
	{
		// If the stack has 4 elements, use the four-element sorting algorithm
		ft_sort_four(s_a, s_b);
	}
	else if (s_a->size == 5)
	{
		// If the stack has 5 elements, use the five-element sorting algorithm
		ft_sort_five(s_a, s_b);
	}
	else
	{
		// For larger stacks, use the radix sort algorithm
		ft_radix(s_a, s_b);
	}
}

/*
** Function: ft_radix
** -------------------
** Sorts the stack using the radix sorting algorithm.
**
** stack_a: The main stack to be sorted.
** stack_b: An auxiliary stack used during sorting.
*/
void ft_radix(t_data *stack_a, t_data *stack_b)
{
	int bit;
	int i;

	// Initialize index and bit variables
	i = stack_a->size - 1;
	bit = 0;

	// Iterate through each bit of the numbers in the stack
	while (bit < stack_a->bit_max)
	{
		// Iterate through the elements in the main stack
		while (i >= 0)
		{
			// Push the element to stack_b if the current bit is 0, else rotate
			if (((stack_a->sort[stack_a->size - 1] >> bit) & 1) == 0)
				ft_push_pb(stack_a, stack_b);
			else
			{
				ft_rotate(stack_a);
				ft_printf("ra\n");
			}
			i--;
		}

		// Dry the stack_b into stack_a after processing each bit
		ft_dry_stack(stack_a, stack_b);

		// Reset index and move to the next bit
		i = stack_a->size - 1;
		bit++;

		// Check if the stack is sorted, if yes, return
		if (ft_is_sorted(stack_a->sort, stack_a->size) == 0)
			return;
	}
}




