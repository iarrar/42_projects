/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:07:42 by orauline          #+#    #+#             */
/*   Updated: 2024/02/05 23:35:17 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Remove an environment variable identified by key from env->env_cpy
// Parameters:
//   - key: the key of the environment variable to be removed
//   - env: a struct containing the environment variables
static void remove_env_var(char *key, t_env *env)
{
    // Declare a variable for iteration
    int i;

    // Initialize the iteration variable to -1
    i = -1;

    // Iterate through the env_cpy array to find the environment variable with the specified key
    while (env->env_cpy[++i])
    {
        // Check if the current environment variable matches the specified key
        if (ft_strcmp(key, env->env_cpy[i]) == 0)
        {
            // Free the memory occupied by the environment variable
            free(env->env_cpy[i]);

            // Shift the subsequent environment variables to fill the gap left by the removed one
            while (env->env_cpy[i + 1])
            {
                env->env_cpy[i] = env->env_cpy[i + 1];
                i++;
            }

            // Set the last element to NULL, indicating the end of the array
            env->env_cpy[i] = NULL;

            // Exit the function after removing the environment variable
            return;
        }
    }
}

// Print an error message indicating that the "unset" command has been called with not enough arguments
// and return an exit status of 1.
// This function is used to handle the case where the "unset" command is called with insufficient arguments.
// It prints an error message to the standard output and returns 1 to indicate an error exit status.
// Return:
//   - 1: Error exit status
static int err_not_enough_args(void)
{
    // Print an error message to the standard output
    printf("unset: not enough arguments\n");

    // Return an exit status of 1 to indicate an error
    return (1);
}

// Print an error message indicating that the "unset" command has been called with an invalid parameter name
// and return an exit status of 1.
// This function is used to handle the case where the "unset" command is called with an invalid parameter name.
// It prints an error message to the standard output, including the specific invalid parameter name,
// and returns 1 to indicate an error exit status.
// Parameters:
//   - cmds: The invalid parameter name provided to the "unset" command
// Return:
//   - 1: Error exit status
static int err_invalid_params(char *cmds)
{
    // Print an error message to the standard output, indicating the invalid parameter name
    printf("unset: %s: invalid parameter name\n", cmds);

    // Return an exit status of 1 to indicate an error
    return (1);
}

// Unset the specified environment variables.
// This function handles the "unset" command, which is used to unset (remove) specified environment variables.
// If no arguments are provided, it prints an error message indicating that not enough arguments were provided.
// If arguments are provided, it iterates through each argument, checks for validity, and removes the corresponding environment variable.
// Parameters:
//   - cmds: An array of strings representing the arguments provided to the "unset" command.
//   - env: A structure containing environment-related data, including the array of environment variables.
// Return:
//   - 1: Success exit status
int m_unset(char **cmds, t_env *env)
{
    int j;
    int i;

    // If no arguments are provided, print an error message and return an exit status of 1.
    if (!cmds[1])
        return err_not_enough_args();

    // Iterate through each argument provided to the "unset" command.
    j = 1;
    while (cmds[j])
    {
        // Check if the argument is a valid parameter name (does not start with a digit).
        if (check_digit(cmds[j]))
            return err_invalid_params(cmds[j]);

        // Duplicate the argument to store it as a key for environment variable removal.
        env->key = ft_strdup(cmds[j]);

        // If the key contains '=', truncate it at the position of '=' to extract only the variable name.
        if (ft_strchr(env->key, '='))
        {
            i = -1;
            while (env->key[++i] != '=')
                ;
            if (ft_strlen(env->key) + 1 == i)
                return 1;
            env->key[i] = '\0';
        }

        // Remove the environment variable with the specified key.
        remove_env_var(env->key, env);

        // Move to the next argument.
        j++;
    }

    // Return an exit status of 1 to indicate success.
    return 1;
}



