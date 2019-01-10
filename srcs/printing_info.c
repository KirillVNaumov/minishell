# include "minishell.h"

void	print_env(void)
{
	extern char **environ;
	char	**argv;

	argv = (char**)malloc(sizeof(char*) * 2);
	argv[0] = "pwd";
	argv[1] = NULL;
	int		i;
	pid_t	pid;

	pid = fork();
	i = 0;
	while (environ[i])
	{
		if (ft_strncmp(environ[i], "PWD", 3))
			ft_printf("%s\n", environ[i]);
		else if (pid == 0)
		{
			ft_printf("PWD=");
			execve("/bin/pwd", argv, NULL);
		}
		else
			wait(&pid);
		++i;
	}
}

void	print_pwd(void)
{
	extern char **environ;

	ft_printf("%s\n", environ[26]);
}
