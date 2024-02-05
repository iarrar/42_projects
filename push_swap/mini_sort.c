/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:22:24 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/05 23:07:23 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: ft_tdu
** ----------------
** Applies specific swap and reverse rotate operations to sort three
** elements on the top of stack A.
**
** stack_a: The stack to be manipulated.
**
** Note: This function is designed to achieve a specific ordering
** of the top three elements on the given stack using predefined
** swap (sa) and reverse rotate (rra) operations. It may output
** sorting operations using printf.
*/
void ft_tdu(t_data *stack_a)
{
	ft_swap(stack_a);         // Swap the top two elements
	ft_printf("sa\n");
	ft_reverse_rotate(stack_a);  // Reverse rotate the stack
	ft_printf("rra\n");
}

/*
** Function: ft_tud
** ----------------
** Applies a specific rotate operation to sort three elements on
** the top of stack A.
**
** stack_a: The stack to be manipulated.
**
** Note: This function is designed to achieve a specific ordering
** of the top three elements on the given stack using a predefined
** rotate (ra) operation. It may output sorting operations using
** printf.
*/
void ft_tud(t_data *stack_a)
{
	ft_rotate(stack_a);  // Rotate the stack
	ft_printf("ra\n");
}

/*
** Function: ft_dut
** ----------------
** Applies a specific swap operation to sort three elements on
** the top of stack A.
**
** stack_a: The stack to be manipulated.
**
** Note: This function is designed to achieve a specific ordering
** of the top three elements on the given stack using a predefined
** swap (sa) operation. It may output sorting operations using
** printf.
*/
void ft_dut(t_data *stack_a)
{
	ft_swap(stack_a);  // Swap the top two elements of the stack
	ft_printf("sa\n");
}

/*
** Function: ft_dtu
** ----------------
** Applies a specific reverse rotate operation to sort three elements on
** the top of stack A.
**
** stack_a: The stack to be manipulated.
**
** Note: This function is designed to achieve a specific ordering
** of the top three elements on the given stack using a predefined
** reverse rotate (rra) operation. It may output sorting operations
** using printf.
*/
void ft_dtu(t_data *stack_a)
{
	ft_reverse_rotate(stack_a);  // Reverse rotate the elements of the stack
	ft_printf("rra\n");
}

/*
** Function: ft_utd
** ----------------
** Applies a specific sequence of operations to sort three elements on
** the top of stack A.
**
** stack_a: The stack to be manipulated.
**
** Note: This function is designed to achieve a specific ordering
** of the top three elements on the given stack using a predefined
** sequence of swap (sa) and rotate (ra) operations. It may output
** sorting operations using printf.
*/
void ft_utd(t_data *stack_a)
{
	ft_swap(stack_a);  // Swap the top two elements of the stack
	ft_printf("sa\n");
	ft_rotate(stack_a);  // Rotate the elements of the stack
	ft_printf("ra\n");
}
