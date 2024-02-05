/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:01:07 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/06 00:23:52 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/*
** Recursive function to mark visited cells in the map.
**
** Parameters:
** - map: The game map.
** - x: The x-coordinate of the current cell.
** - y: The y-coordinate of the current cell.
** - data: A pointer to the game data structure.
*/
void	ft_check(char **map, int x, int y, t_data *data)
{
	// Check if the current cell is not a wall ('1')
	if (map[y][x] != '1')
	{
		// Update flags based on cell content
		if (map[y][x] == 'E')
			data->e = 0;
		if (map[y][x] == 'P')
			data->p = 0;

		// Mark the current cell as visited ('1')
		map[y][x] = '1';

		// Check adjacent cells recursively
		ft_check(map, x - 1, y, data);
		ft_check(map, x + 1, y, data);
		ft_check(map, x, y - 1, data);
		ft_check(map, x, y + 1, data);

		return;
	}
	else
		return;
}


char	**ft_tabtabstrdup(char **tab)
{
	int		i;
	char	**dest;

	i = 0;
	dest = malloc(sizeof(char *) * (ft_tabtabstrlen(tab) + 1));
	while (tab[i])
	{
		dest[i] = ft_strdup(tab[i]);
		i++;
	}
	return (dest);
}

/*
** Pathfinder function to check if the map is solvable.
**
** Parameters:
** - data: A pointer to the game data structure.
**
** Returns:
** 0 if the map is solvable, 1 otherwise.
*/
int	ft_pathfinder(t_data *data)
{
	int		x;
	int		y;
	char	**map;

	x = data->player.posx;
	y = data->player.posy;
	data->e = 1;
	data->p = 1;
	data->r = 1;

	// Create a duplicate of the original map
	map = ft_tabtabstrdup(data->map);

	// Use recursive function to mark visited cells and update flags
	ft_check(map, x, y, data);

	// Free the duplicated map
	ft_freetabtab(map);

	// If 'data->r' is 0, the map is solvable
	if (data->r == 0)
		return (0);
	else
		return (1);
}

