/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:15:46 by iarrar            #+#    #+#             */
/*   Updated: 2023/09/28 10:15:51 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*ft_init_stack(int size)
{
	t_data	*stack;

	stack = malloc(sizeof(t_data));
	stack->tab = malloc(sizeof(int) * size);
	stack->sort = malloc(sizeof(int) * size);
	stack->size = 0;
	stack->bit_max = 0;
	return (stack);
}

char	**ft_init_oneparam(char *str)
{
	char	**tab;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 7 && str[i] <= 13)
			str[i] = 32;
		i++;
	}
	tab = ft_split(str, ' ');
	return (tab);
}

void	ft_index_tab(t_data *stack)
{
	int	i;
	int	fill;
	int	index;

	fill = stack->size - 1;
	i = 0;
	stack->sort[index_min(stack->tab, stack->size)] = 0;
	while (i < stack->size - 1)
	{
		if (ft_all_equal(stack->tab, stack->size) == 0)
			break ;
		index = index_max(stack->tab, stack->size);
		stack->sort[index] = fill;
		stack->tab[index] = -2147483648;
		i++;
		fill--;
	}
}

t_data	*ft_init_params(char **str, int size)
{
	int		i;
	t_data	*data;

	i = 0;
	data = malloc(sizeof(t_data));
	data->tab = malloc(sizeof(int) * size);
	data->sort = malloc(sizeof(int) * size);
	data->size = size;
	while (size >= 1)
	{
		data->tab[size - 1] = ft_atoi(str[i]);
		size--;
		i++;
	}
	ft_index_tab(data);
	data->bit_max = ft_count_bits(max(data->sort, data->size));
	return (data);
}
