# include "minishell.h"
#include <errno.h>

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
	env[0] = "PATH=/usr/local/sbin/:/usr/local/bin:\
	/usr/sbin:/usr/bin:/sbin:/bin:/usr/games";
	env[1] = NULL;
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
	if (pid >= 1)
		wait(&pid);
}

char	*find_home(void)
{
	extern char		**environ;
	int				i;

	i = 0;
	while (ft_strncmp(environ[i], "HOME", 4))
		++i;
	return (&environ[i][5]);
}

void	go_to_cd(char **argv)
{
	char			*home;

	if (argv[1] == NULL || argv[1][0] == '~')
	{
		home = find_home();
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
				home = find_home();
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
			if (access(ft_strjoin("/bin/", d_comm[i][0]), F_OK) != -1)
				print_command(d_comm[i]);
			else
				ft_printf("%s: command not found\n", d_comm[i][0]);
		}
		// else
			// error_no_command(d_comm[i][0]);
		++i;
	}
}
