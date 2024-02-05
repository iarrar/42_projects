/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:04:43 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/05 21:14:41 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Initializes philosopher values from command line arguments
int ft_init_values(t_data *data, char **argv, int argc)
{
	int i;
	struct timeval tv;
	gettimeofday(&tv, NULL);

	// Iterate over philosophers
	while (i < ft_atoi(argv[1]))
	{
		// Set philosopher attributes
		data->philo[i].nphilo = ft_atoi(argv[1]);
		data->philo[i].round = (argc == 6) ? ft_atoi(argv[5]) : -1;
		data->philo[i].pzeros = tv.tv_sec;
		data->philo[i].pzerom = tv.tv_usec;
		data->philo[i].ttd = ft_atoi(argv[2]);
		data->philo[i].start = ft_timestamp(data->philo);
		data->philo[i].count = i;
		data->philo[i].tte = ft_atoi(argv[3]);
		data->philo[i].tts = ft_atoi(argv[4]);
		data->philo[i].die = 0;

		// Move to the next philosopher
		i++;
	}

	// Return 0 for successful initialization
	return (0);
}


// Initializes mutexes for philosophers and associated data
int ft_init_philo_mutex(t_data *data, char **argv)
{
	int i;

	i = 0;

	// Allocate memory for philosopher mutex arrays
	data->philo->mutex = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	data->philo->write = malloc(sizeof(pthread_mutex_t));
	data->philo->m_round = malloc(sizeof(pthread_mutex_t));
	data->philo->dead = malloc(sizeof(pthread_mutex_t));
	data->philo->time = malloc(sizeof(pthread_mutex_t));

	// Initialize global mutexes
	pthread_mutex_init(data->philo->write, NULL);
	pthread_mutex_init(data->philo->m_round, NULL);
	pthread_mutex_init(data->philo->dead, NULL);
	pthread_mutex_init(data->philo->time, NULL);

	// Iterate over philosophers
	while (i < data->philo->nphilo)
	{
		// Initialize mutex for each philosopher
		pthread_mutex_init(&data->philo->mutex[i], NULL);

		// Set shared mutexes for each philosopher
		data->philo[i].m_round = data->philo->m_round;
		data->philo[i].lf = &data->philo->mutex[i];
		data->philo[i].rf = &data->philo->mutex[(i + 1) % data->philo[i].nphilo];
		data->philo[i].write = data->philo->write;
		data->philo[i].dead = data->philo->dead;
		data->philo[i].time = data->philo->time;

		// Move to the next philosopher
		i++;
	}
	return (0);
}


// Initializes monitor mutexes by assigning values from philosopher data
int ft_monitor_init(t_data *data)
{
	// Set monitor mutexes to point to philosopher mutexes
	data->monitor->write = data->philo->write;
	data->monitor->dead = data->philo->dead;
	data->monitor->time = data->philo->time;
	data->monitor->m_round = data->philo->m_round;

	// Return 0 for successful initialization
	return (0);
}


// Initializes and allocates memory for the main data structure
t_data *ft_init_data(char **argv, int argc)
{
	// Allocate memory for data structure
	t_data *data = malloc(sizeof(t_data));
	data->philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	data->monitor = malloc(sizeof(t_monitor));

	// Initialize philosopher values, mutexes, and monitor mutexes
	ft_init_values(data, argv, argc);
	ft_init_philo_mutex(data, argv);
	ft_monitor_init(data);

	// Return the initialized data structure
	return (data);
}

