/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moula.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:23:35 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/05 23:39:46 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Insert the content of one string into another string at a specified position.
// This function inserts the content of the 'app' string into the 'src' string at the specified 'start' position.
// Parameters:
//   - src: The source string into which the content is inserted.
//   - app: The string whose content is inserted into the source string.
//   - start: The position in the source string where the insertion starts.
//   - size: The size of the portion of the source string to be replaced by the inserted content.
// Returns:
//   - A new string with the content of 'app' inserted into 'src'.
char *ft_insert(char *src, char *app, int start, int size)
{
    char *dest;
    int i;
    int j;

    i = 0;
    j = 0;

    // Calculate the size of the destination string.
    dest = malloc(sizeof(char) * ((ft_strlen(src) + ft_strlen(app)) - (size)));

    // Copy the characters from the source string before the insertion point.
    while (i < start)
    {
        dest[i] = src[i];
        i++;
    }

    // Copy the characters from the 'app' string into the destination string.
    while (app[j])
    {
        dest[i] = app[j];
        i++;
        j++;
    }

    // Copy the remaining characters from the source string after the inserted content.
    while (src[i - j + size + 1])
    {
        dest[i] = src[i - j + size + 1];
        i++;
    }

    // Null-terminate the destination string.
    dest[i] = '\0';

    // Return the newly created string.
    return (dest);
}



char	*ft_var_int(char *str, int err, int i, int j)
{
	char	*dest;
	char	*buff;
	int		size;

	size = -1;
	buff = ft_itoa(err);
	dest = malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(str) - 1));
	while (str[i + j])
	{
		if (str[i] == '$' && str[i + 1] == '?')
		{
			j = 0;
			while (buff[++size] != '\0')
				dest[i + size] = buff[size];
			j = j + 2;
		}
		dest[i + size] = str[i + j];
		i++;
	}
	dest[i + size] = '\0';
	free(buff);
	str = ft_strdup(dest);
	free(dest);
	return (str);
}
// Replace environment variables in a string with their corresponding values.
// This function searches for environment variables (indicated by '$') in the input string
// and replaces them with their corresponding values from the 'env' array.
// Parameters:
//   - str: The input string containing potential environment variables.
//   - env: The array of environment variables.
//   - i: The starting index in the input string for variable replacement.
// Returns:
//   - A new string with environment variables replaced by their values.
char *ft_replace_var(char *str, char **env, int i)
{
    int size;
    char *buff;
    char *dest;
    char *var;

    size = 0;

    // Iterate through the string to find and replace environment variables.
    while (str[i])
    {
        if (str[i] == '$' && str[i + 1] != '?')
        {
            // Determine the size of the environment variable.
            size = long_doll(&str[i + 1]);

            // Extract the environment variable.
            var = ft_substr(str, i + 1, size);

            // Resize the environment variable to its corresponding value.
            buff = ft_resize(var, env);

            // Insert the value of the environment variable back into the string.
            dest = ft_insert(str, buff, i, ft_strlen(var));

            // Update the input string with the replaced content.
            str = ft_strdup(dest);

            // Reset the index to the beginning for further replacements.
            i = 0;
            continue;
        }
        i++;
    }

    // Free dynamically allocated memory.
    free(var);
    free(buff);
    free(dest);

    // Return the modified string with replaced environment variables.
    return (str);
}

// Search for the existence of the special environment variable "$?" in a string.
// This function checks if the given string contains the pattern "$?".
// Parameters:
//   - str: The input string to be searched.
// Returns:
//   - 1 if the pattern "$?" is found, indicating the presence of the special environment variable.
//   - 0 otherwise.
int ft_search(char *str)
{
    int i = 0;

    // Iterate through the string to find the pattern "$?".
    while (str[i + 1])
    {
        if (str[i] == '$' && str[i + 1] == '?')
            return (1); // Pattern "$?" found.
        else
            i++;
    }

    // Pattern "$?" not found in the string.
    return (0);
}

// Process and modify an array of strings (command and arguments) based on specific conditions.
// This function iterates through each string in the array and performs modifications.
// Parameters:
//   - cmd: The array of strings representing the command and its arguments.
//   - env: The environment variables.
//   - err: Error indicator used in the ft_var_int function.
// Returns:
//   - The modified array of strings.
char **ft_parkour(char **cmd, char **env, int err)
{
    int i = 0;

    // Iterate through each string in the array.
    while (cmd[i])
    {
        // If the string contains the pattern "$?" and doesn't start with "'", replace it using ft_var_int.
        if (ft_search(cmd[i]) && cmd[i][0] != '\'')
        {
            cmd[i] = ft_var_int(cmd[i], err, 0, 0);
        }

        // If the string contains '$' and doesn't start with "'", replace variable occurrences using ft_replace_var.
        if (ft_strchr(cmd[i], '$') && cmd[i][0] != '\'')
            cmd[i] = ft_replace_var(cmd[i], env, 0);

        i++;
    }

    // Return the modified array of strings.
    return (cmd);
}

