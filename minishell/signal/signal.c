/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:58:11 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/05 23:59:50 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Signal handler for Ctrl+C (SIGINT)
void ft_ctrlc(int sign)
{
    if (!sign)
        printf("sign\n"); //  debugging statement.
    printf("\n"); // Print a newline character.
    rl_on_new_line();
    rl_replace_line("", 0); // Replace the current line with an empty string.
    rl_redisplay(); // Redisplay the command line prompt.
}

// Signal handler for Ctrl+\ (SIGQUIT).
void ft_ctrlslash(int sign)
{
    if (!sign)
        printf("sign\n"); // debugging statement.
    rl_on_new_line();
    rl_redisplay(); // Redisplay the command line prompt.
}


