/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_sort_by_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:42:02 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/01 10:42:03 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node	*node_sort_by_name(t_node *root, int is_asc)
{
	t_node *b;
	t_node *s;

	b = root;
	while (b)
	{
		s = root;
		while (s->next)
		{
			if (is_asc ? ft_strcmp(s->name, s->next->name) < 0 :
					ft_strcmp(s->name, s->next->name) > 0)
				node_swap(s, s->next);
			s = s->next;
		}
		b = b->next;
	}
	free(b);
	return (root);
}
