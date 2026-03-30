/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:04:52 by atrombel          #+#    #+#             */
/*   Updated: 2026/03/23 17:17:07 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **ptr, int tmp_y)
{
	tmp_y--;
	if (ptr == NULL)
		return ;
	while (tmp_y >= 0)
		free (ptr[tmp_y--]);
	free (ptr);
	return ;
}

void	ft_close_parser(t_struct *game)
{
	close(game->map_fd);
	exit(1);
}

void	ft_close_map(t_struct *game, int tmp_y)
{
	ft_free(game->map, tmp_y);
	close(game->map_fd);
	exit(1);
}

void	ft_free_sprites(t_struct *game)
{
	if (game->floor)
		mlx_destroy_image(game->init, game->floor);
	if (game->wall)
		mlx_destroy_image(game->init, game->wall);
	if (game->player)
		mlx_destroy_image(game->init, game->player);
	if (game->item)
		mlx_destroy_image(game->init, game->item);
	if (game->exit_closed)
		mlx_destroy_image(game->init, game->exit_closed);
	if (game->exit_open)
		mlx_destroy_image(game->init, game->exit_open);
}

void	ft_close_all(t_struct *game)
{
		ft_free_sprites(game);
		if (game->window)
			mlx_destroy_window(game->init, game->window);
		mlx_destroy_display(game->init);
		free(game->init);
		ft_close_map(game, game->map_length_y);
}
///////////// attention APRES LE PARSEUR TOUTE LES FONCTIONS DEVRONT FREE X MINILIBX AUSSI

