/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_remove_hidden.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:41:47 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/01 10:41:48 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node	*node_remove_hidden(t_node *root)
{
	t_node	*current;

	current = root;
	while (current && current->name[0] == '.')
		root = current->next;
	while (current && current->next)
	{
		if (current->next->name[0] == '.')
			current->next = current->next->next;
		current = current->next;
	}
	return (root);
}
