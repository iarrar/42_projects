/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:41:23 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/04 15:29:19 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

// Function to convert a pointer to a base and print the result
int ft_base_add(void *ptr, char *str);

// Function to print the address of a pointer in hexadecimal format
int ft_adresse(void *ptr);

// Function to zero out a block of memory
void ft_bzero(void *s, size_t n);

// Function to allocate memory and zero it out
void *ft_calloc(size_t nmemb, size_t size);

// Function to count occurrences of a character in a string
int ft_countchar(const char *str, char c);

// Main printf function that handles format specifiers
int ft_printf(const char *str, ...);

// Function to print a single character to a specified file descriptor
int ft_putchar_fd(char c, int fd);

// Function to print a string followed by a newline to a specified file descriptor
void ft_putendl_fd(char *s, int fd);

// Function to print an integer to a specified file descriptor
int ft_putnbr_fd(int n, int fd);

// Function to calculate the number of digits required to represent an unsigned integer in a given base
int size_unsigned(unsigned int n, unsigned int base);

// Function to print an unsigned integer to a specified file descriptor
int ft_putnbru_fd(unsigned int n, int fd);

// Function to print an unsigned integer in a given base to a specified file descriptor
int ft_putnbru_base(unsigned int n, int fd, char *base);

// Function to print a string to a specified file descriptor
int ft_putstr_fd(char *s, int fd);

// Function to calculate the length of a string
int ft_strlen(const char *str);

// Function to handle individual format specifiers in printf
int ft_which_sign(va_list *args, char c);

// Function to calculate the number of digits required to represent an integer in a given base
int size_base(int n, int base);


#endif
