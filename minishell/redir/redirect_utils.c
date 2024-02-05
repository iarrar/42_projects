/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:56:11 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/05 23:54:23 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Check if a given word matches a specified verification string.
// Parameters:
//   - word: The word to be checked.
//   - verif: The verification string to compare against.
// Returns:
//   - 1 if the word matches the verification string exactly, 0 otherwise.
int verfi_word(const char *word, const char *verif)
{
    int size = ft_strlen(verif);

    // Compare the word with the verification string
    if (!ft_strncmp(word, verif, size) && ft_strlen(word) == size)
        return (1);

    // Return 0 if the word does not match the verification string
    return (0);
}

// Check if a given word represents a redirection operator.
// Parameters:
//   - word: The word to be checked.
// Returns:
//   - 1 if the word is "<" (input redirection).
//   - 2 if the word is "<<" (here document input redirection).
//   - 3 if the word is ">" (output redirection).
//   - 4 if the word is ">>" (append output redirection).
//   - 0 if the word is not a redirection operator.
int is_redir(char *word)
{
    // Check for different redirection operators
    if (verfi_word(word, "<") == 1)
        return 1;
    if (verfi_word(word, "<<") == 1)
        return 2;
    if (verfi_word(word, ">") == 1)
        return 3;
    if (verfi_word(word, ">>") == 1)
        return 4;

    // Return 0 if the word is not a redirection operator
    return 0;
}

// Calculate the number of words in an array of strings, excluding redirection operators.
// Parameters:
//   - tab: The array of strings.
// Returns:
//   The number of words in the array, excluding redirection operators.
int nb_word(char **tab)
{
    int i = 0;
    int count = 0;

    while (tab[i] != NULL)
    {
        if (!is_redir(tab[i]))
            count++;
        else
            i++;
        i++;
    }

    return count;
}

// Create a new t_command structure by removing redirection operators from the original cmd.
// Parameters:
//   - cmd: The original t_command structure.
// Returns:
//   A new t_command structure with redirection operators removed.
t_command *format_exe(t_command *cmd)
{
    int i = 0;
    int j = 0;
    t_command *format;

    format = malloc(sizeof(t_command));
    format->cmd = (char **)ft_calloc(nb_word(cmd->cmd) + 1, sizeof(char *));
    i = 0;
    j = 0;
    
    while (cmd->cmd[i] != NULL)
    {
        if (!is_redir(cmd->cmd[i]))
        {
            format->cmd[j] = ft_strdup(cmd->cmd[i]);
            j++;
        }
        else
            i++;
        if (cmd->cmd[i] != NULL)
            i++;
    }

    format->cmd[j] = NULL;
    format->env.env_cpy = envp_cpy(cmd->env.env_cpy);

    return format;
}

