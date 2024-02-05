/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:11:00 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/05 23:07:56 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: main
** --------------
** Entry point of the program.
**
** argc: Number of command-line arguments.
** argv: Array of command-line arguments.
**
** Note: This function initializes stacks, processes command-line
** arguments, checks input validity, performs sorting operations,
** and releases allocated memory before returning.
*/
int main(int argc, char **argv)
{
	t_data	*stack_a;  // Stack A for holding input elements
	t_data	*stack_b;  // Stack B for auxiliary purposes
	char	**param;    // Processed command-line arguments

	if (argc < 2)
		return (0);

	if (argc == 2)
	{
		if (argv[1][0] == 0)
			return (0);
		param = ft_init_oneparam(argv[1]);  // Initialize parameters from a single string
	}
	else
		param = ft_tabtabstrdup(&argv[1]);  // Duplicate command-line arguments

	if (ft_check_input(param) != 0)
	{
		ft_freetabtab(param);  // Free allocated memory for parameters in case of invalid input
		return (0);
	}

	stack_a = ft_init_params(param, ft_tabtabstrlen(param));  // Initialize stack A with input parameters
	stack_b = ft_init_stack(ft_tabtabstrlen(param));  // Initialize stack B for auxiliary purposes
	ft_sort(stack_a, stack_b);  // Perform sorting operations on stack A and B
	ft_ciao(stack_a, stack_b, param);  // Release allocated memory
	return (0);
}

