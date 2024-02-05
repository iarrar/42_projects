/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:48:12 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/05 23:00:11 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: ft_push_pb
** ---------------------
** Moves the top element from stack A to stack B.
**
** stack_a: The source stack from which the element is moved.
** stack_b: The destination stack to which the element is pushed.
**
** Note: This function assumes that both stacks have at least one element.
*/
void ft_push_pb(t_data *stack_a, t_data *stack_b)
{
	// Increase the size of stack B and copy the top element from stack A.
	stack_b->size = stack_b->size + 1;
	stack_b->sort[stack_b->size - 1] = stack_a->sort[stack_a->size - 1];

	// Decrease the size of stack A.
	stack_a->size = stack_a->size - 1;

	// Display the push operation.
	ft_printf("pb\n");
}

/*
** Function: ft_push_pa
** ---------------------
** Moves the top element from stack B to stack A.
**
** stack_a: The destination stack to which the element is moved.
** stack_b: The source stack from which the element is pushed.
**
** Note: This function assumes that both stacks have at least one element.
*/
void ft_push_pa(t_data *stack_a, t_data *stack_b)
{
	// Increase the size of stack A and copy the top element from stack B.
	stack_a->size = stack_a->size + 1;
	stack_a->sort[stack_a->size - 1] = stack_b->sort[stack_b->size - 1];

	// Decrease the size of stack B.
	stack_b->size = stack_b->size - 1;

	// Display the push operation.
	ft_printf("pa\n");
}

/*
** Function: ft_rotate
** --------------------
** Rotates the elements of the stack to the right.
** The top element becomes the last element after the rotation.
**
** stack: The stack whose elements are rotated.
**
** Note: This function assumes that the stack has at least one element.
*/
void ft_rotate(t_data *stack)
{
	// Store the top element of the stack.
	int cup = stack->sort[stack->size - 1];
	int i = stack->size - 1;

	// Shift each element to the right.
	while (i > 0)
	{
		stack->sort[i] = stack->sort[i - 1];
		i--;
	}

	// Place the stored top element at the bottom.
	stack->sort[0] = cup;
}

/*
** Function: ft_reverse_rotate
** ----------------------------
** Rotates the elements of the stack to the left.
** The last element becomes the top element after the rotation.
**
** stack: The stack whose elements are rotated.
**
** Note: This function assumes that the stack has at least one element.
*/
void ft_reverse_rotate(t_data *stack)
{
	// Store the last element of the stack.
	int cup = stack->sort[0];
	int i = 0;

	// Shift each element to the left.
	while (i < (stack->size - 1))
	{
		stack->sort[i] = stack->sort[i + 1];
		i++;
	}

	// Place the stored last element at the top.
	stack->sort[i] = cup;
}

/*
** Function: ft_swap
** -----------------
** Swaps the top two elements of the stack.
**
** stack: The stack whose top two elements are swapped.
**
** Note: This function assumes that the stack has at least two elements.
*/
void ft_swap(t_data *stack)
{
	// Check if the stack has at least two elements.
	if (stack->size <= 1)
		return; // No need to swap if there is only one or no elements.

	// Swap the top two elements of the stack.
	int cup = stack->sort[stack->size - 1];
	stack->sort[stack->size - 1] = stack->sort[stack->size - 2];
	stack->sort[stack->size - 2] = cup;
}
