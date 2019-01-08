/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:07:42 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/26 13:14:54 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error(char *reason)
{
	ft_printf("Error: %s\n", reason);
	exit(0);
}

void	print_env()
{
	extern char **environ;
	int 		i;

	i = 0;
	while (environ[i])
		ft_printf("%s\n", environ[i++]);
}

void	compare_to_commands(char **commands)
{
	int		i;

	i = 0;
	while (commands[i])
	{
		if (!ft_strcmp(commands[i], "exit"))
		{
			ft_printf("%s", CLEAN);
			exit (0);
		}
		else if (!ft_strcmp(commands[i], "clear"))
			ft_printf("%s", CLEAN);
		else if (!ft_strcmp(commands[i], "env"))
			print_env();
		else
			ft_printf("minishell: command not found: %s\n", commands[i]);
		++i;
	}
}

void	main_while_loop(void)
{
	char	*line;
	char	**commands;

	while (1)
	{
		ft_printf("%s$>%s ", CBLUE, CWHITE);
		get_next_line(0, &line);
		if (ft_strstr(line, ";;") == NULL)
			commands = ft_strsplit(line, ';');
		else
		{
			ft_printf("minishell: parse error near `;;'\n");
			continue ;
		}
		commands = cleaning_matrix(&commands);
		compare_to_commands(commands);
		ft_clean_arr(&commands);
		ft_strdel(&line);
	}
}

int		main(void)
{
	ft_printf("%s", CLEAN);
	main_while_loop();
	return (0);
}
