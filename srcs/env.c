# include "minishell.h"

void	set_env_manage(char **var, t_info *info)
{
	info->env = ft_env_add_back(info->env, var[0], var[1]);
}

int		found_in_env(char **var, t_info *info)
{
	t_env	*tmp;

	tmp = info->env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, var[0]))
			return (1);
		tmp = tmp->next;
	}
	return (-1);
}

void	change_env(char **var, t_info *info)
{
	t_env	*tmp;

	tmp = info->env;
	while (tmp)
	{
        if (!ft_strcmp(tmp->key, var[0]))
		{
            if (var[1])
                tmp->val = var[1];
            else
                tmp->val = ft_strnew(1);
        }
        tmp = tmp->next;
	}
}

char    **args_for_set_env(char **var)
{
    char        **setenv;

    setenv = NULL;
    if (ft_strchr(var[1], '='))
		setenv = ft_strsplit(var[1], '=');
	else if (var[1] && var[2])
	{
		setenv = (char **)malloc(sizeof(char *) * 3);
		setenv[0] = var[1];
		setenv[1] = var[2];
		setenv[2] = NULL;
	}
    else if (var[1] && !var[2])
    {
		setenv = (char **)malloc(sizeof(char *) * 2);
		setenv[0] = var[1];
		setenv[1] = NULL;
    }
    else
	{
		ft_printf("setenv: Variable name ");
		ft_printf("must contain alphanumeric characters.\n");
        return (NULL);
    }
    return (setenv);
}

void	env_manage(char **var, t_info *info)
{
    char        **setenv;

	if (!ft_strcmp(var[0], "setenv") && var[1])
	{
        setenv = args_for_set_env(var);
        if (!setenv)
            return ;
		if (found_in_env(setenv, info) == 1)
			change_env(setenv, info);
		else
			set_env_manage(setenv, info);
	}
	else if (!ft_strcmp(var[0], "setenv") && var[1] == NULL)
		print_env(info);
	else if (!ft_strcmp(var[0], "unsetenv") && var[1])
		info->env = ft_env_remove_by_key(info->env, var[1]);
	else
		ft_printf("unsetenv: Too few arguments.\n");
}