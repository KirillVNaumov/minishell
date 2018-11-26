/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_blocks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 12:55:48 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/10 12:56:06 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_blocks(t_node *path, t_flags *flags)
{
	t_node		*block_list;
	t_node		*begin_list;

	begin_list = path;
	block_list = NULL;
	while (path)
	{
		if ((path->buf.st_mode & S_IFBLK) == S_IFBLK)
			block_list = node_add(block_list, path->name, path->buf);
		path = path->next;
	}
	ft_list_clean(&path);
	path = begin_list;
	display_entity(path, block_list, flags);
	ft_list_clean(&block_list);
}
