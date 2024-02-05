/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cookiz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:57:16 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/06 00:14:22 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/*
** The function ft_cookiz counts the number of 'C' items in the map.
** It iterates through each row and column of the map and increments the count
** whenever it encounters a 'C'.
**
** Parameters:
** - map: A 2D array representing the game map.
**
** Returns:
** The total count of 'C' characters in the map.
*/
int	ft_cookiz(char **map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		j = 0;
		i++;
	}
	return (c);
}

/*
** The function ft_endgame checks whether the game is in a winning state.
** It returns 1 if the player's position coincides with the exit position and
** there are no more 'C' (cookies) left on the map, indicating that the player
** has collected all cookies and reached the exit.
**
** Parameters:
** - data: A pointer to the game data structure containing player, exit, and map information.
**
** Returns:
** 1 if the game is won, 0 otherwise.
*/
int	ft_endgame(t_data *data)
{
	if ((data->player.posy == data->exit.posy) &&
		(data->player.posx == data->exit.posx) &&
		(ft_cookiz(data->map) == 0))
		return (1);
	else
		return (0);
}

/*
** The function check_extension checks whether the file extension of the input string
** is valid for the "so_long" project. It compares the last four characters of the string
** with ".ber" to ensure it has the correct extension.
**
** Parameters:
** - str: A string representing the file name or path.
**
** Returns:
** 1 if the extension is valid, 0 otherwise.
*/
int	check_extension(char *str)
{
	if (ft_strlen(str) < 4)
	{
		ft_putstr_fd("File extension non valide\n", 2);
		return (0);
	}
	if (ft_strncmp(".ber", &str[ft_strlen(str) - 4], 4))
	{
		ft_putstr_fd("File extension non valide\n", 2);
		return (0);
	}
	else
		return (1);
}



