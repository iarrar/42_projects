/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:28:11 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/06 00:00:20 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_isspace(char c)
{
    if ((c >= 9 && c <= 13) || c == 32)
        return 1;  // Character is a whitespace character.
    else
        return 0;  // Character is not a whitespace character.
}

