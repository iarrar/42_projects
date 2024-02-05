/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:34:47 by bgonon            #+#    #+#             */
/*   Updated: 2024/02/05 23:52:20 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Check if the command is in "/bin/". If not, prepend "/bin/" to it.
// Parameters:
//   - cmd: The command to check.
// Returns:
//   - The original cmd if it starts with "/bin/", or "/bin/" + cmd.
char *is_bin(char *cmd)
{
    if (ft_strnstr(cmd, "/bin/", 5))
        return (cmd);
    else
        return (ft_strjoin("/bin/", cmd));
}

// Handle errors related to process execution.
// Parameters:
//   - flag: An integer flag to determine the type of error.
// Returns:
//   - Exits the program with a failure status.
int exe_error(int flag)
{
    if (flag == 0)
        perror("Erreur de processus");
    else
        perror("Erreur d'exécution");
    exit(EXIT_FAILURE);
    return (-1);
}

// Execute a command specified by a t_command structure.
// Parameters:
//   - cmd: A pointer to a t_command structure representing the command to execute.
// Returns:
//   - 0 on successful execution, -1 on failure.
int m_exe(t_command *cmd)
{
    pid_t child_pid;
    int status;
    char *file;

    cmd->status = 0;

    // Create a child process
    child_pid = fork();

    if (child_pid == -1)
    {
        // Failed to create a child process
        return exe_error(0);
    }
    else if (child_pid == 0)
    {
        // In the child process

        // Adjust the path of the executable if necessary
        file = is_bin(cmd->cmd[0]);

        // Attempt to execute the command
        execve(file, cmd->cmd, cmd->env.env_cpy);

        // If execve fails, handle the error
        return exe_error(1);
    }
    else
    {
        // In the parent process

        // Wait for the child process to complete
        waitpid(child_pid, &status, 0);

        // Check if the child process exited normally
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
        {
            cmd->status = 127;
            printf("La commande FAILED end %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}

// Execute a command specified by a t_command structure with input and output redirection.
// Parameters:
//   - cmd: A pointer to a t_command structure representing the command to execute.
//   - in: File descriptor for input redirection.
//   - out: File descriptor for output redirection.
//   - flag: A pointer to an integer flag that is incremented.
void exe_node(t_command *cmd, int in, int out, int *flag)
{
    int origin_fd;
    int ori_fd_in;

    // Save the original file descriptors for stdout and stdin
    origin_fd = dup(STDOUT_FILENO);
    ori_fd_in = dup(STDIN_FILENO);

    // Redirect standard input if in > 0
    if (in > 0)
        dup2(in, 0);

    // Redirect standard output if out > 0
    if (out > 0)
        dup2(out, 1);

    // Execute the command
    m_exe(cmd);

    // Restore the original file descriptors
    dup2(origin_fd, 1);
    dup2(ori_fd_in, 0);

    // Increment the flag
    *flag = *flag + 1;
}
