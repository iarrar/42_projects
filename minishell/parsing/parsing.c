/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:49:31 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/05 23:47:59 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Parse the command string and handle environment variable expansion and quotes.
// Parameters:
//   - cmd: The command string to parse.
//   - env: The array of environment variables.
//   - err: The error flag.
// Returns:
//   - The parsed and modified array of strings.
char **parsing(char *cmd, char **env, int err)
{
    char **cmds;

    // Split the command string into an array of strings using spaces as delimiters.
    cmds = split(cmd, ' ', 0, 0);
    // Apply ft_parkour to handle environment variable expansion and other modifications.
    cmds = ft_parkour(cmds, env, err);
    // Apply handle_quote to handle quotes in each element of the array.
    cmds = handle_quote(cmds);
    // Return the parsed and modified array of strings.
    return (cmds);
}

