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

void	main_while_loop(void)
{
	char			*line;
	char			**commands;
	t_minishell		minishell;

	ft_bzero(&minishell, sizeof(t_minishell));
	minishell.buf = NULL;
	minishell.commands = NULL;
	minishell.path = NULL;
	while (1)
	{
		commands = NULL;
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
