/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 10:53:50 by gavizet           #+#    #+#             */
/*   Updated: 2017/01/31 09:18:41 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"

# define P1	'O'
# define P2	'X'

typedef	struct	s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef	struct	s_grid
{
	int			best_dis;
	char		player;
	char		opp;
	char		map[100][100];
	char		piece[100][100];
	t_vector	min_pyt;
	t_vector	best_pos;
	t_vector	mpos;
	t_vector	ppos;
	t_vector	s_map;
	t_vector	s_piece;
	t_vector	save;
}				t_grid;

/*
** main.c
*/

int				main(void);

void			free_tab2d(char ***tab);

void			get_map(char *line, t_grid *data);
void			get_piece(char *line, t_grid *data);
void			update_map(char *line, t_grid *data);

void			solve(t_grid *data);

#endif
