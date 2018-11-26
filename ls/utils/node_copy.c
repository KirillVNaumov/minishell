/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:41:38 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/01 10:41:39 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	node_copy(t_node *src, t_node *dst)
{
	t_node *temp;

	temp = dst;
	temp->name = src->name;
	temp->buf = src->buf;
}