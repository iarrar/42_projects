/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moula2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:35:28 by bgonon            #+#    #+#             */
/*   Updated: 2024/02/05 23:40:41 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Determine the length of a variable or command sequence starting from the given position in the string.
// This function scans the string from the specified position until the end or until it encounters
// characters such as '\"', '$', or whitespace.
// Parameters:
//   - str: The input string.
// Returns:
//   - The length of the variable or command sequence.
int long_doll(char *str)
{
    int i = 0;

    // Iterate through the string until reaching the end or encountering specific characters.
    while (str[i] != '\0' && str[i] != '\"')
    {
        i++;

        // If the character is '$', return the current position.
        if (str[i] == '$')
            return (i);

        // If the character is whitespace, return the current position.
        if (ft_isspace(str[i]) == 1)
            return (i);
    }

    // Return the length of the variable or command sequence.
    return (i);
}

// Resize the string by replacing it with the corresponding value from the environment.
// This function searches for a matching variable in the environment and returns its value.
// Parameters:
//   - str: The variable to be replaced.
//   - env: The environment array.
// Returns:
//   - The value of the variable in the environment, or an empty string if not found.
char *ft_resize(char *str, char **env)
{
    char *buff; // Buffer to store the value of the matching variable.
    int i = 0;

    // Iterate through the environment array.
    while (env[i])
    {
        // Check if the current environment variable matches the input variable.
        if (ft_strncmp(env[i], str, ft_strlen(str)) == 0 &&
            (env[i][ft_strlen(str)] == '='))
        {
            // Extract the value of the variable from the environment variable.
            buff = ft_substr(env[i], ft_strlen(str) + 1, ft_strlen(env[i]));
            return (buff);
        }
        else
            i++;
    }

    // Return an empty string if the variable is not found in the environment.
    return ("");
}


