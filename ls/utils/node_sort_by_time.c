/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_sort_by_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:42:10 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/01 10:42:11 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node	*node_sort_by_time(t_node *info, int is_asc)
{
	t_node *b;
	t_node *s;

	b = info;
	while (b)
	{
		s = info;
		while (s->next)
		{
			if (is_asc ? s->buf.st_mtime > s->next->buf.st_mtime :
					s->buf.st_mtime < s->next->buf.st_mtime)
				node_swap(s, s->next);
			if (s->buf.st_mtime == s->next->buf.st_mtime)
				if (is_asc ? s->buf.st_mtimespec.tv_nsec >
						s->next->buf.st_mtimespec.tv_nsec :
						s->buf.st_mtimespec.tv_nsec <
						s->next->buf.st_mtimespec.tv_nsec)
					node_swap(s, s->next);
			s = s->next;
		}
		b = b->next;
	}
	return (info);
}
