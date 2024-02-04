/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:45:42 by iarrar            #+#    #+#             */
/*   Updated: 2023/09/25 12:45:45 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_max(int *tab, int size)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	max = tab[0];
	index = 0;
	while (i < size)
	{
		if (tab[i] >= max)
		{
			max = tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	index_min(int *tab, int size)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = tab[0];
	index = 0;
	while (i < size)
	{
		if (tab[i] <= min)
		{
			min = tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	max(int *tab, int size)
{
	int	i;
	int	max;

	i = 0;
	max = tab[0];
	while (i < size)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int	ft_all_equal(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] == tab[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

int	min(int *tab, int size)
{
	int	i;
	int	min;

	i = 0;
	min = tab[0];
	while (i < size)
	{
		if (tab[i] <= min)
			min = tab[i];
		i++;
	}
	return (min);
}
