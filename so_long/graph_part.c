/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:24:31 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/06 00:20:11 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_crdn(int x, t_data *data)
{
	data->dimension = 128;
	return (x * data->dimension);
}

/*
** The function ft_dimension calculates the dimensions of the game window and the map.
**
** Parameters:
** - data: A pointer to the data structure containing information about the game state.
**
** Actions:
** - Set the dimension of each square in the game window to 128 pixels.
** - Calculate the height of the game window based on the number of rows in the map.
** - Calculate the width of the game window based on the number of columns in the map.
** - Store the map's height and width in data->map_height and data->map_width.
**
** Note: The dimensions are calculated by multiplying the number of rows or columns
** by the size of each square.
*/
void	ft_dimension(t_data *data)
{
	data->dimension = 128;
	data->win_height = ft_tabtabstrlen(data->map) * data->dimension;
	data->win_width = ft_strlen(data->map[0]) * data->dimension;
	data->map_height = ft_tabtabstrlen(data->map);
	data->map_width = ft_strlen(data->map[0]);
}


/*
** The function ft_init_img initializes the game sprites by loading XPM image files.
**
** Parameters:
** - data: A pointer to the data structure containing information about the game state.
**
** Actions:
** - Load the player sprite from the "loup.xpm" file.
** - Load the wall sprite from the "font.xpm" file.
** - Load the ground sprite from the "gazon.xpm" file.
** - Load the open exit sprite from the "exit_open.xpm" file.
** - Load the closed exit sprite from the "exit_close.xpm" file.
** - Load the cookie sprite from the "mouton.xpm" file.
**
** Note: Each sprite is assigned an mlx_img structure using mlx_xpm_file_to_image.
** The file paths and names may need to be adjusted based on the actual file locations.
*/
void	ft_init_img(t_data *data)
{
	int	img_height;
	int	img_width;

	data->player.sprite.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/loup.xpm", &img_height, &img_width);
	data->wall.sprite.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/font.xpm", &img_height, &img_width);
	data->font.sprite.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/gazon.xpm", &img_height, &img_width);
	data->exit_open.sprite.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/exit_open.xpm", &img_height, &img_width);
	data->exit_close.sprite.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/exit_close.xpm", &img_height, &img_width);
	data->cookie.sprite.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/mouton.xpm", &img_height, &img_width);
}

/*
** The function put_image displays the game images based on the current state of the map.
**
** Parameters:
** - data: A pointer to the data structure containing information about the game state.
**
** Actions:
** - Initialize game sprites using ft_init_img.
** - Loop through each cell of the map.
**   - For each cell, determine which sprite to display using ft_choose_img.
**   - Update the mlx_img structure of the sprite based on the current map cell.
** - Free the game sprites using free_image.
**
** Note: The exact implementation of ft_choose_img depends on how sprites are assigned to map cells.
*/
void	put_image(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	ft_init_img(data); // Initialize game sprites

	while (data->map[y])
	{
		while (data->map[y][x])
		{
			ft_choose_img(data->map[y][x], data, x, y); // Choose the appropriate sprite for the current map cell
			x++;
		}
		x = 0;
		y++;
	}

	free_image(data); // Free game sprites
}

/*
** The function free_image releases the memory used by game sprites.
**
** Parameters:
** - data: A pointer to the data structure containing information about the game state.
**
** Actions:
** - Destroy each game sprite's mlx_img using mlx_destroy_image.
**
** Note: This function assumes that the mlx_img pointers are initialized before calling free_image.
*/
void	free_image(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->player.sprite.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->cookie.sprite.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->wall.sprite.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->font.sprite.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->exit_open.sprite.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->exit_close.sprite.mlx_img);
}

