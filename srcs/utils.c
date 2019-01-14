#include "minishell.h"

char	***find_tild(char ***commands, t_info *info)
{
	char	*home;
	int		i;
	int		j;

	i = 0;
	while (commands[i])
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

int			check_if_empty(char *str)
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