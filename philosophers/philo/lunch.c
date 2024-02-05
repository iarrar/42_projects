/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:10:40 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/05 21:16:26 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Philosopher routine for even-numbered philosophers
void ft_im_even(t_philo *philo)
{
	// Check if philosopher is dead
	if (ft_am_i_dead(philo) == 1)
		return;

	// Attempt to lock left fork mutex
	if (pthread_mutex_lock(philo->lf) == 0 && ft_am_i_dead(philo) == 0)
	{
		// Attempt to lock right fork mutex
		if (pthread_mutex_lock(philo->rf) == 0)
		{
			// Perform eating routine and release fork mutexes
			ft_eating(philo);
			pthread_mutex_unlock(philo->rf);
			pthread_mutex_unlock(philo->lf);
		}
		else
			pthread_mutex_unlock(philo->lf);
	}
	else
		pthread_mutex_unlock(philo->lf);

	// Return from the routine
	return;
}


// Philosopher routine for odd-numbered philosophers
void ft_im_odd(t_philo *philo)
{
	// Check if philosopher is dead
	if (ft_am_i_dead(philo) == 1)
		return;

	// Attempt to lock right fork mutex
	if (pthread_mutex_lock(philo->rf) == 0 && ft_am_i_dead(philo) == 0)
	{
		// Attempt to lock left fork mutex
		if (pthread_mutex_lock(philo->lf) == 0)
		{
			// Perform eating routine and release fork mutexes
			ft_eating(philo);
			pthread_mutex_unlock(philo->lf);
			pthread_mutex_unlock(philo->rf);
		}
		else
			pthread_mutex_unlock(philo->rf);
	}
	else
		pthread_mutex_unlock(philo->rf);

	// Return from the routine
	return;
}


// Philosopher eating routine
void ft_eating(t_philo *philo)
{
	// Check if philosopher is dead
	if (ft_am_i_dead(philo) == 1)
		return;

	// Lock time mutex and update philosopher's start timestamp
	pthread_mutex_lock(philo->time);
	philo->start = ft_timestamp(philo);
	pthread_mutex_unlock(philo->time);

	// Print messages about taking forks and eating
	pthread_mutex_lock(philo->write);
	printf("[timestamp = %ld ms] : philo %d has taken a fork\n", ft_timestamp(philo), philo->count);
	printf("[timestamp = %ld ms] : philo %d has taken a fork\n", ft_timestamp(philo), philo->count);
	pthread_mutex_unlock(philo->write);
	pthread_mutex_lock(philo->write);
	printf("[timestamp = %ld ms] : philo %d is eating\n", ft_timestamp(philo), philo->count);
	pthread_mutex_unlock(philo->write);

	// Lock and update meal round count if applicable
	pthread_mutex_lock(philo->m_round);
	if (philo->round > 0)
		philo->round--;
	pthread_mutex_unlock(philo->m_round);

	// Sleep for the specified eating time
	usleep(philo->tte * 1000);
}

