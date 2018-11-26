/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:13:21 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/04 15:14:56 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_with_colors(t_node *entity)
{
	if ((entity->buf.st_mode & S_IFBLK) == S_IFBLK)
		ft_printf("%s%s%s%s%s", CBLUE, CBBLUE, entity->name, CBBLACK, CWHITE);
	else if ((entity->buf.st_mode & S_IFDIR) == S_IFDIR)
		ft_printf("%s%s%s", CBLUE, entity->name, CWHITE);
	else if ((entity->buf.st_mode & S_IFLNK) == S_IFLNK)
		ft_printf("%s%s%s", CPINK, entity->name, CWHITE);
	else if ((entity->buf.st_mode & S_IXUSR) == S_IXUSR)
		ft_printf("%s%s%s", CRED, entity->name, CWHITE);
	else if ((entity->buf.st_mode & S_IFCHR) == S_IFCHR)
		ft_printf("%s%s%s%s%s", CBLUE, CBYELLOW, entity->name, CBBLACK, CWHITE);
	else
		ft_printf("%s%s", CWHITE, entity->name);
}
