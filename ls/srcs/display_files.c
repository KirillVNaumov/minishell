/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:43:07 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/01 13:34:26 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	check_for_links(t_node *path, DIR *dir, t_flags *flags)
{
	if ((path->buf.st_mode & S_IFLNK) == S_IFLNK && !dir && flags->flag_l == 0)
		ft_printf("%s\n", path->name);
}

void	display_files(t_node *path, t_flags *flags)
{
	t_node		*file_list;
	t_node		*begin_list;
	DIR			*dir;

	file_list = NULL;
	begin_list = path;
	flags->entity_fill = 1;
	while (path)
	{
		dir = opendir(path->name);
		if ((path->buf.st_mode & S_IFLNK) != S_IFLNK || ((path->buf.st_mode & \
		S_IFLNK) == S_IFLNK && path->name[0] == '/' && flags->flag_l == 0) || \
	((path->buf.st_mode & S_IFLNK) == S_IFLNK && flags->flag_l == 0 && !dir))
			if ((path->buf.st_mode & S_IFDIR) != S_IFDIR && !stat(path->name, \
						&path->buf))
				file_list = node_add(file_list, path->name, path->buf);
		check_for_links(path, dir, flags);
		if (dir)
			closedir(dir);
		path = path->next;
	}
	ft_list_clean(&path);
	path = begin_list;
	display_entity(path, file_list, flags);
	ft_list_clean(&file_list);
}
