# include "minishell.h"

char        *add_to_str(char *str, char c)
{
    char    *charecter;

    charecter = (char *)malloc(sizeof(char) * 2);
    charecter[0] = c;
    charecter[1] = '\0';
    str = ft_update(str, ft_strjoin(str, charecter));
    free(charecter);
    return (str);
}

void        manage_space(char *c, char **str, t_list **list)
{
    char    *tmp;

    tmp = ft_strnew(1);
    while (**str && **str != ' ' && (int)**str != 39 && **str != 34)
    {
        tmp = add_to_str(tmp, **str);
        ++(*str);
    }
    if (**str != '\0')
        ++(*str);
    if (**str == 34 || **str == 39)
        *c = **str;
    else
        *c = ' ';
    *list = ft_list_add_back(*list, tmp);
    free(tmp);
}

void        manage_quotes(char *c, char **str, t_list **list)
{
    char    *tmp;

    tmp = ft_strnew(1);
    while (**str && **str != *c)
    {
        tmp = add_to_str(tmp, **str);
        ++(*str);
    }    
    *c = **str;
    if (**str != '\0')
        ++(*str);
    *list = ft_list_add_back(*list, tmp);
    free(tmp);
}

t_list        *clean_empty_elems(t_list *list)
{
    t_list      *new;

    new = NULL;
    while (list)
    {
        if (list->name && list->name[0] != '\0' && (ft_strlen(list->name) != 1 || list->name[0] != ' '))
            new = ft_list_add_back(new, list->name);
        list = list->next;
    }
    return (new);
}

char        **list_to_arr(t_list *list)
{
    int     i;
    int     length;
    char    **new;

    length = ft_list_size(list);
    new = (char **)malloc(sizeof(char *) * (length + 1));
    i = 0;
    while (i < length)
    {
        new[i] = ft_strdup(list->name);
        list = list->next;
        ++i;
    }
    new[i] = NULL;
    return (new);
}

char        **divide_and_conquer(char *str)
{
    char    c;
    t_list  *list;

    list = NULL;
    c = ' ';    
    while (*str)
    {
        if (c == ' ')
            manage_space(&c, &str, &list);
        if ((int)c == 34 || (int)c == 39)
            manage_quotes(&c, &str, &list);
    }
    list = clean_empty_elems(list);
    return (list_to_arr(list));
}

char        ***parse_with_args(char **args)
{
    int     i;
    char    ***new;

    i = 0;
    while (args[i])
        ++i;
    new = (char ***)malloc(sizeof(char **) * (i + 1));
    i = -1;
    while (args[++i])
        new[i] = divide_and_conquer(args[i]);
    return (new);
}