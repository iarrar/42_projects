/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:21:35 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/04 15:58:08 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	main(int argc, char **argv)
{
	int		i;
	t_data	*data;

	i = 0;
	if (argc < 5 || argc > 6)
		return (0);
	data = ft_init_data(argv, argc);
	pthread_create(&data->monitor->tid, NULL, &ft_monitor, data);
	while (i < ft_atoi(argv[1]))
	{
		pthread_create(&data->philo[i].tid, NULL, &routine, &data->philo[i]);
		i++;
	}
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		pthread_join(data->philo[i].tid, NULL);
		i++;
	}
	pthread_join(data->monitor->tid, NULL);
	ft_ciao(data);
	free(data);
	return (0);
}
