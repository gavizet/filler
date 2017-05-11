/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:38:21 by gavizet           #+#    #+#             */
/*   Updated: 2017/01/31 09:17:36 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		get_map(char *line, t_grid *data)
{
	int		i;
	char	**str_map;

	i = 0;
	str_map = ft_strsplit(line, ' ');
	data->s_map.y = ft_atoi(str_map[1]);
	data->s_map.x = ft_atoi(str_map[2]);
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	while (i < data->s_map.y)
	{
		get_next_line(0, &line);
		ft_memmove(data->map[i], line + 4, ft_strlen(line) - 3);
		ft_strdel(&line);
		i++;
	}
	ft_strdel(&line);
	free_tab2d(&str_map);
}

/*
** On recupere les dimensions de la piece ansi que toute la piece
*/

void		get_piece(char *line, t_grid *data)
{
	int		i;
	char	**str_piece;

	i = 0;
	str_piece = ft_strsplit(line, ' ');
	data->s_piece.y = ft_atoi(str_piece[1]);
	data->s_piece.x = ft_atoi(str_piece[2]);
	while (i < data->s_piece.y)
	{
		ft_strdel(&line);
		get_next_line(0, &line);
		ft_memmove(data->piece[i], line, ft_strlen(line) + 1);
		i++;
	}
	ft_strdel(&line);
	free_tab2d(&str_piece);
}
