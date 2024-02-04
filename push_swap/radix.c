/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:20:46 by iarrar            #+#    #+#             */
/*   Updated: 2023/09/25 14:20:48 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_bits(int n)
{
	int	bits;

	bits = 0;
	while ((n >> bits) > 0)
		bits++;
	return (bits);
}

void	ft_dry_stack(t_data *stack_a, t_data *stack_b)
{
	while (stack_b->size >= 1)
		ft_push_pa(stack_a, stack_b);
}

void	ft_sort(t_data *s_a, t_data *s_b)
{
	if (ft_is_sorted(s_a->sort, s_a->size) == 0)
		return ;
	if (s_a->size == 2)
	{
		if (s_a->sort[1] > s_a->sort[0])
		{
			ft_swap(s_a);
			ft_printf("sa\n");
			return ;
		}
	}
	else if (s_a->size == 3)
		ft_sort_three(s_a, s_a->sort[0], s_a->sort[1], s_a->sort[2]);
	else if (s_a->size == 4)
		ft_sort_four(s_a, s_b);
	else if (s_a->size == 5)
		ft_sort_five(s_a, s_b);
	else
		ft_radix(s_a, s_b);
}

void	ft_radix(t_data *stack_a, t_data *stack_b)
{
	int	bit;
	int	i;

	i = stack_a->size - 1;
	bit = 0;
	while (bit < stack_a->bit_max)
	{
		while (i >= 0)
		{
			if (((stack_a->sort[stack_a->size - 1] >> bit) & 1) == 0)
				ft_push_pb(stack_a, stack_b);
			else
			{
				ft_rotate(stack_a);
				ft_printf("ra\n");
			}
			i--;
		}
		ft_dry_stack(stack_a, stack_b);
		i = stack_a->size - 1;
		bit++;
		if (ft_is_sorted(stack_a->sort, stack_a->size) == 0)
			return ;
	}
}
