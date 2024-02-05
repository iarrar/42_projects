/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:24:18 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/05 21:37:47 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: ft_ciao
** -----------------
** Frees memory allocated for the stacks and parameters in the push_swap program.
**
** stack_a: A pointer to the first stack (stack A).
** stack_b: A pointer to the second stack (stack B).
** param:   An array of strings containing program parameters.
*/
void	ft_ciao(t_data *stack_a, t_data *stack_b, char **param)
{
	// Free memory for the integer arrays in both stacks.
	if (stack_a->tab)
		free(stack_a->tab);
	if (stack_b->tab)
		free(stack_b->tab);

	// Free memory for the sorted arrays in both stacks.
	if (stack_a->sort)
		free(stack_a->sort);
	if (stack_b->sort)
		free(stack_b->sort);

	// Free memory for the stacks themselves.
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);

	// Free memory for the array of strings (parameters).
	if (param)
		ft_freetabtab(param);
}
