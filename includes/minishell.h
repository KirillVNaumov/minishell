#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <limits.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct          s_info
{
    char                *pwd;
    char                *old_pwd;
    char                **env;
}                       t_info;

typedef struct          s_list
{
    char                *dir;
    struct  s_list      *next;
}                       t_list;

char                	**cleaning_matrix(char ***commands);
void	                print_env(t_info *info);
int	        		    check_if_empty(char *str);
void	                compare_to_commands(char **commands, t_info *info);
void        	        go_to_cd(char **argv, t_info *info);
char                	*find_in_env(char *find, t_info *info);
t_list	                *ft_list_add_back(t_list *list, char *dir);
void        			ft_list_remove_back(t_list **list);

//ERROR MANAGMENT
void            	    error_permissions(char *command, char *file);
void                    error_arguments(char *command);
void                    error_no_command(char *command);

#endif
