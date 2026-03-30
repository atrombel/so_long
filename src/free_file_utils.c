/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 12:43:05 by atrombel          #+#    #+#             */
/*   Updated: 2026/03/29 12:43:09 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	ft_sprite_error(t_struct *game, char *sprite_name)
{
	ft_putstr_fd("Error\nInvalid sprite: ", 2);
	ft_putstr_fd(sprite_name, 2);
	ft_putstr_fd(" (Missing or wrong size)\n", 2);
	ft_close_all(game);
}

int	ft_close_all_2(t_struct *game)
{
	ft_free_sprites(game);
	if (game->window)
		mlx_destroy_window(game->init, game->window);
	mlx_destroy_display(game->init);
	free(game->init);
	ft_close_map(game, game->map_length_y);
	return (0);
}
