/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:27:38 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/05 21:25:39 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Function to convert a string to an integer
int ft_atoi(const char *str)
{
	int i;
	int sign;
	int res;

	// Initialize variables
	res = 0;
	i = 0;
	sign = 1;

	// Skip leading whitespaces
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;

	// Handle the sign
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	// Convert digits to integer
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}

	return (res * sign);
}

// Function to get the current timestamp in milliseconds
long int ft_timestamp(t_philo *philo)
{
	long int ts;
	struct timeval tv;

	// Get current time
	gettimeofday(&tv, NULL);

	// Calculate timestamp in milliseconds
	ts = (((tv.tv_sec - philo->pzeros) * 1000000)
			+ (tv.tv_usec - philo->pzerom)) / 1000;

	// Return the calculated timestamp
	return (ts);
}

// Function to check if a philosopher is dead or has completed their rounds
int ft_am_i_dead(t_philo *philo)
{
	// Lock mutexes for dead and round variables
	pthread_mutex_lock(philo->dead);
	pthread_mutex_lock(philo->m_round);

	// Check if the philosopher is dead or has completed rounds
	if (philo->die == 1 || philo->round == 0)
	{
		// Unlock mutexes and return 1 (true)
		pthread_mutex_unlock(philo->m_round);
		pthread_mutex_unlock(philo->dead);
		return (1);
	}

	// Unlock mutexes and return 0 (false)
	pthread_mutex_unlock(philo->m_round);
	pthread_mutex_unlock(philo->dead);
	return (0);
}

// Function to set the "die" flag for all philosophers, signaling termination
void ft_kill_them_all(t_data *data)
{
	int i;

	// Lock the mutex for the dead variable
	pthread_mutex_lock(data->monitor->dead);

	// Set the "die" flag to 1 for all philosophers
	while (i < data->philo->nphilo)
	{
		data->philo[i].die = 1;
		i++;
	}

	// Unlock the mutex for the dead variable
	pthread_mutex_unlock(data->monitor->dead);
}




