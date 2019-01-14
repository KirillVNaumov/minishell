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
		if (s2)
			list->val = ft_strdup(s2);
		else
			list->val = ft_strnew(1);
		list->next = NULL;
		return (list);
	}
	node = (t_env *)malloc(sizeof(t_env));
	begining = list;
	node->next = NULL;
	node->key = ft_strdup(s1);
	if (s2)
		node->val = ft_strdup(s2);
	else
		node->val = ft_strnew(1);
	while (list->next)
		list = list->next;
	list->next = node;
	return (begining);
}

t_env			*ft_env_remove_by_key(t_env *list, char *key)
{
	t_env		*head;
	t_env		*tmp;

	head = list;
	if (!ft_strcmp(list->key, key))
	{
		tmp = list->next;
		free(list->key);
		free(list->val);
		free(list);
		return (tmp);
	}
	while (list && list->next && ft_strcmp(list->next->key, key))
		list = list->next;
	if (list && list->next && !ft_strcmp(list->next->key, key))
	{
		tmp = list->next;
		list->next = list->next->next;
		free(tmp->key);
		free(tmp->val);
		free(tmp);
	}
	else if (list && !ft_strcmp(list->key, key))
	{
		tmp = list;
		list->next = NULL;
		free(tmp->key);
		free(tmp->val);
		free(tmp);
	}
	return (head);
}
