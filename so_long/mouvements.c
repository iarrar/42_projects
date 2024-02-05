/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:48:23 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/06 00:22:45 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/*
** Move the player to the left on the game map if the destination is not a wall ('1').
**
** Parameters:
** - data: A pointer to the game data structure.
**
** Returns:
** - 1 if the player is successfully moved to the left.
** - 0 if the destination is a wall, and no movement occurs.
*/
int	move_left(t_data *data)
{
	if (data->map[data->player.posy][data->player.posx - 1] != '1')
	{
		// Update map after moving the player
		data->map[data->player.posy][data->player.posx] = '0';
		data->map[data->exit.posy][data->exit.posx] = 'E';
		data->map[data->player.posy][data->player.posx - 1] = 'P';
		
		// Update player's position
		data->player.posx--;
		
		// Increment move count
		data->count++;

		return (1); // Successful move
	}
	else
		return (0); // Wall encountered, no movement
}


int	move_right(t_data *data)
{
	if (data->map[data->player.posy][data->player.posx + 1] != '1')
	{
		data->map[data->player.posy][data->player.posx] = '0';
		data->map[data->exit.posy][data->exit.posx] = 'E';
		data->map[data->player.posy][data->player.posx + 1] = 'P';
		data->player.posx++;
		data->count ++;
		return (1);
	}
	else
		return (0);
}

int	move_up(t_data *data)
{
	if (data->map[data->player.posy - 1][data->player.posx] != '1')
	{
		data->map[data->player.posy][data->player.posx] = '0';
		data->map[data->exit.posy][data->exit.posx] = 'E';
		data->map[data->player.posy - 1][data->player.posx] = 'P';
		data->player.posy--;
		data->count ++;
		return (1);
	}
	else
		return (0);
}

int	move_down(t_data *data)
{
	if (data->map[data->player.posy + 1][data->player.posx] != '1')
	{
		data->map[data->player.posy][data->player.posx] = '0';
		data->map[data->exit.posy][data->exit.posx] = 'E';
		data->map[data->player.posy + 1][data->player.posx] = 'P';
		data->player.posy++;
		data->count ++;
		return (1);
	}
	else
		return (0);
}
