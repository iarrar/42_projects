/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:37:12 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/05 23:50:26 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Implement here document feature.
// Parameters:
//   - eof: The delimiter indicating the end of the here document.
// Returns:
//   - The read end of the pipe.
int heredoc(char *eof)
{
    int pipefd[2];
    char *input;

    // Create a pipe.
    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Read input from the user until the specified delimiter is encountered.
    while (1)
    {
        // Prompt the user with "heredoc>" and read input.
        input = readline("heredoc>");

        // Check if the input matches the specified delimiter.
        if (ft_strncmp(input, eof, ft_strlen(eof)) == 0 &&
            ft_strlen(eof) == ft_strlen(input))
        {
            free(input);
            break;
        }

        // Write the input followed by a newline to the write end of the pipe.
        write(pipefd[1], input, strlen(input));
        write(pipefd[1], "\n", 1);

        // Free the allocated memory for input.
        free(input);
    }

    // Close the write end of the pipe.
    close(pipefd[1]);

    // Return the read end of the pipe.
    return (pipefd[0]);
}

