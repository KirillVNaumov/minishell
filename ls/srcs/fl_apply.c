/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:43:13 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/01 12:58:28 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node	*fl_apply(t_node *node_list, t_flags *flags)
{
	int		rev;

	rev = 0;
	if (flags->flag_r == 1)
		rev = 1;
	node_list = node_sort_by_name(node_list, rev);
	if (flags->flag_t == 1 && flags->flag_sc == 0)
		node_list = node_sort_by_time(node_list, rev);
	if (flags->flag_sc == 1)
		node_list = node_sort_by_size(node_list, rev);
	return (node_list);
}
