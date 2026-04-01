/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 12:41:17 by atrombel          #+#    #+#             */
/*   Updated: 2026/03/29 12:41:19 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	ft_current_nbr_mvmt(t_struct *game)
{
	game->current_nbr_mvmt++;
	ft_printf("current nbr of movements = %d\n", game->current_nbr_mvmt);
}

void	tiles_type_check(t_struct *game)
{
	if (game->map[game->player_y_index][game->player_x_index] == 'C')
		game->collectible_count--;
	if (game->collectible_count == 0)
	{
		mlx_put_image_to_window(game->init, game->window, game->exit_open,
			game->exit_x_index * TILE, game->exit_y_index * TILE);
		game->map[game->exit_y_index][game->exit_x_index] = 'F';
	}
}

void	x_y_init(int key_code, int *x, int *y)
{
	if (key_code == 119)
	{
		*y = -1;
		*x = 0;
		return ;
	}
	if (key_code == 115)
	{
		*y = 1;
		*x = 0;
		return ;
	}
	if (key_code == 97)
	{
		*y = 0;
		*x = -1;
		return ;
	}
	if (key_code == 100)
	{
		*y = 0;
		*x = 1;
		return ;
	}
}

void	end(t_struct *game, int x, int y)
{
	if (x != 0 || y != 0)
		ft_current_nbr_mvmt(game);
	if (game->map[game->player_y_index][game->player_x_index] == 'F')
	{
		ft_printf("\nyou WIN\n");
		ft_close_all_2(game);
	}
}

void	ft_map_sprite_mvmt(int key_code, t_struct *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	x_y_init(key_code, &x, &y);
	if (game->map[game->player_y_index + y][game->player_x_index + x] == '1')
		return ;
	if (!(game->map[game->player_y_index][game->player_x_index] == 'E'))
		mlx_put_image_to_window(game->init, game->window, game->floor,
			game->player_x_index * TILE, game->player_y_index * TILE);
	if (game->map[game->player_y_index][game->player_x_index] == 'E')
		mlx_put_image_to_window(game->init, game->window, game->exit_closed,
			game->player_x_index * TILE, game->player_y_index * TILE);
	if (!(game->map[game->player_y_index][game->player_x_index] == 'E'))
		game->map[game->player_y_index][game->player_x_index] = '0';
	game->player_x_index += x;
	game->player_y_index += y;
	mlx_put_image_to_window(game->init, game->window, game->player,
		game->player_x_index * TILE, game->player_y_index * TILE);
	tiles_type_check(game);
	end(game, x, y);
	if (!(game->map[game->player_y_index][game->player_x_index] == 'E'))
		game->map[game->player_y_index][game->player_x_index] = 'P';
}
