/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:22:37 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/05 23:26:13 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Custom implementation of "env" command
int m_env(char **envp)
{
    int i = 0;

    // Iterate over each environment variable
    while (envp[i] != NULL)
    {
        // Print the current environment variable
        printf("%s\n", envp[i]);

        // Move to the next environment variable
        i++;
    }

    // Return 1 to indicate the success of the "env" command
    return (1);
}
