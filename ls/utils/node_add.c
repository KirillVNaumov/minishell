/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:40:45 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/01 10:40:46 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node	*node_add(t_node *root, char *name, struct stat buf)
{
	t_node *temp;
	t_node *begin_list;

	if (root == NULL)
	{
		root = malloc(sizeof(t_node));
		root->name = ft_strdup(name);
		root->buf = buf;
		root->next = NULL;
		return (root);
	}
	begin_list = root;
	temp = (t_node *)malloc(sizeof(t_node));
	temp->name = ft_strdup(name);
	temp->buf = buf;
	temp->next = NULL;
	while (root->next)
		root = root->next;
	root->next = temp;
	return (begin_list);
}
