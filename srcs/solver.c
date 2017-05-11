/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:19:10 by gavizet           #+#    #+#             */
/*   Updated: 2017/01/15 14:58:59 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** On parcourt notre piece, et on compte le nombre d'asterix qu'on y trouve
*/

static int		browse_piece(t_grid *data, t_vector *place, int count)
{
	int			index;

	index = 0;
	data->ppos.y = -1;
	while (++data->ppos.y < data->s_piece.y)
	{
		data->ppos.x = -1;
		while (++data->ppos.x < data->s_piece.x)
		{
			if (data->piece[data->ppos.y][data->ppos.x] == '*')
			{
				index++;
				if (index == count)
				{
					place->y = data->ppos.y;
					place->x = data->ppos.x;
					return (1);
				}
			}
		}
	}
	return (0);
}

/*
** Lancement des differentes checks de placement de piece
*/

static int		place_piece(t_grid *data, int y_ret, int x_ret)
{
	t_vector	count;
	t_vector	place;

	count.x = 0;
	count.y = 0;
	while (browse_piece(data, &place, ++count.y))
	{
		if (y_ret + place.y >= 0 && x_ret + place.x >= 0 &&
			y_ret + place.y < data->s_map.y && x_ret + place.x < data->s_map.x)
		{
			if (data->map[y_ret + place.y][x_ret + place.x] != '.')
				count.x++;
		}
		else
		{
			data->save.y = 0;
			data->save.x = 0;
			return (0);
		}
		if (count.x > 1)
			return (0);
	}
	data->save.y = y_ret;
	data->save.x = x_ret;
	return (1);
}

/*
** Lancement des fonctions permettant que l'on peut poser notre forme
*/

static int		check_placement(t_grid *data)
{
	int			count;
	t_vector	place;

	count = 0;
	place.y = 0;
	place.x = 0;
	browse_piece(data, &place, ++count);
	while (!(place_piece(data, data->save.y - place.y, data->save.x - place.x)))
		if (!(browse_piece(data, &place, ++count)))
			return (0);
	return (1);
}

/*
** Recuperation de la diagonale la plus petite afin d'obtenir la position
** la plus proche de l'adversaire ou placer notre piece
*/

static void		smaller_diff(t_grid *data)
{
	t_vector	pos;

	pos.x = -1;
	while (++pos.x < data->s_map.x)
	{
		pos.y = -1;
		while (++pos.y < data->s_map.y)
		{
			if (data->map[pos.y][pos.x] == data->opp ||
				data->map[pos.y][pos.x] == data->opp + 32)
			{
				if (ft_sqrt((pos.x - data->mpos.x) * (pos.x - data->mpos.x) +
					(pos.y - data->mpos.y) * (pos.y - data->mpos.y)) <
					data->best_dis)
				{
					data->best_dis = ft_sqrt((pos.x - data->mpos.x) *
					(pos.x - data->mpos.x) + (pos.y - data->mpos.y) *
					(pos.y - data->mpos.y));
					data->best_pos.y = data->save.y;
					data->best_pos.x = data->save.x;
				}
			}
		}
	}
}

/*
** Parcours de la map jusqu'a trouver notre joueur.
** Une fois trouve, on lancer le solver
*/

void			solve(t_grid *data)
{
	int			can_place;

	can_place = 0;
	data->mpos.y = -1;
	while (++data->mpos.y < data->s_map.y)
	{
		data->mpos.x = -1;
		while (++data->mpos.x < data->s_map.x)
		{
			if (data->map[data->mpos.y][data->mpos.x] == data->player ||
				data->map[data->mpos.y][data->mpos.x] == data->player + 32)
			{
				data->save.y = data->mpos.y;
				data->save.x = data->mpos.x;
				if (check_placement(data) && ++can_place)
					smaller_diff(data);
			}
		}
	}
	if (can_place == 0)
	{
		data->best_pos.y = 0;
		data->best_pos.x = 0;
	}
}
