/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:29:43 by knaumov           #+#    #+#             */
/*   Updated: 2019/01/15 14:29:44 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	***find_tild(char ***commands, t_info *info)
{
	char	*home;
	int		i;
	int		j;

	i = 0;
	while (commands[i] && commands[i][0])
	{
		j = 1;
		while (commands[i][j])
		{
			if (commands[i][j][0] == '~')
			{
				home = find_in_env("HOME", info);
				commands[i][j] = ft_update(commands[i][j], ft_strjoin(home\
				, &commands[i][j][1]));
			}
			j++;
		}
		i++;
	}
	return (commands);
}

void	change_pwd(char *address, t_info *info)
{
	free(info->old_pwd);
	info->old_pwd = ft_strdup(info->pwd);
	info->pwd = new_pwd(info->pwd, address);
}

int		check_if_empty(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] > ' ')
			return (0);
		++i;
	}
	return (1);
}
