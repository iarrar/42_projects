/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:11:57 by bgonon            #+#    #+#             */
/*   Updated: 2024/02/05 23:25:44 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Custom implementation of "echo -n" command
int m_echo_n(char **cmd)
{
    int i = 2;

    // Print each argument after "echo -n"
    while (cmd[i])
    {
        // Print the current argument
        printf("%s", cmd[i]);

        // If there is a next argument, print a space
        if (cmd[i + 1] != NULL)
            printf(" ");

        // Move to the next argument
        i++;
    }

    // Return 1 to indicate the success of the "echo -n" command
    return (1);
}
