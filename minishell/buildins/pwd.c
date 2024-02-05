/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:14:34 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/05 23:32:30 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Implementation of the pwd built-in command
// Displays the current working directory
// Returns 1 upon successful execution
int m_pwd(void)
{
    // Declare variables to store the current working directory
    char *s;
    size_t size;

    // Set the size for the buffer
    size = 2042;

    // Allocate memory for the buffer
    s = malloc((size + 1) * sizeof(char));

    // Check if memory allocation is successful; exit if not
    if (s == NULL)
        exit(EXIT_FAILURE);

    // Get the current working directory and store it in the buffer
    if (getcwd(s, size) == NULL)
        exit(EXIT_FAILURE);

    // Display the current working directory
    printf("%s\n", s);

    // Free the allocated memory
    free(s);

    // Return 1 upon successful execution
    return (1);
}

