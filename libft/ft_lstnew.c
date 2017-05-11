/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:13:52 by gavizet           #+#    #+#             */
/*   Updated: 2016/11/19 09:56:52 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*maillon;

	if (!(maillon = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		content = NULL;
		content_size = 0;
	}
	else
	{
		if (!(maillon->content = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(maillon->content, content, content_size);
		maillon->content_size = content_size;
		maillon->next = NULL;
	}
	return (maillon);
}
