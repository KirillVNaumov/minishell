/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:41:54 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/01 10:41:55 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		node_size(t_node *root)
{
	int		i;
	t_node	*entity;

	i = 0;
	if (root)
	{
		entity = root;
		while (entity)
			(entity = entity->next) && i++;
	}
	return (i);
}
