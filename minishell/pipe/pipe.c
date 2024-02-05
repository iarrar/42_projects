/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:52:18 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/05 23:49:48 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Create a pipeline and execute the commands in the input array.
// Parameters:
//   - l_cmd: An array of t_command structures representing the commands.
// Returns:
//   - 0 on success, -1 on failure.
int fake_tree(t_command *l_cmd)
{
    int i;
    int fd_in;
    int fd_out;
    int *fd_pipe;

    // Allocate memory for the pipe file descriptors.
    fd_pipe = (int *)ft_calloc(2, sizeof(int));
    if (!fd_pipe)
        return (-1);

    fd_in = -1;
    fd_out = -1;
    i = 0;

    // Iterate through the commands, setting up pipes and executing each command.
    while (l_cmd[i + 1].cmd != NULL)
    {
        // Create a pipe.
        pipe(fd_pipe);
        fd_out = fd_pipe[1];

        // Redirect input and output for the current command.
        redirect(&l_cmd[i], fd_in, fd_out);

        // Close the input file descriptor if it's not the first command.
        if (fd_in != -1)
            close(fd_in);

        // Update the input file descriptor for the next command.
        fd_in = fd_pipe[0];

        // Close the output file descriptor.
        close(fd_out);

        i++;
    }

    // Redirect input and output for the last command in the pipeline.
    redirect(&l_cmd[i], fd_in, -1);

    // Free the allocated memory for pipe file descriptors.
    free(fd_pipe);

    return (0);
}
