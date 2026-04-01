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
	ft_printf("current nbr of movements = \033[0;32m%d\033[0m\n",  game->current_nbr_mvmt);
}

void	tiles_type_check(t_struct *game)
{
	if (game->map[game->player_y_index][game->player_x_index] == 'C')
		game->collectible_count--;
	ft_printf(" collectible_count = \033[0;32m%d\033[0m\n",  game->collectible_count);// A ENLEVER
	if (game->collectible_count == 0)
	{
		mlx_put_image_to_window(game->init, game->window, game->exit_open, game->exit_x_index * TILE_SIZE, game->exit_y_index * TILE_SIZE);
		game->map[game->exit_y_index][game->exit_x_index] = 'F';
	}
}

void	x_y_init(int key_code, int *x, int *y)
{
	if (key_code == 119)//w
	{
		*y = -1;
		*x = 0;
		return ;
	}
	if (key_code == 115)//s2
	{
		*y = 1;
		*x = 0;
		return ;
	}
	if (key_code == 97 )//a
	{
		*y = 0;
		*x = -1;
		return ;
	}
	if (key_code == 100)//d
	{
		*y = 0;
		*x = 1;
		return ;
	}
}

void	end(t_struct *game)
{
	ft_printf("\nyou \033[0;32mWIN\033[0m\n");
	ft_close_all_2(game);
}

void	ft_map_sprite_mvmt(int key_code,t_struct *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	x_y_init(key_code, &x, &y);
	if (game->map[game->player_y_index + y][game->player_x_index + x] == '1')
		return ;
	if (!(game->map[game->player_y_index][game->player_x_index] == 'E'))
		mlx_put_image_to_window(game->init, game->window, game->floor, game->player_x_index * TILE_SIZE, game->player_y_index * TILE_SIZE);
	if	(game->map[game->player_y_index][game->player_x_index] == 'E')
		mlx_put_image_to_window(game->init, game->window, game->exit_closed, game->player_x_index * TILE_SIZE, game->player_y_index * TILE_SIZE);
	if (!(game->map[game->player_y_index][game->player_x_index] == 'E'))
		game->map[game->player_y_index][game->player_x_index] = '0';
	game->player_x_index += x;
	game->player_y_index += y;
	mlx_put_image_to_window(game->init, game->window, game->player, game->player_x_index * TILE_SIZE, game->player_y_index * TILE_SIZE);
	tiles_type_check(game);
	if (game->map[game->player_y_index][game->player_x_index] == 'F')
		end(game);
	if(x != 0 || y != 0)
		ft_current_nbr_mvmt(game);
	if (!(game->map[game->player_y_index][game->player_x_index] == 'E'))
		game->map[game->player_y_index][game->player_x_index] = 'P';
}

