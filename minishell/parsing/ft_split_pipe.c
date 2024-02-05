/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:21:40 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/05 23:42:43 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Split the command array into subarrays based on the pipe '|' delimiter.
// Parameters:
//   - cmd: The command array to be split.
// Returns:
//   - An array of subarrays, each containing a portion of the original command.
char **ft_split_pipe(char **cmd)
{
    int start = 0;  // Start index for the current subarray.
    int end = 0;    // End index for the current subarray.
    int size = 0;   // Size of the original command array.
    char **dest;    // Destination array to store subarrays.

    // Calculate the size of the original command array.
    while (cmd[size])
        size++;

    // Initialize end to start, and iterate until the end of the command or a pipe is found.
    while (cmd[end] && ft_strcmp(cmd[end], "|") != 0)
        end++;

    // If no pipe is found, return the original command array.
    if (end == size)
        return (cmd);
    else
    {
        // Allocate memory for the destination array of subarrays.
        dest = (char **)ft_calloc((end + 1), sizeof(char *));

        // Copy elements from the original command array to the destination array.
        while (start < end)
        {
            dest[start] = ft_strdup(cmd[start]);
            start++;
        }

        // Set the last element of the destination array to NULL to indicate the end.
        dest[start] = NULL;
    }

    // Return the array of subarrays.
    return (dest);
}

// Duplicate a table of strings (array of strings).
// Parameters:
//   - tab: The table of strings to be duplicated.
// Returns:
//   - A new table of strings, which is a duplicate of the input table.
char **tabtab_strdup(char **tab)
{
    int i;           // Loop variable.
    char **dest;     // Destination array to store duplicated strings.

    // Count the number of strings in the input table.
    i = 0;
    while (tab[i])
        i++;

    // Allocate memory for the destination array of strings.
    dest = (char **)ft_calloc((i + 1), sizeof(char *));

    // Copy strings from the input table to the destination array.
    i = 0;
    while (tab[i])
    {
        dest[i] = ft_strdup(tab[i]);
        i++;
    }

    // Set the last element of the destination array to NULL to indicate the end.
    dest[i] = NULL;

    // Return the array of duplicated strings.
    return (dest);
}

// Count the number of pipelines in an array of strings.
// Parameters:
//   - cmd: The array of strings representing a command line.
// Returns:
//   - The number of pipelines in the command line.
int ft_count_pipe(char **cmd)
{
    int i;      // Loop variable.
    int count;  // Counter for the number of pipelines.

    i = 0;
    count = 0;

    // Iterate through the array of strings.
    while (cmd[i])
    {
        // Check if the current string is a pipeline symbol ("|").
        if (ft_strcmp(cmd[i], "|") == 0)
            count++;

        // Move to the next string.
        i++;
    }

    // Add 1 to the count to include the last command after the last pipeline.
    return (count + 1);
}

// Create an array of t_command structures from an array of strings representing a command line.
// Parameters:
//   - cmd: The array of strings representing the command line.
//   - env: The array of strings representing the environment variables.
// Returns:
//   - An array of t_command structures.
t_command *ft_create_nodes(char **cmd, char **env)
{
    int         n;    // Number of pipelines.
    t_command   *node; // Array of t_command structures.
    int         i;    // Loop variable.
    int         j;    // Index for the t_command array.

    i = 0;
    j = 1;

    // Count the number of pipelines in the command line.
    n = ft_count_pipe(cmd);

    // Allocate memory for the array of t_command structures.
    node = (t_command *)ft_calloc(n + 2, sizeof(t_command));

    // Initialize the first t_command structure with the entire command line.
    node[0].cmd = ft_split_pipe(cmd);
    node[0].env.env_cpy = envp_cpy(env);

    // Iterate through the array of strings.
    while (cmd[i])
    {
        // Check if the current string is a pipeline symbol ("|").
        if (ft_strcmp(cmd[i], "|") == 0 && j < n)
        {
            // Initialize the next t_command structure with the remaining command line.
            node[j].cmd = ft_split_pipe(&cmd[i + 1]);
            node[j].env.env_cpy = envp_cpy(env);
            j++;
        }

        // Move to the next string.
        i++;
    }

    // Set the last t_command structure's cmd field to NULL to indicate the end.
    node[j].cmd = NULL;

    return (node);
}

