#include "minishell.h"

char    *new_pwd(char *old_pwd, char *address)
{
	char		**arr;
	char		*str;
	int			i;
	t_list	*pwd;

	i = 0;
	pwd = NULL;
	address = ft_strjoin("/", address);
	address = ft_strjoin(&old_pwd[1], address);
	arr = ft_strsplit(address, '/');
	while (arr[i])
	{
		if (!ft_strcmp(arr[i], ".."))
			ft_list_remove_back(&pwd);
		else if (!ft_strcmp(arr[i], "."))
			continue ;
		else
			pwd = ft_list_add_back(pwd, arr[i]);
		i++;
	}
	str = ft_strnew(1);
	if (!pwd)
		str = ft_strjoin(str, "/");
	while (pwd)
	{
		str = ft_strjoin(str, "/");
		str = ft_strjoin(str, pwd->dir);
		pwd = pwd->next;
	}
	return (str);
}

void    change_pwd(char *address, t_info *info)
{
	free(info->old_pwd);
	info->old_pwd = ft_strdup(info->pwd);
	// free(info->pwd);
	info->pwd = new_pwd(info->pwd, address);
}

void	go_to_cd(char **argv, t_info *info)
{
	char	*home;
	char	*address;

	if (argv[1] == NULL || argv[1][0] == '~')
	{
		home = find_in_env("HOME", info);
		address = ft_strdup(home);
		if (argv[1] == NULL || argv[1][1] == '\0')
		{
			info->old_pwd = ft_strdup(info->pwd);
			info->pwd = home;
			ft_printf("OLD_PWD = %s\nPWD = %s\n", info->old_pwd, info->pwd);
			chdir(address);
		}
		else if (argv[1][0] == '~' && argv[1][1] == '/')
		{
			ft_printf("---~LOL\n");

			address = ft_update(address, (ft_strjoin("/", home), &argv[1][1]));
			change_pwd(address, info);
			ft_printf("OLD_PWD = %s\nPWD = %s\n", info->old_pwd, info->pwd);
			chdir(address);
		}
	}
	else if (argv[2])
		ft_printf("cd: string not in pwd: %s", argv[1]);
	else if (chdir(argv[1]) == 0)
	{
		address = ft_strdup(argv[1]);
		change_pwd(address, info);
		ft_printf("OLD_PWD = %s\nPWD = %s\n", info->old_pwd, info->pwd);
	}
	else
		ft_printf("minishell: No such file or directory\n");
}
