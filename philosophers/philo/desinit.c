/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:30:19 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/05 21:09:59 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Function to clean up resources and free memory
void ft_ciao(t_data *data)
{
	// Variable to iterate over the philosophers
	int i;

	i = 0;

	// Iterate over each philosopher
	while (i < data->philo->nphilo)
	{
		// Destroy the left fork mutex of the current philosopher
		pthread_mutex_destroy(data->philo[i].lf);
		i++;
	}

	// Destroy monitor mutexes
	pthread_mutex_destroy(data->monitor->write);
	pthread_mutex_destroy(data->monitor->dead);

	// Free memory for philosopher mutex array
	free(data->philo->mutex);

	// Free memory for monitor mutex arrays
	free(data->monitor->m_round);
	free(data->monitor->time);
	free(data->monitor->write);
	free(data->monitor->dead);

	// Free memory for philosopher and monitor structures
	free(data->philo);
	free(data->monitor);
}
