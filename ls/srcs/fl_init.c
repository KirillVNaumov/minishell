/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:43:19 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/10 18:44:56 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		fl_init(t_flags *flags)
{
	flags->flag_a = 0;
	flags->flag_l = 0;
	flags->flag_r = 0;
	flags->flag_t = 0;
	flags->flag_g = 0;
	flags->flag_n = 0;
	flags->flag_d = 0;
	flags->flag_sc = 0;
	flags->flag_tc = 0;
	flags->flag_gc = 0;
	flags->flag_rc = 0;
	flags->entity_fill = 0;
	flags->flag_illegal = 0;
}
