# include "minishell.h"

int			finding_length(char *str)
{
	int		length;
	int		i;

	i = 0;
	length = 0;
	while (str[i] <= ' ')
		++i;
	while (str[i])
	{
		while (str[i] && str[i] > ' ')
		{
			++length;
			++i;
		}
		if (str[i] && str[i] <= ' ')
		{
			++length;
			while (str[i] && str[i] <= ' ')
				++i;
		}
	}
	if (str[i - 1] <= ' ')
		--length;
	return (length);
}

char	*cleaning_string(char *str)
{
	char	*new;
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	length = finding_length(str);
	new = (char *)malloc(sizeof(char) * finding_length(str) + 1);
	while (str[i] <= ' ')
		++i;
	while (str[i])
	{
		while (str[i] && str[i] > ' ')
			new[j++] = str[i++];
		if (j == length)
			break ;
		if (str[i] && str[i] <= ' ')
		{
			new[j++] = ' ';
			while (str[i] && str[i] <= ' ')
				++i;
		}
	}
	new[j] = '\0';
	return (new);
}

char	**cleaning_matrix(char ***commands)
{
	char	**arr;
	int		i;
	int		length;

	length = 0;
	while ((*commands)[length])
		++length;
	arr = (char **)malloc(sizeof(char *) * (length + 1));
	i = -1;
	while (++i < length)
		arr[i] = cleaning_string((*commands)[i]);
    arr[i] = NULL;
	ft_clean_arr(commands);
	return (arr);
}
