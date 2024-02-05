/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:21:36 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/05 23:05:10 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: ft_sort_three
** -----------------------
** Sorts the top three elements of the stack in ascending order using
** specific swap and rotate operations based on their initial positions.
**
** s:    The stack to be sorted.
** zero: The value of the element that should be at index 0 after sorting.
** one:  The value of the element that should be at index 1 after sorting.
** two:  The value of the element that should be at index 2 after sorting.
*/
void ft_sort_three(t_data *s, int zero, int one, int two)
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

/*
** Function: ft_sort_five
** -----------------------
** Sorts the top five elements of stack A using additional stack B.
** Utilizes predefined swap, push, and rotate operations to achieve
** a sorted order on stack A. Assumes stack A has at least five elements.
**
** s_a: The main stack to be sorted.
** s_b: An auxiliary stack used during the sorting process.
*/
void ft_sort_five(t_data *s_a, t_data *s_b)
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

/*
** Function: ft_sort_four
** -----------------------
** Sorts the top four elements of stack A using additional stack B.
** Utilizes predefined swap, push, and rotate operations to achieve
** a sorted order on stack A. Assumes stack A has at least four elements.
**
** s_a: The main stack to be sorted.
** s_b: An auxiliary stack used during the sorting process.
*/
void ft_sort_four(t_data *s_a, t_data *s_b)
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

