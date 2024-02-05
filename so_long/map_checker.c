/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:12:10 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/06 00:22:09 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/*
** This function checks whether the map is a valid rectangle and not too small.
**
** Parameters:
** - map: The game map represented as a 2D array of characters.
**
** Returns:
** - 0 if the map is a valid rectangle and has an acceptable size.
** - 500 if the map is not a valid rectangle.
** - 501 if the map is too small.
**
** Note: The function iterates through the rows of the map, comparing the length of each row with the length of the first row (x).
** If any row has a different length, it returns an error. It also checks whether the total size of the map is larger than 15.
*/
int	check_rectangle(char **map)
{
	int	i;
	int	y;
	int	x;

	y = 0;
	i = 0;
	x = ft_strlen(map[0]);
	while (map[y])
	{
		i = ft_strlen(map[y]);
		if (i != x)
		{
			ft_putstr_fd("Error 500: Non-rectangular map\n", 2);
			return (500);
		}
		i = 0;
		y++;
	}
	if (x * y <= 15)
	{
		ft_putstr_fd("Error 501: Map is too small\n", 2);
		return (501);
	}
	return (0);
}

/*
** This function checks various aspects of the map for errors and prints corresponding error messages.
**
** Parameters:
** - map: The game map represented as a 2D array of characters.
**
** Returns:
** - 1 if any error is found.
** - 0 if the map passes all checks.
**
** Note: The function calls several helper functions to perform specific checks.
*/
int	ft_errmsg(char **map)
{
	if (check_rectangle(map) == 500)
		return (1);
	else if (check_rectangle(map) == 501)
		return (1);
	else if (check_walls(map) == 502)
		return (1);
	else if (check_elements(map) == 504)
		return (1);
	else if (count_elements(map) == 505)
		return (1);
	else if (ft_cookiz(map) == 0)
	{
		ft_putstr_fd("Error: Your game contains no collectibles\n", 2);
		return (1);
	}
	return (0);
}


int	ft_tabtabstrlen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

/*
** This function checks whether the game map is surrounded by walls (represented by '1' characters).
**
** Parameters:
** - map: The game map represented as a 2D array of characters.
**
** Returns:
** - 502 if the map is not surrounded by walls.
** - 0 if the map passes the check.
*/
int	check_walls(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[0][x] && map[ft_tabtabstrlen(map) - 1][x])
	{
		if ((map[0][x] != '1') || (map[ft_tabtabstrlen(map) - 1][x] != '1'))
		{
			ft_putstr_fd("Error 502: The map must be surrounded by walls\n", 2);
			return (502);
		}
		x++;
	}
	while (map[y])
	{
		if ((map[y][0] != '1') || (map[y][ft_strlen(map[0]) - 1] != '1'))
		{
			ft_putstr_fd("Error 502: The map must be surrounded by walls\n", 2);
			return (502);
		}
		y++;
	}
	return (0);
}

/*
** This function counts the occurrences of 'E' (exit) and 'P' (player) in the game map.
**
** Parameters:
** - map: The game map represented as a 2D array of characters.
**
** Returns:
** - 505 if there is an invalid number of exits or players.
** - 0 if the count is valid.
*/
int	count_elements(char **map)
{
	static int	i = 0;
	static int	j = 0;
	static int	e = 0;
	static int	p = 0;

	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'E')
				e++;
			else if (map[j][i] == 'P')
				p++;
			i++;
		}
		i = 0;
		j++;
	}
	if (e != 1 || p != 1)
	{
		ft_putstr_fd("Error 505: Invalid number of exits or players on the map\n", 2);
		return (505);
	}
	else
		return (0);
}
