/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:04:27 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/05 23:24:32 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    if (s1 == NULL)
        return (-1);
    while (s1[i] != '\0')
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}

// Execute built-in commands based on the input command array and environment
int m_exe_buildin(char **cmds, t_env *env)
{
    // Check for the "echo" command with the "-n" option
    if (ft_strcmp(cmds[0], "echo") && ft_strcmp(cmds[1], "-n") == 0)
        return (m_echo_n(cmds));
    // Check for the "cd" command
    else if (ft_strcmp(cmds[0], "cd") == 0)
        return (m_cd(cmds));
    // Check for the "pwd" command
    else if (ft_strcmp(cmds[0], "pwd") == 0)
        return (m_pwd());
    // Check for the "env" command
    else if (ft_strcmp(cmds[0], "env") == 0)
        return (m_env(env->env_cpy));
    // Check for the "export" command
    else if (ft_strcmp(cmds[0], "export") == 0)
        return (m_export(cmds, env));
    // Check for the "unset" command
    else if (ft_strcmp(cmds[0], "unset") == 0)
        return (m_unset(cmds, env));
    // Check for the "exit" command
    else if (ft_strcmp(cmds[0], "exit") == 0)
        return (m_exit(cmds, env->env_cpy));
    else
        return (0);
}

