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

t_env			*ft_env_remove_by_key(t_env *list, char *key)
{
	t_env		*head;

	head = list;
	if (!ft_strcmp(list->key, key))
		return (list->next);
	while (list && list->next && ft_strcmp(list->next->key, key))
		list = list->next;
	if (list->next && !ft_strcmp(list->next->key, key))
		list->next = list->next->next;
	if (list && !ft_strcmp(list->key, key))
		list->next = NULL;
	return (head);
}
