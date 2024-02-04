/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:21:36 by iarrar            #+#    #+#             */
/*   Updated: 2023/09/28 10:21:38 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_data *s, int zero, int one, int two)
{
	if (s->sort[0] == zero && s->sort[1] == one && s->sort[2] == two)
		ft_tdu(s);
	else if (s->sort[0] == one && s->sort[1] == zero && s->sort[2] == two)
		ft_tud(s);
	else if (s->sort[0] == two && s->sort[1] == zero && s->sort[2] == one)
		ft_dut(s);
	else if (s->sort[0] == zero && s->sort[1] == two && s->sort[2] == one)
		ft_dtu(s);
	else if (s->sort[0] == one && s->sort[1] == two && s->sort[2] == zero)
		ft_utd(s);
}

void	ft_sort_five(t_data *s_a, t_data *s_b)
{
	while (s_a->size > 3)
	{
		while (s_a->sort[s_a->size - 1] != min(s_a->sort, s_a->size))
		{
			ft_rotate(s_a);
			ft_printf("ra\n");
		}
		ft_push_pb(s_a, s_b);
	}
	ft_sort_three(s_a, 2, 3, 4);
	if (s_b->sort[0] > s_b->sort[1])
	{
		ft_swap(s_b);
		ft_printf("sb\n");
	}
	while (s_b->size > 0)
		ft_push_pa(s_a, s_b);
}

void	ft_sort_four(t_data *s_a, t_data *s_b)
{
	while (s_a->size > 3)
	{
		while (s_a->sort[s_a->size - 1] != min(s_a->sort, s_a->size))
		{
			ft_rotate(s_a);
			ft_printf("ra\n");
		}
		ft_push_pb(s_a, s_b);
	}
	ft_sort_three(s_a, 1, 2, 3);
	if (s_b->sort[0] > s_b->sort[1])
	{
		ft_swap(s_b);
		ft_printf("sb\n");
	}
	while (s_b->size > 0)
		ft_push_pa(s_a, s_b);
}
