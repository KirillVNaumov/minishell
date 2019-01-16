#include "minishell.h"

void	manage_dollar(char **args, t_info *info)
{
	int		i;

	i = 0;
	while (args[i])
	{
		if (args[i][0] == '$')
			args[i] = ft_update(args[i],\
				ft_strdup(find_in_env((&args[i][1]), info)));
		i++;
	}
}
