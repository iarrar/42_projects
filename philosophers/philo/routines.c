/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:29:12 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/05 21:37:03 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Routine function for each philosopher to execute in a separate thread
void *routine(void *arg)
{
	t_philo	*philo;
	int		i;
	int		j;

	// Initialize variables
	i = 0;
	j = -1;
	philo = (t_philo *)arg;

	// Loop until the philosopher either dies or completes required rounds
	while (i == 0 && j != 0)
	{
		// Attempt to acquire forks and eat
		ft_bandb(philo);

		// Think
		ft_i_think(philo);

		// Sleep
		ft_i_slip(philo);

		// Check if the philosopher has died
		pthread_mutex_lock(philo->dead);
		i = philo->die;
		pthread_mutex_unlock(philo->dead);

		// Check the remaining rounds
		pthread_mutex_lock(philo->m_round);
		j = philo->round;
		pthread_mutex_unlock(philo->m_round);
	}

	return (NULL);
}

// Function to simulate the "wait for both forks and eat" action
void ft_bandb(t_philo *philo)
{
	// Check if the philosopher is already dead
	if (ft_am_i_dead(philo) == 1)
		return;

	// If there is only one philosopher, directly acquire the fork and eat
	if (philo->nphilo == 1)
	{
		pthread_mutex_lock(philo->lf);
		printf("[timestamp = %ld ms] : philo %d \
has taken a fork\n", ft_timestamp(philo), philo->count);
		usleep(philo->ttd * 1100);
		pthread_mutex_unlock(philo->lf);
		return;
	}
	// If the philosopher's count is even, execute the "even" action, otherwise, execute the "odd" action
	else if (philo->count % 2 == 0)
		ft_im_even(philo);
	else
		ft_im_odd(philo);

	return;
}

// Function to simulate the "think" action of a philosopher
void ft_i_think(t_philo *philo)
{
	// Check if the philosopher is already dead
	if (ft_am_i_dead(philo) == 1)
		return;

	// Lock the write mutex to print the thinking message
	pthread_mutex_lock(philo->write);
	printf("[timestamp = %ld ms] : philo %d \
is thinking\n", ft_timestamp(philo), philo->count);
	pthread_mutex_unlock(philo->write);

	return;
}

// Function to simulate the "sleep" action of a philosopher
void ft_i_slip(t_philo *philo)
{
	// Check if the philosopher is already dead
	if (ft_am_i_dead(philo) == 1)
		return;

	// Lock the write mutex to print the sleeping message
	pthread_mutex_lock(philo->write);
	printf("[timestamp = %ld ms] : philo %d \
is sleeping\n", ft_timestamp(philo), philo->count);
	pthread_mutex_unlock(philo->write);

	// Sleep for the specified time
	usleep(philo->tts * 1000);

	return;
}



