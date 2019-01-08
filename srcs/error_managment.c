# include "minishell.h"

void	error_permissions(char *command, char *file)
{
	ft_printf("%s: %s: Permission denied\n", command, file);
}

void    error_arguments(char *command)
{
    ft_printf("%s: too many arguments\n", command);
}

void    error_no_command(char *command)
{
    ft_printf("minishell: command not found: %s\n", command);
}