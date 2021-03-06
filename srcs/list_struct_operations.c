/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_struct_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:29:06 by knaumov           #+#    #+#             */
/*   Updated: 2019/01/15 14:29:07 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_list_size(t_list *root)
{
	int		i;
	t_list	*entity;

	i = 1;
	if (!root)
		return (0);
	if (root)
	{
		entity = root;
		while (entity)
			(entity = entity->next) && i++;
	}
	return (i);
}

void	ft_list_clean(t_list **list)
{
	t_list *node;

	if (*list == NULL || list == NULL)
		return ;
	node = *list;
	if (node && node->next)
		ft_list_clean(&node->next);
	ft_strdel(&node->name);
	ft_memdel((void**)list);
}

t_list	*ft_list_add_back(t_list *list, char *dir)
{
	t_list		*begining;
	t_list		*node;

	if (list == NULL)
	{
		list = (t_list *)malloc(sizeof(t_list));
		list->name = ft_strdup(dir);
		list->next = NULL;
		return (list);
	}
	node = (t_list *)malloc(sizeof(t_list));
	begining = list;
	node->next = NULL;
	node->name = ft_strdup(dir);
	while (list->next)
		list = list->next;
	list->next = node;
	return (begining);
}

void	ft_list_remove_back(t_list **list)
{
	t_list		*tmp;
	t_list		*node;

	if (*list == NULL)
		return ;
	if (ft_list_size(*list) == 1)
	{
		free((*list)->name);
		free(*list);
		*list = NULL;
		return ;
	}
	node = *list;
	while (node->next->next)
		node = node->next;
	tmp = node->next;
	node->next = NULL;
	free(tmp->name);
	free(tmp);
}
