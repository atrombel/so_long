/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:22:01 by atrombel          #+#    #+#             */
/*   Updated: 2026/03/27 15:22:02 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood(t_struct *game, int x, int y, char **map_tmp)
{
	if (x < 0 || y < 0 || x >= game->map_length_x || y >= game->map_length_y)
		return ;
	if (map_tmp[y][x] == 'x' || map_tmp[y][x] == '1')
		return ;
	if (map_tmp[y][x] == 'C')
		game->flood_c++;
	if (map_tmp[y][x] == 'E')
		game->flood_e++;
	map_tmp[y][x] = 'x';
	flood(game, x + 1, y, map_tmp);
	flood(game, x - 1, y, map_tmp);
	flood(game, x, y + 1, map_tmp);
	flood(game, x, y - 1, map_tmp);
}

void	flood_check(t_struct *game, char **map_tmp)
{
	int	x;
	int	y;

	x = game->player_x_index;
	y = game->player_y_index;
	flood(game, x, y, map_tmp);
}

char	**map_tmp_copy(char	**map_tmp, t_struct *game)
{
	int	y;

	y = 0;
	while (y < game->map_length_y)
	{
		map_tmp[y] = ft_strdup(game->map[y]);
		if (!map_tmp[y])
		{
			perror("Error:");
			ft_free(map_tmp, y);
			ft_close_map(game, game->map_length_y);
		}
		y++;
	}
	map_tmp[y] = NULL;
	return (map_tmp);
}

void	flood_validity_nbr_element_check(t_struct *game)
{
	if (game->flood_c != game->collectible_count)
	{
		ft_putstr_fd("Error\nPath: some collectibles are unreachable\n", 2);
		ft_close_map(game, game->map_length_y);
	}
	if (game->flood_e != game->exit_count)
	{
		ft_putstr_fd("Error\nInvalid path, Exit should be reachable\n", 2);
		ft_close_map(game, game->map_length_y);
	}
}

void	map_path_check(t_struct *game)
{
	char	**map_tmp;

	map_tmp = malloc(sizeof(char *) * (game->map_length_y + 1));
	if (!map_tmp)
	{
		perror("Error:");
		ft_close_map(game, game->map_length_y);
	}
	map_tmp = map_tmp_copy(map_tmp, game);
	flood_check(game, map_tmp);
	ft_free(map_tmp, game->map_length_y);
	flood_validity_nbr_element_check(game);
}
