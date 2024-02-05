/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:21:35 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/05 21:19:53 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// Main function to initialize and run the dining philosophers simulation
int main(int argc, char **argv)
{
	int		i;
	t_data	*data;

	i = 0;

	// Check for valid command-line arguments
	if (argc < 5 || argc > 6)
		return (0);

	// Initialize data structure for philosophers and monitor
	data = ft_init_data(argv, argc);

	// Create a thread for the monitor to check the status of philosophers
	pthread_create(&data->monitor->tid, NULL, &ft_monitor, data);

	// Create threads for each philosopher to run the routine
	while (i < ft_atoi(argv[1]))
	{
		pthread_create(&data->philo[i].tid, NULL, &routine, &data->philo[i]);
		i++;
	}

	i = 0;

	// Wait for all philosopher threads to finish
	while (i < ft_atoi(argv[1]))
	{
		pthread_join(data->philo[i].tid, NULL);
		i++;
	}

	// Wait for the monitor thread to finish
	pthread_join(data->monitor->tid, NULL);

	// Clean up resources and free memory
	ft_ciao(data);
	free(data);

	return (0);
}
