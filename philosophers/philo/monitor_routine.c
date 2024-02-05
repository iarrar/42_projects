/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:12:36 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/05 21:19:07 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Calculate remaining time for a philosopher to starve
int ft_time_left(t_data *data, int i)
{
	int res;

	// Lock time mutex and compute remaining time
	pthread_mutex_lock(data->monitor->time);
	res = (data->philo[i].start + data->philo[i].ttd) - ft_timestamp(&data->philo[i]);
	pthread_mutex_unlock(data->monitor->time);

	return (res);
}


// Check if all philosophers have completed their meals
int ft_check_meals(t_data *data)
{
	int i;
	int meals;

	meals = 0;
	i = 0;

	// Lock each philosopher's round mutex and count completed meals
	while (i < data->philo->nphilo)
	{
		pthread_mutex_lock(data->philo[i].m_round);
		if (data->philo[i].round == 0)
			meals++;
		pthread_mutex_unlock(data->philo[i].m_round);
		i++;
	}

	// If all philosophers have completed their meals, return 1; otherwise, return 0
	if (meals == data->philo->nphilo)
		return (1);
	else
		return (0);
}

// Check if the given philosopher has completed the specified number of meals
int ft_check_round(t_data *data, int i)
{
	// Lock the global round mutex
	pthread_mutex_lock(data->monitor->m_round);

	// If the philosopher has completed all meals, unlock the mutex and return 0; otherwise, return 1
	if (data->philo[i].round == 0)
	{
		pthread_mutex_unlock(data->monitor->m_round);
		return (0);
	}
	else
		pthread_mutex_unlock(data->monitor->m_round);

	return (1);
}

// Monitor function to check the status of philosophers and terminate if necessary
void *ft_monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;

	// Continue monitoring until all philosophers have completed their meals
	while (ft_check_meals(data) == 0)
	{
		i = 0;

		// Check each philosopher's time left and whether they have completed their meals
		while (i < data->philo->nphilo)
		{
			// If a philosopher's time is up and they haven't completed their meals, print a death message
			if (ft_time_left(data, i) < -1 && ft_check_round(data, i) != 0)
			{
				pthread_mutex_lock(data->monitor->write);
				printf("[timestamp monitor = %ld ms] philo %d died\n", ft_timestamp(&data->philo[i]), i);
				pthread_mutex_unlock(data->monitor->write);
				// Terminate all philosophers and return from the monitor function
				ft_kill_them_all(data);
				return (NULL);
			}
			i++;
		}
	}

	return (NULL);
}


