/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:32:17 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/05 23:32:33 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Check the position of the first '=' character in the given command string
// Returns the index of the first '=' character, or -1 if not found
int check_place_space(char *cmd)
{
    int i;

    // Initialize the index variable
    i = 0;

    // Traverse the command string
    while (cmd[i])
    {
        // Check if the current character is '='
        if (cmd[i] == '=')
            return (i); // Return the index of '=' if found

        // Move to the next character
        i++;
    }

    // If '=' is not found, return -1
    return (-1);
}

// Check if a command with the specified prefix (first 'n' characters) exists in the environment
// Returns the index of the command in the environment array if found, or -1 if not found
int check_exist(char *cmd, t_env *env, int n)
{
    int i;

    // Initialize the index variable
    i = 0;

    // Traverse the environment array
    while (env->env_cpy[i] != NULL)
    {
        // Compare the prefix of the current environment variable with the specified command
        if (ft_strncmp(cmd, env->env_cpy[i], n) == 0)
            return (i); // Return the index if a match is found

        // Move to the next environment variable
        i++;
    }

    // If no match is found, return -1
    return (-1);
}

// Calculate the number of strings in a two-dimensional array of strings (tabtab)
// Returns the count of strings in the array
int tabtab_strlen(char **tab)
{
    int i;

    // Initialize the index variable
    i = 0;

    // Check if the array is NULL
    if (!tab)
        return (0);

    // Traverse the array to count the number of strings
    while (tab[i])
        i++;

    // Return the count of strings in the array
    return (i);
}

// Concatenate a command string and an environment tabtab (two-dimensional array of strings)
// Returns a new tabtab with the concatenated strings
char **tabtab_strjoin(char *cmd, char **env)
{
    int len;
    char **dest;
    int i;

    // Initialize the index variable
    i = 0;

    // Calculate the number of strings in the existing environment array
    len = tabtab_strlen(env);

    // Allocate memory for the new tabtab, considering the existing environment and the command
    dest = malloc(sizeof(char *) * (len + 2));

    // Copy the existing environment strings to the new tabtab
    while (env[i])
    {
        dest[i] = ft_strdup(env[i]);
        i++;
    }

    // Copy the command string to the new tabtab
    dest[i] = ft_strdup(cmd);

    // Set the last element of the new tabtab to NULL
    dest[i + 1] = NULL;

    // Return the new tabtab with concatenated strings
    return (dest);
}

// Implementation of the export built-in command
// Handles exporting environment variables or displays the entire environment
// Updates the environment copy in the t_env structure
// Returns 1 upon successful execution
int m_export(char **cmds, t_env *env)
{
    int j;

    // Initialize the index variable
    j = 1;

    // Check if the export command is without arguments; if true, display the entire environment
    if (!cmds[1])
        m_env(env->env_cpy);
    else
    {
        // Loop through the export command arguments
        while (cmds[j])
        {
            // Check if the argument contains '=' and is not starting with '='
            if (ft_strchr(cmds[j], '=') != 0 && cmds[j][0] != '=')
            {
                // Check if the environment variable already exists
                int index = check_exist(cmds[j], env, check_place_space(cmds[j]));
                if (index >= 0)
                {
                    // Update the existing environment variable
                    env->env_cpy[index] = ft_strdup(cmds[j]);
                }
                else
                {
                    // Add the new environment variable to the environment copy
                    env->env_cpy = tabtab_strjoin(cmds[j], env->env_cpy);
                }
            }
            j++;
        }
    }

    // Return 1 upon successful execution
    return (1);
}



