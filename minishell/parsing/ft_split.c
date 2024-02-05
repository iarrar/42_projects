/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 01:20:16 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/05 23:45:47 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Copy at most 'size - 1' characters from the source string to the destination string.
// Null-terminate the result. If the destination string starts with a single quote or
// double quote and the resulting string has only one character, null-terminate the
// destination string.
// Parameters:
//   - dst: The destination string.
//   - src: The source string.
//   - size: The size of the destination buffer.
// Returns:
//   - The length of the source string.
int ft_strlcpy2(char *dst, char *src, int size)
{
    int i;      // Loop variable.
    int length; // Length of the source string.

    i = 0;
    length = ft_strlen(src);

    // Check if the destination and source strings are not NULL.
    if (!dst || !src)
        return (0);

    // Check if the size is 0. If so, return the length of the source string.
    if (size == 0)
        return (length);

    // Copy at most 'size - 1' characters from the source to the destination.
    while ((src[i] != '\0') && (i < size - 1))
    {
        dst[i] = src[i];
        i++;
    }

    // Null-terminate the destination string.
    dst[i] = '\0';

    // Check if the first character of the destination is a single quote or double quote,
    // and the resulting string has only one character. If so, null-terminate the destination.
    if ((dst[0] == '\'' || dst[0] == '\"') && dst[1] == '\0')
        dst[0] = '\0';

    // Return the length of the source string.
    return (length);
}

// Find the index of the first character in a word in the string 's',
// starting from index 'a', and considering the delimiter character 'c'.
// Parameters:
//   - s: The input string.
//   - c: The delimiter character.
//   - a: The starting index.
// Returns:
//   - The index of the first character in a word.
int ft_actualword(char *s, char c, int a)
{
    int i = a;

    // Iterate through the string until a non-delimiter character is found.
    while (s[i] && s[i] == c)
        i++;

    // Return the index of the first character in a word.
    return i;
}

// Find the index of the character immediately following the end of a word
// in the string 's', starting from index 'a', and considering the delimiter character 'c'.
// Also, consider the special case when the delimiter character is a single-quote or double-quote.
// Parameters:
//   - s: The input string.
//   - c: The delimiter character.
//   - a: The starting index.
// Returns:
//   - The index of the character immediately following the end of a word.
int ft_nextword(char *s, char c, int a)
{
    int i = a;
    int b = 1;

    // Adjust behavior for single-quote or double-quote delimiters.
    if (c == '\'' || c == '\"')
    {
        b = 2;
        i = a + 1;
    }

    // Iterate through the string until the delimiter character or the end of the string is found.
    while (s[i] && s[i] != c)
        i++;

    // Return the index of the character immediately following the end of a word.
    return i + b;
}

// Count the number of words in the string 's' based on the delimiter character 'c'.
// Words enclosed in single-quotes or double-quotes are considered as a single word.
// Parameters:
//   - s: The input string.
//   - c: The delimiter character.
// Returns:
//   - The number of words in the string.
int ft_wordcount(char *s, char c)
{
    int i = 0;
    int count = 0;

    while (s[i])
    {
        if (s[i] != c)
        {
            count++;

            // Handle words enclosed in single-quotes.
            if (s[i] == '\'')
                while (s[++i] != '\'')
                    i = i;

            // Handle words enclosed in double-quotes.
            else if (s[i] == '\"')
                while (s[++i] != '\"')
                    i = i;

            // Move to the next word.
            while (s[i] != c && s[i])
                i++;
        }
        else
            i++;
    }

    return count;
}

// Split the string 's' into an array of words based on the delimiter character 'c'.
// Words enclosed in single-quotes or double-quotes are considered as a single word.
// Parameters:
//   - s: The input string.
//   - c: The delimiter character.
//   - actualw: Index pointing to the start of the current word.
//   - nextw: Index pointing to the start of the next word.
// Returns:
//   - An array of strings representing the words in the string.
char **split(char *s, char c, int actualw, int nextw)
{
    char **cmds;
    int cnt;
    int j;

    j = 0;
    cnt = ft_wordcount(s, c);
    cmds = (char **)malloc(sizeof(char *) * (cnt + 1));
    
    while (j < cnt)
    {
        actualw = ft_actualword(s, c, nextw);
        
        // Handle words enclosed in double-quotes or single-quotes.
        if (s[actualw] == '\"')
            nextw = ft_nextword(s, '\"', actualw);
        else if (s[actualw] == '\'')
            nextw = ft_nextword(s, '\'', actualw);
        else
            nextw = ft_nextword(s, c, actualw);
        
        cmds[j] = malloc(sizeof(char) * ((nextw) - actualw));
        ft_strlcpy2(cmds[j], s + actualw, ((nextw) - actualw));
        j++;
    }
    
    cmds[j] = NULL;
    return (cmds);
}

