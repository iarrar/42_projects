/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:11:00 by iarrar            #+#    #+#             */
/*   Updated: 2023/09/25 11:11:03 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*stack_a;
	t_data	*stack_b;
	char	**param;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (argv[1][0] == 0)
			return (0);
		param = ft_init_oneparam(argv[1]);
	}
	else
		param = ft_tabtabstrdup(&argv[1]);
	if (ft_check_input(param) != 0)
	{
		ft_freetabtab(param);
		return (0);
	}
	stack_a = ft_init_params(param, ft_tabtabstrlen(param));
	stack_b = ft_init_stack(ft_tabtabstrlen(param));
	ft_sort(stack_a, stack_b);
	ft_ciao(stack_a, stack_b, param);
	return (0);
}
