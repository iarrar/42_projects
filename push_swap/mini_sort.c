/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:22:24 by iarrar            #+#    #+#             */
/*   Updated: 2023/09/26 20:22:27 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tdu(t_data *stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
	ft_reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	ft_tud(t_data *stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	ft_dut(t_data *stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
}

void	ft_dtu(t_data *stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	ft_utd(t_data *stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
	ft_rotate(stack_a);
	ft_printf("ra\n");
}
