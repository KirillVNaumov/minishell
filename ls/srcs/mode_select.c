/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:43:40 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/01 10:43:41 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	mode_select(mode_t mode, char *c)
{
	if ((mode & S_IFDIR) == S_IFDIR)
		*c = 'd';
	if ((mode & S_IFCHR) == S_IFCHR)
		*c = 'c';
	if ((mode & S_IFIFO) == S_IFIFO)
		*c = 'p';
	if ((mode & S_IFBLK) == S_IFBLK)
		*c = 'b';
	if ((mode & S_IFREG) == S_IFREG)
		*c = '-';
	if ((mode & S_IFLNK) == S_IFLNK)
		*c = 'l';
	if ((mode & S_IFSOCK) == S_IFSOCK)
		*c = 's';
}
