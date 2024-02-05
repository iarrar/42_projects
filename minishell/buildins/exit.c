/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:00:05 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/05 23:26:48 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Custom implementation of "exit" command
int m_exit(char **cmds, char **envp)
{
    // Silence unused parameter warnings
    (void)cmds;
    (void)envp;

    // Free memory allocated for command line arguments and environment variables
    ft_freetabs(cmds);
    ft_freetabs(envp);

    // Clear the history of the readline library
    rl_clear_history();

    // Terminate the program with exit code 0
    exit(0);

    // Return 1 to indicate the success of the "exit" command (although it will not be reached)
    return (1);
}

