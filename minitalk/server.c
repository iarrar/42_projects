/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:19:43 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/05 23:21:03 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "minitalk.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Function to calculate the length of a string
int ft_strlenc(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

// Function to concatenate two strings
char *ft_strjoin(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    char *dest = malloc(sizeof(char) * (ft_strlenc(s1) + 2));
    if (!dest)
        return (NULL);
    while (s1[i])
	{
        dest[i] = s1[i];
        i++;
    }
    while (s2[j])
	{
        dest[i] = s2[j];
        j++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

// Function to create a string with a single character
char *creastr(char c)
{
    char *dest = malloc(sizeof(char) * 2);
    dest[0] = c;
    dest[1] = '\0';
    return (dest);
}

// Signal handler function
void handler(int signal)
{
    static int bitcount = 0;
    static char c;
    static char *dest = "";
    char *s2;

    if (signal == SIGUSR1)
        c |= (1 << bitcount);
    bitcount++;
    if (bitcount == 8)
	{
        if (c == 0)
		{
            ft_printf("%s", dest);
            free(dest);
            bitcount = 0;
        }
		else
		{
            s2 = creastr(c);
            dest = ft_strjoin(dest, s2);
            free(s2);
            bitcount = 0;
            c = 0;
        }
    }
}

// Main function
int main(int argc, char **argv)
{
    if (argc)
	{
        signal(SIGUSR1, &handler);
        signal(SIGUSR2, &handler);
        ft_printf("pid = %d\n", getpid());
    }
    while (argv[0])
        ;
    return (0);
}
