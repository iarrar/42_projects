/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:24:18 by iarrar            #+#    #+#             */
/*   Updated: 2023/09/25 14:24:21 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ciao(t_data *stack_a, t_data *stack_b, char **param)
{
	if (stack_a->tab)
		free(stack_a->tab);
	if (stack_b->tab)
		free(stack_b->tab);
	if (stack_a->sort)
		free(stack_a->sort);
	if (stack_b->sort)
		free(stack_b->sort);
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
	if (param)
		ft_freetabtab(param);
}
