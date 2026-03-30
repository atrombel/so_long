/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 09:13:36 by atrombel          #+#    #+#             */
/*   Updated: 2026/03/15 09:13:39 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen_no_endline(const	char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{

		if (s[i] == '\n' || s[i] == '\r' )
			break ;
		i++;
	}
	return (i);
}

void	ft_access_map_ber_verif(char *map, t_struct *game)
{
	game->map_fd = open(map, O_RDONLY);
	if (game->map_fd >= 0)
		return ;
	else
	{
		ft_putstr_fd("Error:\nCannot open map\n", 2);
		exit (1);
	}
}

void	ft_map_length(t_struct	*game)
{
	char	*line1;

	line1 = get_next_line(game->map_fd);
	game->map_length_x = 0;
	if (line1 == NULL)
	{
		ft_putstr_fd("Error\nEmpty map\n", 2);
		close(game->map_fd);
		exit (1);
	}
 	game->map_length_x = ft_strlen_no_endline(line1);
											ft_putstr_fd("\033[34mgame->map_length_x  ", 1);
											ft_putnbr_fd(game->map_length_x, 1);
											ft_putstr_fd("\033[0m\n", 1);
	free(line1);
	if (game->map_length_x == 0 || game->map_length_x < 3)
	{
		ft_putstr_fd("Error\ninvalid map (map too small and need a player, colletible and an exit)\n", 2);
		close(game->map_fd);
		exit(1);
	}
	game->map_length_y = 1;
}

void	is_ber_rectangular_test(t_struct *game)
{
	int		tmp_length;
	char	*line;

	tmp_length = 1;
	while (tmp_length != 0)
	{
		line = get_next_line(game->map_fd);
		if (line == NULL)
			break ;
		tmp_length = ft_strlen_no_endline(line);
		if (tmp_length != game->map_length_x)
		{
			close(game->map_fd);
			is_there_an_empty_line(line);
			ft_putstr_fd("Error:\nInvalid map, the map is not rectangular\n", 2);
			free(line);
			exit(1);
		}
		free(line);
		game->map_length_y++;
	}
										printf("\033[34mgame->map_length_y  %d\033[0m\n", game->map_length_y);
}

int	ft_reverse_strncmp_ber_ext_verif(char *s1, char *s2)
{
	int	i;
	int	j;
	int	n;

	n = 4;
	j = 3;
	i = ft_strlen(s1) - 1;
	while (n > 0 && i >= 0 && j >= 0)
	{
		if (s1[i] != s2[j])
			return ((unsigned char)s1[i] - (unsigned char)s2[j]);
		n--;
		i--;
		j--;
	}
	if (n == 0)
		return (0);
	return (1);
}
