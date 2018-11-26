/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:42:26 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/01 10:42:27 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	node_swap(t_node *one, t_node *two)
{
	t_node *temp;

	temp = (t_node *)malloc(sizeof(t_node));
	node_copy(one, temp);
	node_copy(two, one);
	node_copy(temp, two);
	free(temp);
}
