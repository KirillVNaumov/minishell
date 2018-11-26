/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_apply_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:43:48 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/01 10:43:49 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node	*path_apply_flag(t_node *path, t_flags *flags)
{
	int		rev;

	rev = 0;
	if (flags->flag_r == 1)
		rev = 1;
	path = node_sort_by_name(path, rev);
	if (flags->flag_t == 1 && flags->flag_sc == 0)
		path = node_sort_by_time(path, rev);
	if (flags->flag_sc == 1)
		path = node_sort_by_size(path, rev);
	return (path);
}
