/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:37:42 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/05 23:25:00 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Change current directory based on the "cd" command arguments
int m_cd(char **cmds)
{
    // Change the current directory to the path specified in the command arguments
    chdir(cmds[1]);

    // Return 1 to indicate the success of the "cd" command
    return (1);
}
