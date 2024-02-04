/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:49:39 by iarrar            #+#    #+#             */
/*   Updated: 2023/09/25 12:49:41 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_data *stack_a, t_data *stack_b)
{
	int	a;
	int	b;

	a = stack_a->size - 1;
	b = stack_b->size - 1;
	while (a >= 0)
	{
		ft_printf("sort[%d] = %d\n", a, stack_a->sort[a]);
		a--;
	}
	ft_printf("stack_a (size = %d)\n\n", stack_a->size);
	while (b >= 0)
	{
		ft_printf("sort[%d] = %d\n", b, stack_b->sort[b]);
		b--;
	}
	ft_printf("stack_b (size = %d)\n\n", stack_b->size);
}

int	ft_check_input(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_check_string(tab[i]) != 0 || ft_check_allnum(tab[i]) != 0)
			return (1);
		else
			i++;
	}
	if (ft_check_double(tab) == 1)
		return (1);
	return (0);
}

int	ft_check_double(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (tab[i])
	{
		while (tab[i + j])
		{
			if (ft_strcmp(tab[i], tab[i + j]) == 0)
			{
				ft_printf("Error\n");
				return (1);
			}
			else
				j++;
		}
		j = 1;
		i++;
	}
	return (0);
}

int	ft_check_string(char *str)
{
	char	*checker;

	checker = ft_itoa(ft_atoi(str));
	if (ft_strncmp(checker, str, (ft_strlen(str) - 1)) != 0)
	{
		ft_printf("Error\n");
		free(checker);
		return (1);
	}
	else
	{
		free(checker);
		return (0);
	}
}

int	ft_check_allnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			ft_printf("Error\n");
			return (1);
		}
		else
			i++;
	}
	return (0);
}
