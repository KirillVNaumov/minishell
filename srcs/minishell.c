/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:07:42 by amelikia          #+#    #+#             */
/*   Updated: 2019/01/10 17:22:05 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_env(t_info *info)
{
	extern char		**environ;
	char			**tmp;
	int				i;

	i = 0;
	info->env = NULL;
	while (environ[i])
	{
		tmp = ft_strsplit(environ[i], '=');
		info->env = ft_env_add_back(info->env, tmp[0], tmp[1]);
		ft_clean_arr(&tmp);
		++i;
	}
	info->old_pwd = ft_strdup(find_in_env("OLDPWD", info));
	info->pwd = ft_strdup(find_in_env("PWD", info));
}

void	main_while_loop(void)
{
	char			*line;
	char			**commands;
	t_info			info;

	ft_bzero(&info, sizeof(t_info *));
	create_env(&info);
	// rl_bind_key('\t', rl_complete);
	while (1)
	{
		commands = NULL;
		ft_printf("%s$> %s", CBLUE, CWHITE);
		get_next_line(0, &line);
		// line = readline(CBLUE"$> " CWHITE);
		// if (!line)
			// break ;
		// add_history(line);
		if (ft_strstr(line, ";;") == NULL)
			commands = ft_strsplit(line, ';');
		else
		{
			ft_printf("minishell: parse error near `;;'\n");
			continue ;
		}
		commands = cleaning_matrix(&commands);
		compare_to_commands(commands, &info);
		ft_clean_arr(&commands);
		free(line);
	}
}

int		main(void)
{
	ft_printf("%s", CLEAN);
	main_while_loop();
	return (0);
}
