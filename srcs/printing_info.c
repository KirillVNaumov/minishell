# include "minishell.h"

void	print_env()
{
	extern char **environ;
	int 		i;

	i = 0;
	while (environ[i])
		ft_printf("%s\n", environ[i++]);
}

void	print_pwd()
{
	extern char **environ;

    ft_printf("%s\n", environ[26]);
}