/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:42:54 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/02 11:18:09 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_node			*reading_dir(t_node *path, t_flags *flags, \
		DIR *dir, t_node *dir_list)
{
	struct stat			buf;
	char				*linkname;
	char				*tmp;
	struct dirent		*sd;

	while ((sd = readdir(dir)))
	{
		linkname = NULL;
		lstat(path->name, &buf);
		if ((buf.st_mode & S_IFLNK) != S_IFLNK || ((buf.st_mode & S_IFLNK) ==\
					S_IFLNK && flags->flag_l == 0))
		{
			tmp = ft_strjoin(path->name, "/");
			tmp = ft_update(tmp, ft_strjoin(tmp, sd->d_name));
			lstat(tmp, &buf);
			if (flags->flag_a == 1 || sd->d_name[0] != '.')
				dir_list = node_add(dir_list, sd->d_name, buf);
			free(tmp);
		}
	}
	return (dir_list);
}

t_node					*only_dirs_fill(t_node *path, t_node *list)
{
	char				*tmp;
	t_node				*dir_list;

	dir_list = NULL;
	while (list)
	{
		if ((list->buf.st_mode & S_IFDIR) == S_IFDIR)
		{
			tmp = ft_strjoin(path->name, "/");
			tmp = ft_update(tmp, ft_strjoin(tmp, list->name));
			if (ft_strcmp(list->name, ".") && ft_strcmp(list->name, ".."))
				dir_list = node_add(dir_list, tmp, list->buf);
			free(tmp);
		}
		list = list->next;
	}
	return (dir_list);
}

void					count_dirs(t_node *path, t_flags *flags, \
		DIR *dir, int count_rec)
{
	t_node				*dir_entity_list;
	t_node				*only_dirs;

	dir_entity_list = NULL;
	dir_entity_list = reading_dir(path, flags, dir, dir_entity_list);
	only_dirs = only_dirs_fill(path, dir_entity_list);
	display_entity(path, dir_entity_list, flags);
	fl_apply(only_dirs, flags);
	if (flags->flag_rc == 1)
		display_dirs(only_dirs, flags, ++count_rec);
	ft_list_clean(&dir_entity_list);
	ft_list_clean(&only_dirs);
}

void					display_dirs(t_node *path, \
		t_flags *flags, int count_rec)
{
	int					cnt_dirs;
	DIR					*dir;
	struct stat			buf;

	flags->entity_fill = 0;
	cnt_dirs = node_size(path);
	while (path)
	{
		dir = opendir(path->name);
		if ((cnt_dirs > 0 && ((path->buf.st_mode & S_IFDIR) == S_IFDIR ||\
		((path->buf.st_mode & S_IFLNK) == S_IFLNK && flags->\
					flag_l == 0)) && dir) || count_rec > 0)
			ft_printf("\n") && ft_printf("%s:\n", path->name);
		if (!dir && !stat(path->name, &buf) && ((path->buf.st_mode & S_IFDIR) \
		== S_IFDIR || (((path->buf.st_mode & S_IFLNK) == S_IFLNK && flags->\
					flag_l == 0))) && (path->buf.st_mode & S_IFBLK) != S_IFBLK)
			ft_printf("ft_ls: %s: %s\n", path->name, strerror(errno));
		if (dir && ((path->buf.st_mode & S_IFDIR) == S_IFDIR || \
					((path->buf.st_mode & S_IFLNK) == S_IFLNK && flags->\
					flag_l == 0)))
			count_dirs(path, flags, dir, count_rec);
		if (dir)
			closedir(dir);
		path = path->next;
	}
}
