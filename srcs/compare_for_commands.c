#include "minishell.h"
#include <errno.h>

char	*find_in_env(char *find, t_info *info)
{
	int				i;

	i = 0;
	while (ft_strncmp(info->env[i], find, ft_strlen(find)))
		++i;
	return (ft_strchr(info->env[i], '/'));
}

char	***divide_commands(char **commands)
{
	char		***d_comm;
	int			i;

	i = 0;
	while (commands[i])
		++i;
	d_comm = (char ***)malloc(sizeof(char **) * (i + 1));
	i = 0;
	while (commands[i])
	{
		d_comm[i] = ft_strsplit(commands[i], ' ');
		++i;
	}
	d_comm[i] = NULL;
	return (d_comm);
}

void	print_command(char *path, char **argv, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(path, argv, env) == -1)
			ft_printf("minishell: command not found: %s\n", path);
		exit(-1);
	}
	else if (pid == -1)
	{
		ft_printf("Unable to fork process\n");
		exit(-1);
	}
	if (pid >= 1)
		wait(&pid);
}

int	find_command(char **args, t_info *info)
{
	char	**p;
	char	*path;
	int		i;

	i = -1;
	p = ft_strsplit(find_in_env("PATH", info), ':');
	path = ft_strnew(PATH_MAX);
	while (p[++i])
	{
		ft_strclr(path);
		ft_strcat(path, p[i]);
		(args[0][0] == '/') ? 0 : ft_strcat(path, "/");
		ft_strcat(path, args[0]);
		if (access(path, F_OK) != -1)
		{
			print_command(path, args, info->env);
			i = -100;
			break ;
		}
	}
	ft_clean_arr(&p);
	ft_strdel(&path);
	if (i == -100)
		return (0);
	return (-1);
}

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
				commands[i][j] = ft_strjoin(home\
				, &commands[i][j][1]);
			}
			j++;
		}
		i++;
	}
	return (commands);
}

void	find_exit(char *str)
{
	if (!ft_strcmp(str, "exit"))
	{
		ft_printf("%s", CLEAN);
		exit(0);
	}
}

void	compare_to_commands(char **commands, t_info *info)
{
	int		i;
	char	***d_comm;

	d_comm = divide_commands(commands);
	i = 0;
	d_comm = find_tild(d_comm, info);
	while (d_comm && d_comm[i] && d_comm[i][0])
	{
		if (check_if_empty(d_comm[i][0]) == 1)
		{
			++i;
			continue ;
		}
		find_exit(d_comm[i][0]);
		if (!ft_strcmp(d_comm[i][0], "clear"))
			ft_printf("%s", CLEAN);
		else if (!ft_strcmp(d_comm[i][0], "env"))
			print_env(info);
		else if (!ft_strcmp(d_comm[i][0], "cd"))
			go_to_cd(d_comm[i], info);
		else if (!ft_strcmp(d_comm[i][0], "setenv") ||\
			!ft_strcmp(d_comm[i][0], "unsetenv"))
			env_manage(d_comm[i], );
		else
		{
			if (access(d_comm[i][0], F_OK) != -1)
				print_command(d_comm[i][0], d_comm[i], NULL);
			else if (find_command(d_comm[i], info) == -1)
				ft_printf("%s: command not found\n", d_comm[i][0]);
		}
		++i;
	}
}
