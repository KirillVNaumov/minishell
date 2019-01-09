#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <limits.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct  s_minishell
{
    char        **commands;
    char        *path;
    char        *buf;
}               t_minishell;

char        	**cleaning_matrix(char ***commands);
void            print_env();
void            print_pwd();
int			    check_if_empty(char *str);
void	        compare_to_commands(char **commands);

//ERROR MANAGMENT
void    	    error_permissions(char *command, char *file);
void            error_arguments(char *command);
void            error_no_command(char *command);

#endif
