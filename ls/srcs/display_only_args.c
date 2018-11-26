/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_only_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 19:11:15 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/10 19:11:48 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_only_args(t_node *path, t_flags *flags)
{
	t_node		*argument_list;
	t_node		*begin_list;
	char		*str;

	begin_list = path;
	argument_list = NULL;
	while (path)
	{
		str = delete_slash(path->name);
		if (!stat(path->name, &path->buf))
			argument_list = node_add(argument_list, path->name, path->buf);
		free(str);
		path = path->next;
	}
	ft_list_clean(&path);
	path = begin_list;
	display_entity(path, argument_list, flags);
	ft_list_clean(&argument_list);
}
