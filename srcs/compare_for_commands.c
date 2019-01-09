# include "minishell.h"

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

void	print_command(char **argv)
{
	pid_t	pid;
	char	**env;

	env = (char**)malloc(sizeof(char*) * 2);
	env[1] = "PATH=/usr/local/sbin/:/usr/local/bin:\
	/usr/sbin:/usr/bin:/sbin:/bin:/usr/games";
	env[2] = NULL;
	pid = fork();
	if (pid == 0)
	{
		if (execve(ft_strjoin("/bin/", argv[0]), argv, env) == -1)
			ft_printf("minishell: premission denied: %s\n", argv[0]);
		exit(-1);
	}
	else if (pid == -1)
	{
		ft_printf("Unable to fork process\n");
		exit(-1);
	}
	else
		wait(&pid);
}

void	compare_to_commands(char **commands)
{
	int		i;
	char	***d_comm;

	d_comm = divide_commands(commands);
	i = 0;
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
		else if (!ft_strcmp(d_comm[i][0], "pwd"))
			print_pwd();
		else
			print_command(d_comm[i]);
		// else
			// error_no_command(d_comm[i][0]);
		++i;
	}
}
