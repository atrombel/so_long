/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 09:06:36 by atrombel          #+#    #+#             */
/*   Updated: 2026/03/14 09:06:37 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "unistd.h"
# include <fcntl.h>
# include <stdio.h>
# define TILE 64
# define MARGIN 100

typedef struct so_long
{
	void	*init;
	void	*window;
	char	*addr;
	int		map_fd; // to close !!!!!!
	int		map_length_y;
	int		map_length_x;
	char	**map;// a free
	int		collectible_count;
	int		exit_count;
	int		player_count;
	int		player_x_index;
	int		player_y_index;
	int		extra_parameter_count_error;
	int		flood_collectible_count;
	int		flood_exit_count;
	int		flood_e;
	int		flood_c;
	void	*floor;
	void	*wall;
	void	*player;
	void	*item;
	void	*exit_closed;
	void	*exit_open;
	int		current_nbr_mvmt;
	int		exit_x_index;
	int		exit_y_index;
}	t_struct;

void	ft_parser_boss(int argc, char **argv, t_struct *game);
int		ft_reverse_strncmp_ber_ext_verif(char *s1, char *s2);
void	ft_access_map_ber_verif(char *map, t_struct *game);
void	is_map_element_ok_and_path_valid(t_struct *game);
void	map_init(t_struct *game, char **argv);
void	ft_close_parser(t_struct *game);
void	ft_close_map(t_struct *game, int tmp_y);
void	ft_free(char **ptr, int tmp_y);
void	ft_map_length(t_struct	*game);
void	is_ber_rectangular_test(t_struct *game);
void	is_map_surrounded_by_walls(t_struct *game);
void	is_there_an_empty_line(char *line);
void	is_map_element_ok_and_path_valid(t_struct *game);
void	map_path_check(t_struct *game);
void	ft_close_all(t_struct *game);
void	ft_sprite_error(t_struct *game, char *sprite_name);
int		ft_render_map(t_struct *game);
void	ft_map_sprite_mvmt(int key_code, t_struct *game);
void	x_y_init(int key_code, int *x, int *y);
int		ft_close_all_2(t_struct *game);
void	ft_free_sprites(t_struct *game);
void	ft_gnl_flush(int fd);

#endif
