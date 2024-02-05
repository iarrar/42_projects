/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:41:10 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/05 23:36:28 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Check if a string consists entirely of a specified character.
// This function checks if every character in the given string is equal to the specified character.
// Parameters:
//   - str: The string to be checked.
//   - c: The character to compare against.
// Return:
//   - 1: If every character in the string is equal to the specified character.
//   - 0: If there is at least one character in the string that is not equal to the specified character.
int ft_check_empty(char *str, char c)
{
    size_t i; // Variable to iterate through the characters of the string.
    size_t a; // Variable to count the occurrences of the specified character.

    // Initialize variables.
    i = 0;
    a = 0;

    // Iterate through the characters of the string.
    while (str[i] != '\0')
    {
        // Check if the current character is equal to the specified character.
        if (str[i] == c)
            a++;

        // Move to the next character.
        i++;
    }

    // Check if the count of the specified character is equal to the total number of characters in the string.
    // If true, every character in the string is equal to the specified character, so return 1.
    // If false, there is at least one character that is not equal to the specified character, so return 0.
    if (a == i)
        return 1;
    else
        return 0;
}

// Add a command to the history if it is not empty.
// This function adds a command to the Readline history if the command is not empty or consists only of spaces.
// Parameters:
//   - cmd: The command to be added to the history.
void handle_history(char *cmd)
{
    // Check if the command is NULL or consists only of spaces.
    // If true, do not add it to the history.
    if (cmd == NULL || ft_check_empty(cmd, ' ') == 1)
        return;

    // Add the non-empty command to the Readline history.
    add_history(cmd);

    // Move to a new line in the Readline interface.
    rl_on_new_line();
}


