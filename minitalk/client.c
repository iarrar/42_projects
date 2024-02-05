/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:21:45 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/05 23:18:10 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <signal.h>

// Function to convert a character to a series of signals and send them to the specified process ID
void convert(int pid, char c)
{
    int bit = 0;

    // Loop through each bit (8 bits in a char)
    while (bit < 8) {
        // Check the value of the bit and send corresponding signal to the process ID
        if (c & (1 << bit))
            kill(pid, SIGUSR1); // Signal for bit 1
        else
            kill(pid, SIGUSR2); // Signal for bit 0

        usleep(150); // Delay to ensure signals are properly received
        bit++;
    }
}

// Function to convert and send the entire string to the specified process ID
void splitstr(int pid, char *str) 
{
    int i = 0;

    // Loop through each character in the string
    while (str[i]) {
        convert(pid, str[i]); // Convert and send each character
        i++;
    }

    convert(pid, str[i]); // Send the null terminator to indicate the end of the string
}

int main(int argc, char **argv)
{
    int pid;

    // Check if the correct number of arguments is provided
    if (argc != 3)
        return 0;
    else {
        pid = ft_atoi(argv[1]); // Convert the string argument to integer (process ID)
        splitstr(pid, argv[2]); // Send the string to the specified process ID
    }

    return 0;
}
