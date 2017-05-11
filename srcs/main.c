/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 13:22:13 by gavizet           #+#    #+#             */
/*   Updated: 2017/01/15 14:58:07 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** Affichage des coordonnees d'origine ou placer notre piece
*/

static void		put_piece(t_grid *data)
{
	ft_putnbr(data->best_pos.y);
	ft_putchar(' ');
	ft_putnbr(data->best_pos.x);
	ft_putchar('\n');
}

int				main(void)
{
	char		*line;
	t_grid		data;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "$$$ exec p", 10) == 0)
		{
			data.player = (line[10] == '1') ? P1 : P2;
			data.opp = (data.player == P1) ? P2 : P1;
			ft_strdel(&line);
		}
		else if (ft_strncmp(line, "Plateau", 7) == 0)
			get_map(line, &data);
		else if (ft_strncmp(line, "Piece", 5) == 0)
		{
			data.best_dis = 1024;
			get_piece(line, &data);
			solve(&data);
			put_piece(&data);
		}
	}
	return (0);
}
