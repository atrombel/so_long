/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:24:53 by atrombel          #+#    #+#             */
/*   Updated: 2026/03/23 17:24:54 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	map_struct_element_set_zero(t_struct *game)
{
	game->collectible_count = 0;
	game->exit_count = 0;
	game->player_count = 0;
	game->extra_parameter_count_error = 0;
	game->flood_e = 0;
	game->flood_c = 0;
	game->current_nbr_mvmt = 0;
	game->floor = NULL;
	game->wall = NULL;
	game->player = NULL;
	game->item = NULL;
	game->exit_closed = NULL;
	game->exit_open = NULL;
	game->window = NULL;
	game->init = NULL;
	game->exit_x_index = 0;
	game->exit_y_index = 0;
	game->init = NULL;
	game->addr = NULL;
}

void	fd_map_cursor_reset(t_struct *game, char **argv)
{
	close(game->map_fd);
	game->map_fd = open(argv[1], O_RDONLY);
	if (game->map_fd >= 0)
		return ;
	else
	{
		ft_putstr_fd("Error\nso_long cannot open map\n", 2);
		ft_close_parser(game);
	}
}

void	map_fil(t_struct *game)
{
	int	tmp_y;

	tmp_y = 0;
	while (tmp_y < (game->map_length_y))
	{
		game->map[tmp_y] = get_next_line(game->map_fd);
		if (game->map[tmp_y] == NULL)
			ft_close_map(game, tmp_y);
		tmp_y++;
	}
	game->map[tmp_y] = NULL;
}

void	map_init(t_struct *game, char **argv)
{
	fd_map_cursor_reset(game, argv);
	game->map = malloc(sizeof(char *) * (game->map_length_y + 1));
	if (game->map == NULL)
	{
		ft_putstr_fd("Error\nmemory allocation for map failed\n", 2);
		ft_close_parser(game);
	}
	map_fil(game);
	map_struct_element_set_zero(game);
}
