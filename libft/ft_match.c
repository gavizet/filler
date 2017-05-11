/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 19:18:54 by gavizet           #+#    #+#             */
/*   Updated: 2016/11/11 20:00:10 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_match(char *s1, char *s2)
{
	if (*s2 != '*')
	{
		if (*s1 == '\0' && *s2 == '\0')
			return (1);
		else if (*s1 != *s2)
			return (0);
		else if (*s1 == *s2)
			return (ft_match(s1 + 1, s2 + 1));
	}
	else
	{
		if (*(s2 + 1) == '\0')
			return (1);
		else if (*(s2 + 1) == '*')
			return (ft_match(s1, s2 + 1));
		else if (*s1 == *(s2 + 1))
			return ((ft_match(s1 + 1, s2 + 2)) || (ft_match(s1 + 1, s2)));
		else if (*s1 == '\0')
			return (0);
		else if (*s1 != *(s2 + 1))
			return (ft_match(s1 + 1, s2));
	}
	return (0);
}
