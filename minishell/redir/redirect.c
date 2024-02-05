/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:41:36 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/05 23:57:30 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Open a file for writing based on the provided file name and redirection type.
// Parameters:
//   - file: The name of the file to open.
//   - redirect: The type of redirection (">" for truncation, ">>" for append).
// Returns:
//   The file descriptor of the opened file, or -1 on failure.
int open_out(char *file, char *redirect)
{
    if (file == NULL)
        return -1;

    if (verfi_word(redirect, ">"))
        return open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    else
        return open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
}

// Execute all commands in the given command structure and handle output redirections.
// Parameters:
//   - cmd: The command structure containing commands and potential output redirections.
//   - cmd_exe: The command structure for executing commands.
//   - p_i: The input file descriptor (pipe input).
//   - p_o: The output file descriptor (pipe output).
// Returns:
//   0 on success.
int all_nodes_no_enter(t_command *cmd, t_command *cmd_exe, int p_i, int p_o)
{
    int i;
    int fd_out;
    int flag;

    i = 0;
    flag = 0;

    // If there is a pipe output, execute the command with pipe output.
    if (p_o != -1)
        exe_node(cmd_exe, p_i, p_o, &flag);

    while (cmd->cmd[i] != NULL)
    {
        // Check for output redirections ">" and ">>".
        if (verfi_word(cmd->cmd[i], ">") || verfi_word(cmd->cmd[i], ">>"))
        {
            // Open the output file and execute the command with redirected output.
            fd_out = open_out(cmd->cmd[i + 1], cmd->cmd[i]);
            if (fd_out == -1)
                perror("ERREUR DE FICHIER");

            // Execute the command with the specified output redirection.
            exe_node(cmd_exe, p_i, fd_out, &flag);
            close(fd_out);
        }
        i++;
    }

    // If no output redirection is specified, execute the command with default output.
    if (flag == 0)
        exe_node(cmd_exe, p_i, 1, &flag);

    return 0;
}

// Open a file for input redirection or set up a heredoc.
// Parameters:
//   - file: The file name or delimiter for heredoc.
//   - redirect: The redirection symbol ("<").
// Returns:
//   File descriptor for input on success, -1 on failure.
int open_enter(char *file, char *redirect)
{
    if (file == NULL)
        return (-1);

    // Check for input redirection ("<").
    if (verfi_word(redirect, "<"))
    {
        // Open the file for reading.
        return open(file, O_RDONLY | O_CREAT, 0777);
    }
    else
    {
        // Set up a heredoc and return the file descriptor.
        return heredoc(file);
    }
}

// Execute the command with input and output redirections.
// Parameters:
//   - cmd: The command node.
//   - cmd_exe: The formatted command for execution.
//   - p_i: Input file descriptor.
//   - p_o: Output file descriptor.
// Returns:
//   0 on success.
int all_nodes(t_command *cmd, t_command *cmd_exe, int p_i, int p_o)
{
    int i;
    int fd_in;
    int flag;

    i = 0;
    flag = 0;

    // Execute the command without input redirection and with output redirection.
    if (p_i != -1 && ++flag > -1)
        all_nodes_no_enter(cmd, cmd_exe, p_i, p_o);

    while (cmd->cmd[i] != NULL)
    {
        // Handle input redirection ("<" or "<<").
        if (verfi_word(cmd->cmd[i], "<") || verfi_word(cmd->cmd[i], "<<"))
        {
            // Open the input file or set up a heredoc.
            fd_in = open_enter(cmd->cmd[i + 1], cmd->cmd[i]);
            if (fd_in == -1)
                perror("ERREUR DE FICHIER");

            // Execute the command with input redirection and output redirection.
            all_nodes_no_enter(cmd, cmd_exe, fd_in, p_o);
            flag++;

            // Close the input file or heredoc.
            close(fd_in);
        }
        i++;
    }

    // If no redirections were encountered, execute the command with default file descriptors.
    if (flag == 0)
        all_nodes_no_enter(cmd, cmd_exe, -1, p_o);

    return 0;
}

// Set up and execute redirections for a command.
// Parameters:
//   - cmd: The command node.
//   - p_i: Input file descriptor.
//   - p_o: Output file descriptor.
// Returns:
//   0 on success.
int redirect(t_command *cmd, int p_i, int p_o)
{
    t_command *cmd_exe;

    // Format the command for execution.
    cmd_exe = format_exe(cmd);

    // Handle input and output redirections.
    all_nodes(cmd, cmd_exe, p_i, p_o);

    // Update the command status.
    cmd->status = cmd_exe->status;

    // Free allocated memory.
    ft_freetabs(cmd_exe->cmd);
    ft_freetabs(cmd_exe->env.env_cpy);
    free(cmd_exe);

    return 0;
}





