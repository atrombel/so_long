/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:51:23 by atrombel          #+#    #+#             */
/*   Updated: 2026/03/29 16:51:26 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	ft_render_x(t_struct *game, int x, int y)
{
	while (x < game->map_length_x)
	{
		mlx_put_image_to_window(game->init,
			game->window, game->floor, x * TILE_SIZE, y * TILE_SIZE);
		if (game->map[y][x] == '1')
			mlx_put_image_to_window(game->init,
				game->window, game->wall, x * TILE_SIZE, y * TILE_SIZE);
		else if (game->map[y][x] == 'P')
			mlx_put_image_to_window(game->init,
				game->window, game->player, x * TILE_SIZE, y * TILE_SIZE);
		else if (game->map[y][x] == 'C')
			mlx_put_image_to_window(game->init,
				game->window, game->item, x * TILE_SIZE, y * TILE_SIZE);
		else if (game->map[y][x] == 'E')
			mlx_put_image_to_window(game->init,
				game->window, game->exit_closed, x * TILE_SIZE, y * TILE_SIZE);
		else if (game->map[y][x] == 'F')
			mlx_put_image_to_window(game->init,
				game->window, game->exit_open, x * TILE_SIZE, y * TILE_SIZE);
		x++;
	}
}

int	ft_render_map(t_struct *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_length_y)
	{
		x = 0;
		ft_render_x(game, x, y);
		y++;
	}
	return (0);
}
