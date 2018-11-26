/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:43:26 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/10 18:50:08 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	void	continue_func(t_flags *flags, char c)
{
	if (c == 'd')
		flags->flag_d = 1;
	else if (c == 'n')
		flags->flag_n = 1;
	else if (c == 'S')
		flags->flag_sc = 1;
	else if (c == 'T')
		flags->flag_tc = 1;
	else if (c == 'R')
		flags->flag_rc = 1;
	else if (c == 'G')
		flags->flag_gc = 1;
	else
	{
		flags->flag_illegal = 1;
		ft_printf("ft_ls: illegal option -- %c\n", c);
		ft_printf("usage: ./ft_ls [GSTadglrt] [file ...]\n");
	}
}

void			fl_set(char *str, t_flags *flags)
{
	while (*str != '\0' && flags->flag_illegal == 0)
	{
		if (*str == 'l')
			flags->flag_l = 1;
		else if (*str == 'a')
			flags->flag_a = 1;
		else if (*str == 't')
			flags->flag_t = 1;
		else if (*str == 'r')
			flags->flag_r = 1;
		else if (*str == 'g')
		{
			flags->flag_l = 1;
			flags->flag_g = 1;
		}
		else
			continue_func(flags, *str);
		str++;
	}
}
