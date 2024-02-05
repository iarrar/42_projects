/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:49:39 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/05 21:37:17 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: print_stacks
** -----------------------
** Prints the elements of two stacks (stack_a and stack_b) along with their
** corresponding sort indexes.
**
** stack_a: Pointer to the first stack.
** stack_b: Pointer to the second stack.
*/
void	print_stacks(t_data *stack_a, t_data *stack_b)
{
	int a;
	int b;

	a = stack_a->size - 1;
	b = stack_b->size - 1;

	// Print elements of stack_a along with their sort indexes.
	while (a >= 0)
	{
		ft_printf("sort[%d] = %d\n", a, stack_a->sort[a]);
		a--;
	}
	ft_printf("stack_a (size = %d)\n\n", stack_a->size);

	// Print elements of stack_b along with their sort indexes.
	while (b >= 0)
	{
		ft_printf("sort[%d] = %d\n", b, stack_b->sort[b]);
		b--;
	}
	ft_printf("stack_b (size = %d)\n\n", stack_b->size);
}

/*
** Function: ft_check_input
** -------------------------
** Checks the validity of the input arguments.
**
** tab: A null-terminated array of strings representing the input arguments.
**
** Returns:
**   - 0 if input is valid.
**   - 1 if there is an issue with the input.
*/
int	ft_check_input(char **tab)
{
	int	i;

	i = 0;

	// Iterate through the array of strings.
	while (tab[i])
	{
		// Check each string for format and content validity.
		if (ft_check_string(tab[i]) != 0 || ft_check_allnum(tab[i]) != 0)
			return (1);
		else
			i++;
	}

	// Check for duplicate values in the input.
	if (ft_check_double(tab) == 1)
		return (1);

	// Input is valid.
	return (0);
}

/*
** Function: ft_check_double
** --------------------------
** Checks for duplicate values in the array of strings.
**
** tab: A null-terminated array of strings representing input values.
**
** Returns:
**   - 0 if there are no duplicate values.
**   - 1 if there are duplicate values, and an error message is printed.
*/
int	ft_check_double(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 1;

	// Iterate through the array of strings.
	while (tab[i])
	{
		// Compare the current string with subsequent strings.
		while (tab[i + j])
		{
			// If duplicate values are found, print an error message and return 1.
			if (ft_strcmp(tab[i], tab[i + j]) == 0)
			{
				ft_printf("Error\n");
				return (1);
			}
			else
				j++;
		}

		// Reset the counter for the next iteration.
		j = 1;
		i++;
	}

	// No duplicate values found.
	return (0);
}

/*
** Function: ft_check_string
** -------------------------
** Checks if a given string is a valid representation of an integer.
**
** str: A string to be checked.
**
** Returns:
**   - 0 if the string is a valid integer representation.
**   - 1 if the string is not a valid integer representation, and an error
**        message is printed.
*/
int	ft_check_string(char *str)
{
	char	*checker;

	// Convert the string to an integer and then back to a string for validation.
	checker = ft_itoa(ft_atoi(str));

	// Compare the converted string with the original string.
	if (ft_strncmp(checker, str, (ft_strlen(str) - 1)) != 0)
	{
		// Print an error message and free allocated memory.
		ft_printf("Error\n");
		free(checker);
		return (1);
	}
	else
	{
		// Free allocated memory.
		free(checker);
		return (0);
	}
}

/*
** Function: ft_check_allnum
** -------------------------
** Checks if all characters in a given string are numeric digits.
**
** str: A string to be checked.
**
** Returns:
**   - 0 if all characters are numeric digits.
**   - 1 if any non-numeric character is found, and an error message is printed.
*/
int	ft_check_allnum(char *str)
{
	int	i;

	i = 0;

	// If the string starts with '+' or '-', move to the next character.
	if (str[i] == '+' || str[i] == '-')
		i++;

	// Iterate through the string and check if each character is a digit.
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			// Print an error message if a non-numeric character is found.
			ft_printf("Error\n");
			return (1);
		}
		else
			i++;
	}

	// Return 0 if all characters are numeric digits.
	return (0);
}


