/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:23:29 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/05 21:37:13 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: ft_is_sorted
** -----------------------
** Checks if an integer array is sorted in ascending order.
**
** tab:   Pointer to the integer array.
** size:  Number of elements in the array.
**
** returns: 0 if the array is sorted, 1 if not.
*/
int	ft_is_sorted(int *tab, int size)
{
    int i;

    i = 0;
    while (i < size - 1)
    {
        // Compare each element with the next one.
        if (tab[i] > tab[i + 1])
            i++;
        else
            return (1);  // If the array is not sorted, return 1.
    }

    return (0);  // If the array is sorted, return 0.
}

