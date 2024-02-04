/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:48:12 by iarrar            #+#    #+#             */
/*   Updated: 2023/09/25 12:48:14 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_pb(t_data *stack_a, t_data *stack_b)
{
	stack_b->size = stack_b->size + 1;
	stack_b->sort[stack_b->size - 1] = stack_a->sort[stack_a->size - 1];
	stack_a->size = stack_a->size - 1;
	ft_printf("pb\n");
}

void	ft_push_pa(t_data *stack_a, t_data *stack_b)
{
	stack_a->size = stack_a->size + 1;
	stack_a->sort[stack_a->size - 1] = stack_b->sort[stack_b->size - 1];
	stack_b->size = stack_b->size - 1;
	ft_printf("pa\n");
}

void	ft_rotate(t_data *stack)
{
	int	cup;
	int	i;

	i = stack->size - 1;
	cup = stack->sort[i];
	while (i > 0)
	{
		stack->sort[i] = stack->sort[i - 1];
		i--;
	}
	stack->sort[0] = cup;
}

void	ft_reverse_rotate(t_data *stack)
{
	int	cup;
	int	i;

	i = 0;
	cup = stack->sort[0];
	while (i < (stack->size - 1))
	{
		stack->sort[i] = stack->sort[i + 1];
		i++;
	}
	stack->sort[i] = cup;
}

void	ft_swap(t_data *stack)
{
	int	cup;

	if (stack->size <= 1)
		return ;
	else
	{
		cup = stack->sort[stack->size - 1];
		stack->sort[stack->size - 1] = stack->sort[stack->size - 2];
		stack->sort[stack->size - 2] = cup;
	}
}
