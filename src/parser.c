/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 09:02:50 by atrombel          #+#    #+#             */
/*   Updated: 2026/03/15 09:02:52 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	argv_nbr_check(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error:\ninvalid nbr of args\n", 2);
		exit(1);
	}
	else
		return ;
}

void	is_there_an_empty_line(char *line)
{
	if (!line)
		return ;
	if	(line[0] == '\n' || line[0] == '\r')
	{
		ft_putstr_fd("Error:\nInvalid map, The map have an empty line\n", 2);
		free(line);
		exit(1);
	}
	return ;
}

void	ft_parser_boss(int argc, char **argv, t_struct *game)
{
	argv_nbr_check(argc);
	ft_access_map_ber_verif(argv[1], game);
	if (ft_reverse_strncmp_ber_ext_verif(argv[1], ".ber") != 0)
	{
		ft_putstr_fd("Error\nthe map format is not valid, it should end by the extension .ber\n", 2);
		exit(1);
	}
	ft_map_length(game);
	is_ber_rectangular_test(game);
	map_init(game, argv);
	is_map_surrounded_by_walls(game);
	is_map_element_ok_and_path_valid(game);
}
