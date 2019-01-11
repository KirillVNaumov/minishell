#include "minishell.h"

void	print_env(t_info *info)
{
	t_env *tmp;

	tmp = info->env;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, "PWD", 3)\
		&& ft_strncmp(tmp->key, "OLDPWD", 3))
			ft_printf("%s=%s\n", tmp->key, tmp->val);
		else
		{
			if (!ft_strncmp(tmp->key, "PWD", 3))
				ft_printf("PWD=%s\n", info->pwd);
			if (!ft_strncmp(tmp->key, "OLDPWD", 3))
				ft_printf("OLDPWD=%s\n", info->old_pwd);
		}
		tmp = tmp->next;
	}
}
