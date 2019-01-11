#include "minishell.h"

int		ft_env_size(t_env *root)
{
	int		i;
	t_env	*entity;

	i = 1;
	if (!root)
		return (0);
	if (root)
	{
		entity = root;
		while (entity)
			(entity = entity->next) && i++;
	}
	return (i);
}

t_env			*ft_env_add_back(t_env *list, char *s1, char *s2)
{
	t_env		*begining;
	t_env		*node;

	if (list == NULL)
	{
		list = (t_env *)malloc(sizeof(t_env));
		list->key = ft_strdup(s1);
		list->val = ft_strdup(s2);
		list->next = NULL;
		return (list);
	}
	node = (t_env *)malloc(sizeof(t_env));
	begining = list;
	node->next = NULL;
	node->key = ft_strdup(s1);
	node->val = ft_strdup(s2);
	while (list->next)
		list = list->next;
	list->next = node;
	return (begining);
}

void			ft_env_remove_back(t_env **list)
{
	t_env		*tmp;
	t_env		*node;

	if (*list == NULL)
		return ;
	if (ft_env_size(*list) == 1)
	{
		free((*list)->key);
		free((*list)->val);
		free(*list);
		*list = NULL;
		return ;
	}
	node = *list;
	while (node->next->next)
		node = node->next;
	tmp = node->next;
	node->next = NULL;
	free(tmp->key);
	free(tmp->val);
	free(tmp);
}
