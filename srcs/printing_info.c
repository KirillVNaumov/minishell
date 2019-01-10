#include "minishell.h"

void	print_env(t_info *info)
{
	int	i;

	i = 0;
	while (info->env[i])
	{
		if (ft_strncmp(info->env[i], "PWD", 3)\
		&& ft_strncmp(info->env[i], "OLDPWD", 3))
			ft_printf("%s\n", info->env[i]);
		else
		{
			if (!ft_strncmp(info->env[i], "PWD", 3))
				ft_printf("PWD=%s\n", info->pwd);
			if (!ft_strncmp(info->env[i], "OLDPWD", 3))
				ft_printf("OLDPWD=%s\n", info->old_pwd);
		}
		++i;
	}
}
