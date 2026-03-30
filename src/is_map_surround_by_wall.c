/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_surround_by_wall.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:58:09 by atrombel          #+#    #+#             */
/*   Updated: 2026/03/24 10:58:11 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	first_line_test(t_struct *game)
{
	int	x;

	x = 0;
	ft_printf("\nmap_length_x = %d\n", game->map_length_x);
	ft_printf("map_length_y = %d\n", game->map_length_y);
	while(x < game->map_length_x)
	{
		if (game->map[0][x] != '1')
		{
			ft_putstr_fd("Error:\nmap must be surrounded by walls (first line invalid)\n", 2);
			ft_close_map(game, game->map_length_y);
		}
		x++;
	}
}

void	final_line_test(t_struct *game)
{
	int	x;

	x = 0;

	while(x < game->map_length_x)
	{
		if (game->map[game->map_length_y - 1][x] != '1')
		{
			ft_putstr_fd("Error:\nmap must be surrounded by walls", 2);
			ft_close_map(game, game->map_length_y);
		}
		x++;
	}
	if (game->map[game->map_length_y - 1][x] == '\n' || game->map[game->map_length_y - 1][x] == '\r')
	{
		ft_putstr_fd("Error:\nInvalid map. The map have an empty line at the end.\n", 2);
		ft_close_map(game, game->map_length_y);
	}
}

void	midle_line_test(t_struct *game)
{
	int	y;

	y = 1;
	while(y < game->map_length_y - 1)
	{
		if (game->map[y][0] != '1' || game->map[y][game->map_length_x - 1 ] != '1')
		{
			ft_putstr_fd("Error:\nmap must be surrounded by walls (last line invalid)\n", 2);
			ft_close_map(game, game->map_length_y);
		}
		y++;
	}
}

void	is_map_surrounded_by_walls(t_struct *game)
{
	first_line_test(game);
	midle_line_test(game);
	final_line_test(game);
}
