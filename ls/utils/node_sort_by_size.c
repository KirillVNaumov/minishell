/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_sort_by_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:09:46 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/04 15:10:25 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node	*node_sort_by_size(t_node *info, int is_asc)
{
	t_node *b;
	t_node *s;

	b = info;
	while (b)
	{
		s = info;
		while (s->next)
		{
			if (is_asc ? s->buf.st_size > s->next->buf.st_size :
					s->buf.st_size < s->next->buf.st_size)
				node_swap(s, s->next);
			s = s->next;
		}
		b = b->next;
	}
	return (info);
}
