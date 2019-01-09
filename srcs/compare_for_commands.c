# include "minishell.h"
#include <errno.h>

char	*find_in_env(char *find)
{
	extern char		**environ;
	int				i;

	i = 0;
	while (ft_strncmp(environ[i], find, 4))
		++i;
	return (&environ[i][5]);
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
	// char	**env;

	// env = (char**)malloc(sizeof(char*) * 2);
	// env[0] = "PATH=/nfs/2018/a/amelikia/.brew/bin:/usr/local/\
	// bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/Library/\
	// Frameworks/Mono.framework/Versions/Current/Commands:/usr/local/munki";
	// env[1] = NULL;
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, argv, env) == -1)
			ft_printf("minishell: premission denied: %s\n", path);
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

int	find_command(char **args, char **env)
{
	char	**p;
	char	*path;
	int		i;

	i = -1;
	p = ft_strsplit(find_in_env("PATH"), ':');
	path = ft_strnew(PATH_MAX);
	while (p[++i])
	{
		ft_strclr(path);
		ft_strcat(path, p[i]);
		(args[0][0] == '/') ? 0 : ft_strcat(path, "/");
		ft_strcat(path, args[0]);
		if (access(path, F_OK) != -1)
		{
			print_command(path, args, env);
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

void	go_to_cd(char **argv)
{
	char			*home;

	if (argv[1] == NULL || argv[1][0] == '~')
	{
		home = find_in_env("HOME");
		if (argv[1] == NULL || argv[1][1] == '\0')
			chdir(ft_strjoin("/", home));
		else
			chdir(ft_strjoin(ft_strjoin("/", home), &argv[1][1]));
	}
	else if (argv[2])
	{
		ft_printf("cd: string not in pwd: %s", argv[1]);
		exit(-1);
	}
	else if (chdir(argv[1]) != 0)
	{
		ft_printf("minishell: No such file or directory");
		exit(-1);
	}
}

char	***find_tild(char ***commands)
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
				home = find_in_env("HOME");
				commands[i][j] = ft_strjoin(ft_strjoin("/", home)\
				, &commands[i][j][1]);
			}
			j++;
		}
		i++;
	}
	return (commands);
}

void	compare_to_commands(char **commands)
{
	int		i;
	char	***d_comm;
	extern char	**environ;

	d_comm = divide_commands(commands);
	i = 0;
	d_comm = find_tild(d_comm);
	while (d_comm && d_comm[i] && d_comm[i][0])
	{
		if (check_if_empty(d_comm[i][0]) == 1)
		{
			++i;
			continue ;
		}
		if (!ft_strcmp(d_comm[i][0], "exit"))
		{
			ft_printf("%s", CLEAN);
			exit(0);
		}
		else if (!ft_strcmp(d_comm[i][0], "clear"))
			ft_printf("%s", CLEAN);
		else if (!ft_strcmp(d_comm[i][0], "env"))
			print_env();
		else if (!ft_strcmp(d_comm[i][0], "cd"))
			go_to_cd(d_comm[i]);
		else
		{
			if (access(d_comm[i][0], F_OK) != -1)
				print_command(d_comm[i][0], d_comm[i], NULL);
			else if (find_command(d_comm[i], environ) == -1)
				ft_printf("%s: command not found\n", d_comm[i][0]);
		}
		// else
			// error_no_command(d_comm[i][0]);
		++i;
	}
}
