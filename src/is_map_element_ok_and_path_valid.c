/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_element_ok_and_path_valid.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 10:24:34 by atrombel          #+#    #+#             */
/*   Updated: 2026/03/27 10:24:38 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	element_count_x(t_struct *game, int y)
{
	int	x;

	x = 0;
	while(x < game->map_length_x)
	{
		if (game->map[y][x] == 'C')
			game->collectible_count++;
		else if (game->map[y][x]  == 'E')
		{
			game->exit_count++;
			game->exit_y_index = y;
			game->exit_x_index = x;
		}
		else if (game->map[y][x]  == 'P')
		{
			game->player_count++;
			game->player_y_index = y;
			game->player_x_index = x;
		}
		else if (game->map[y][x] == '1' || game->map[y][x] == '0')
			;
		else
			game->extra_parameter_count_error = 1;
		x++;
	}
}

void	element_count(t_struct *game)
{
	int	y;

	y = 0;
	while(y < game->map_length_y)
	{
		element_count_x(game, y);
		y++;
	}
}

void	map_element_nbr_check(t_struct *game)
{
	if (game->collectible_count < 1)
	{
		ft_putstr_fd("Error\nMap requires at least one collectible (C)\n", 2);
		ft_close_map(game, game->map_length_y);
	}
	if (game->exit_count != 1)
	{
		ft_putstr_fd("Error\nMap requires exactly one exit (E)\n", 2);
		ft_close_map(game, game->map_length_y);
	}
	if (game->player_count != 1)
	{
		ft_putstr_fd("Error\nMap requires exactly one Player (P)\n", 2);
		ft_close_map(game, game->map_length_y);
	}
	if (game->extra_parameter_count_error == 1)
	{
		ft_putstr_fd("Error\nInvalid character: only 0, 1, C, E, P allowed\n", 2);
		ft_close_map(game, game->map_length_y);
	}
}

void	map_element_count_check(t_struct *game)
{
	element_count(game);
	map_element_nbr_check(game);
}

void	is_map_element_ok_and_path_valid(t_struct *game)
{
	map_element_count_check(game);
	map_path_check(game);
}
