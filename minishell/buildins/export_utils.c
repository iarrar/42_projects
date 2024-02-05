/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:03:58 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/05 23:29:12 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Duplicate the environment variables array
char **envp_cpy(char **envp)
{
    char **env;
    int len;
    int i;

    // Initialize index and calculate the length of the input envp array
    i = -1;
    len = -1;
    while (envp[++len])
        ;

    // Allocate memory for the new environment variables array
    env = malloc(sizeof(char *) * (len + 1));
    if (!env)
        return (NULL);

    // Set the last element of the new array to NULL
    env[len] = NULL;

    // Copy each element of the input envp array to the new array
    while (envp[++i])
    {
        env[i] = ft_strdup(envp[i]);
    }

    // Return the duplicated environment variables array
    return (env);
}

// Count the number of arguments in an array of strings
int count_args(char **str)
{
    int count;

    // Initialize the counter
    count = 0;

    // Check if the input array is NULL
    if (str == NULL)
        return (0);

    // Iterate through the array and count non-NULL elements
    while (str[count] != NULL)
    {
        count++;
    }

    // Return the total count of arguments
    return (count);
}

// Check if the first character of a string is a digit
int check_digit(char *str)
{
    int i;

    // Initialize the index
    i = 0;

    // Check if the first character is present and is a digit
    if (str[0] && ft_isdigit(str[0]))
        return (1);

    // Increment the index
    i++;

    // Return 0 if the first character is not a digit
    return (0);
}

// Concatenate a specified number of characters from one string to another
char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    unsigned int i;
    unsigned int j;

    // Find the end of the destination string
    i = 0;
    while (dest[i] != '\0')
        i++;

    // Copy characters from the source to the destination, up to the specified limit (nb)
    j = 0;
    while (src[j] != '\0' && j < nb)
    {
        dest[i + j] = src[j];
        j++;
    }

    // Add a null terminator at the end of the concatenated string
    dest[i + j] = '\0';

    // Return the modified destination string
    return (dest);
}

