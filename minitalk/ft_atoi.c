/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:07:18 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/05 23:18:47 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Function to convert a string to an integer
int ft_atoi(const char *str) {
    int i = 0;
    int sign = 1;
    int res = 0;

    // Skip leading whitespaces
    while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)) {
        i++;
    }

    // Handle sign (positive or negative)
    if (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            sign = -1;
        }
        i++;
    }

    // Convert remaining digits to integer
    while (str[i] && (str[i] >= '0' && str[i] <= '9')) {
        res = res * 10 + (str[i] - '0');
        i++;
    }

    return (res * sign);
}

