/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:50:11 by knaumov           #+#    #+#             */
/*   Updated: 2018/11/26 13:14:27 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include "minishell.h"

# define CRED  "\x1B[31m"
# define CBLUE  "\x1B[34m"
# define CPINK  "\x1B[35m"
# define CWHITE  "\x1B[39m"
# define CBBLUE "\x1B[46m"
# define CBYELLOW "\x1B[43m"
# define CBBLACK "\x1B[40m"

typedef struct		s_node
{
	char			*name;
	struct stat		buf;
	struct s_node	*next;
}					t_node;

typedef struct		s_flags
{
	int				flag_a;
	int				flag_l;
	int				flag_t;
	int				flag_r;
	int				flag_g;
	int				flag_n;
	int				flag_d;
	int				flag_sc;
	int				flag_tc;
	int				flag_gc;
	int				flag_rc;
	int				entity_fill;
	int				flag_illegal;
}					t_flags;

int					node_size(t_node *begin_list);
void				node_swap(t_node *one, t_node *two);
void				node_copy(t_node *src, t_node *dst);
t_node				*node_remove_hidden(t_node *begin_list);
t_node				*node_sort_by_name(t_node *info, int is_asc);
t_node				*node_sort_by_time(t_node *info, int is_asc);
t_node				*node_sort_by_size(t_node *info, int is_asc);
t_node				*node_add(t_node *info, char *name, struct stat buf);
void				fl_init(t_flags *flags);
void				fl_set(char *str, t_flags *flags);
char				*help_func(char *link, char *path);
char				*getting_full_symlink(char *link, char *path);
long long			count_blocks(t_node *entity);
t_node				*fl_apply(t_node *node_list, t_flags *flags);
t_node				*path_search_errors(t_node *path);
t_node				*path_apply_flag(t_node *path, t_flags *flags);
char				*mode_print(mode_t mode);
void				mode_select(mode_t mode, char *c);
void				display_dirs(t_node *path, t_flags *flags, int count_rec);
void				display_files(t_node *path, t_flags *flags);
void				display_entity(t_node *path, t_node *entity, \
				t_flags *flags);
void				display_symlink(t_node *path, t_flags *flags);
void				display_blocks(t_node *path, t_flags *flags);
void				print_with_colors(t_node *entity);
char				*delete_slash(char *str);
void				ft_list_clean(t_node **list);
char				*getting_full_symlink(char *link, char *path);
int					ft_str_find(char *s1, char *s2);
void				display_only_args(t_node *path, t_flags *flags);

#endif
