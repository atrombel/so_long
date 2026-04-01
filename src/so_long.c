/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 09:06:40 by atrombel          #+#    #+#             */
/*   Updated: 2026/03/14 09:06:41 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	ft_window_creation(t_struct *game)//
{
	int	width;
	int	height;

	height = 0;
	width = 0;
	mlx_get_screen_size(game->init, &width, &height);
	if ((game->map_length_x * TILE) + MARGIN > width
		|| (game->map_length_y * TILE) + MARGIN > height)
	{
		ft_putstr_fd("Error\nMap is too large for the current display\n", 2);
		mlx_destroy_display(game->init);
		free(game->init);
		ft_close_map(game, game->map_length_y);
	}
	if (!game->window)
		game->window = mlx_new_window(game->init,
				game->map_length_x * TILE,
				game->map_length_y * TILE, "so_long");
	if (game->window == NULL)
	{
		ft_putstr_fd("Error\nFailed to initialize window\n", 2);
		mlx_destroy_display(game->init);
		free(game->init);
		ft_close_map(game, game->map_length_y);
	}
}

void	ft_init_sprites(t_struct *game)
{
	int	w;
	int	h;

	game->floor = mlx_xpm_file_to_image(game->init, "assets/floor.xpm", &w, &h);
	if (!game->floor || w != TILE || h != TILE)
		ft_sprite_error(game, "floor");
	game->wall = mlx_xpm_file_to_image(game->init, "assets/wall.xpm", &w, &h);
	if (!game->wall || w != TILE || h != TILE)
		ft_sprite_error(game, "wall");
	game->player = mlx_xpm_file_to_image(game->init,
			"assets/player.xpm", &w, &h);
	if (!game->player || w != TILE || h != TILE)
		ft_sprite_error(game, "player");
	game->item = mlx_xpm_file_to_image(game->init, "assets/item.xpm", &w, &h);
	if (!game->item || w != TILE || h != TILE)
		ft_sprite_error(game, "item");
	game->exit_closed = mlx_xpm_file_to_image(game->init,
			"assets/exit_closed.xpm", &w, &h);
	if (!game->exit_closed || w != TILE || h != TILE)
		ft_sprite_error(game, "exit");
	game->exit_open = mlx_xpm_file_to_image(game->init,
			"assets/exit_open.xpm", &w, &h);
	if (!game->exit_open || w != TILE || h != TILE)
		ft_sprite_error(game, "exit");
}

int	ft_key_action(int key_code, void *game)
{
	if (key_code == 65307)
		ft_close_all(game);
	ft_map_sprite_mvmt(key_code, game);
	return (0);
}

void	ft_loop(t_struct *game)
{
	mlx_key_hook(game->window, ft_key_action, game);
	mlx_hook(game->window, 17, 0, ft_close_all_2, game);
	mlx_hook(game->window, 12, (1L << 15), ft_render_map, game);
	mlx_loop(game->init);
}

int	main(int argc, char **argv)
{
	t_struct	game;

	ft_parser_boss(argc, argv, &game);
	game.init = mlx_init();
	if (!game.init)
	{
		ft_putstr_fd("Error\nFailed to initialize MiniLibX\n", 2);
		exit(1);
	}
	ft_window_creation(&game);
	ft_init_sprites(&game);
	ft_render_map(&game);
	ft_loop(&game);
	mlx_destroy_window(game.init, game.window);
	mlx_destroy_display(game.init);
	free(game.init);
}
