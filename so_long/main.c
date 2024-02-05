/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:45:32 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/06 00:18:39 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/*
** The main function serves as the entry point for the program.
**
** Parameters:
** - argc: Number of command-line arguments.
** - argv: Array of command-line arguments.
**
** Actions:
** 1. Check if the correct number of command-line arguments is provided, and if the file extension is valid.
** 2. Read the map from the file into the data structure.
** 3. Initialize the game, checking for errors and displaying appropriate messages.
** 4. Check for errors in the map and exit if any are found.
** 5. Perform pathfinding to ensure that all collectible items are reachable.
** 6. Display the initial state of the game.
** 7. Set up event hooks for handling key presses and window close events.
** 8. Enter the main event loop using mlx_loop.
**
** Note: This main function seems well-organized and follows a modular structure.
*/
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || check_extension(argv[1]) == 0)
		return (0);
	if (get_map(argv[1], &data) == 0)
		return (0);
	if (ft_init_all(&data) == 1)
		return (0);
	if (ft_errmsg(data.map) != 0)
	{
		ft_ciao(&data);
		return (0);
	}
	if (ft_pathfinder(&data))
	{
		ft_putstr_fd("Error: Not all items are collectible\n", 2);
		ft_ciao(&data);
		return (0);
	}
	put_image(&data);
	mlx_key_hook(data.win_ptr, &handle_input, &data);
	mlx_hook(data.win_ptr, 17, KeyPressMask, &ft_ciao, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

