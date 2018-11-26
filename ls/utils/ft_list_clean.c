/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:39:23 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/05 20:54:52 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_list_clean(t_node **list)
{
	t_node	*link;

	if (*list == NULL)
		return ;
	link = *list;
	if (link->next)
		ft_list_clean(&link->next);
	free(link->name);
	free(*list);
}
