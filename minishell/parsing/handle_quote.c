/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:46:29 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/05 23:47:33 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Remove quotes from the given string 'cmd'.
// Parameters:
//   - cmd: The input string enclosed in quotes.
// Returns:
//   - A new string without the quotes.
char *del_quote(char *cmd)
{
    char *str;
    int i;

    i = 1;
    // Allocate memory for the new string without quotes.
    str = malloc(sizeof(char) * (ft_strlen(cmd) - 1));

    while (cmd[i + 1] != '\0')
    {
        // Copy characters without the quotes into the new string.
        str[i - 1] = cmd[i];
        i++;
    }

    // Null-terminate the new string.
    str[i - 1] = '\0';
    return (str);
}

// Check if the given string 'cmd' starts with a quote (' or ").
// If yes, remove the quotes and return a new string without them.
// If no quotes are present, return the original string.
// Parameters:
//   - cmd: The input string to check for quotes.
// Returns:
//   - A new string without quotes if present; otherwise, the original string.
char *check_quote(char *cmd)
{
    int i;
    char *str;

    i = 0;
    // Check if the first character is a quote.
    if (cmd[i] == '\'' || cmd[i] == '\"')
    {
        // If yes, remove the quotes using the del_quote function.
        str = del_quote(cmd);
        return (str);
    }
    // If no quotes are present, return the original string.
    return (cmd);
}

// Apply the check_quote function to each element of the array 'cmds'.
// Parameters:
//   - cmds: The array of strings to handle quotes.
// Returns:
//   - The modified array with quotes removed.
char **handle_quote(char **cmds)
{
    int i;

    i = 0;
    // Iterate through each element of the array.
    while (cmds[i] != NULL)
    {
        // Apply the check_quote function to remove quotes.
        cmds[i] = check_quote(cmds[i]);
        i++;
    }
    // Return the modified array.
    return (cmds);
}



