/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:07:42 by amelikia          #+#    #+#             */
/*   Updated: 2019/01/09 13:38:01 by amelikia         ###   ########.fr       */
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
    rl_bind_key('\t', rl_complete);
	while (1)
	{
		commands = NULL;
		// ft_printf("%s$>%s ", CBLUE, CWHITE);
        line = readline(CBLUE"$> " CWHITE);
        if (!line)
            break;
        add_history(line);
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
		// free(&line);
	}
}

int		main(void)
{
	ft_printf("%s", CLEAN);
	main_while_loop();
	return (0);
}
