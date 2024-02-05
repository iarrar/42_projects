/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creamap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:06:24 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/06 00:16:09 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

#define BUFFER_SIZE 5000

int	ft_searchar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

t_player	ft_searstruct(char **map, char c)
{
	t_player	cacahuete;

	cacahuete.posx = -1;
	cacahuete.posy = 0;
	while (cacahuete.posx == -1)
	{
		cacahuete.posx = ft_searchar(map[cacahuete.posy], c);
		cacahuete.posy++;
	}
	cacahuete.posy--;
	return (cacahuete);
}

void	ft_freetabtab(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/*
** The function handle_input processes the input keys and performs corresponding actions.
**
** Parameters:
** - keysym: The key symbol representing the pressed key.
** - data: A pointer to the data structure containing information about the game state.
**
** Actions:
** - If the 'a' key is pressed, move the player left.
** - If the 's' key is pressed, move the player down.
** - If the 'w' key is pressed, move the player up.
** - If the 'd' key is pressed, move the player right.
** - Update the display with the current game state.
** - Print the total number of moves.
** - If the game is won or the 'Escape' key is pressed, display the corresponding message
**   and exit the game.
**
** Returns:
** Always returns 0.
*/
int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_a)
		move_left(data);
	else if (keysym == XK_s)
		move_down(data);
	else if (keysym == XK_w)
		move_up(data);
	else if (keysym == XK_d)
		move_right(data);
	put_image(data);
	ft_printf("\033[H\033[J");
	ft_printf("total moves = %d\n", data->count);
	if (ft_endgame(data) == 1 || keysym == XK_Escape)
	{
		if (ft_endgame(data) == 1)
		{
			ft_printf("!!! YOU WIN !!!\nCongatulations !\n");
			ft_printf("map cleared in %d moves\n", data->count);
		}
		ft_ciao(data);
	}
	return (0);
}

/*
** The function get_map reads the content of the specified file and populates
** the data structure with the map information.
**
** Parameters:
** - str: The name of the file containing the map.
** - data: A pointer to the data structure containing information about the game state.
**
** Actions:
** - Allocate memory for a buffer and read the content of the file into the buffer.
** - If the file doesn't exist or there is an error reading it, print an error message
**   and return 0.
** - If the file is empty, free the allocated memory and return 0.
** - Duplicate the content of the buffer into data->str.
** - Split the content of data->str into lines using '\n' as a delimiter and store
**   the result in data->map.
** - Free the allocated memory for the buffer.
**
** Returns:
** The total number of characters read from the file.
*/
int	get_map(char *str, t_data *data)
{
	int		ret;
	int		total_len;
	char	*buf;

	buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	ret = read(open(str, O_RDONLY), buf, BUFFER_SIZE);
	total_len = ret;
	if (ret == -1)
	{
		ft_putstr_fd("Invalid map name\n", 2);
		free(buf);
		return (0);
	}
	if (ret == 0)
	{
		free(buf);
		return (0);
	}
	data->str = ft_strdup(buf);
	free(buf);
	if (data->str)
		data->map = ft_split(data->str, '\n');
	else
		free(data->str);
	return (total_len);
}

