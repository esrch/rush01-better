#include <stdio.h>
#include <stdlib.h>

#include "common.h"

int int_list_add(t_int_list **list, int num)
{
	t_int_list	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (-1);
	new_node->next = NULL;
	new_node->num = num;
	if (!*list)
		*list = new_node;
	else
		int_list_last(*list)->next = new_node;
	return (0);
}

void int_list_destroy(t_int_list *list)
{
	t_int_list	*next;

	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
}

size_t int_list_len(t_int_list *list)
{
	size_t	len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

t_int_list *int_list_last(t_int_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

static int extract_num(char *s, t_int_list **list)
{
	char	*start;
	char	tmp_char;
	int		num;

	start = s;
	while (*s && *s != ' ' && *s != '\n')
	{
		if (*s < '0' || *s > '9')
			return (-1);
		s++;
	}
	tmp_char = *s;
	*s = '\0';
	num = atoi(start);
	*s = tmp_char;
	if (int_list_add(list, num) != 0)
		return (-1);
	return (s - start);
}

t_int_list *int_list_from_str(char *s)
{
	t_int_list	*list;
	int			len;

	list = NULL;
	while (*s)
	{
		if (*s == ' ' || *s == '\n')
			s++;
		else
		{
			len = extract_num(s, &list);
			if (len < 0)
			{
				int_list_destroy(list);
				return (NULL);
			}
			s += len;
		}
	}
	return (list);
}

int *int_list_to_arr(t_int_list *list)
{
	int		*arr;
	size_t	len;
	size_t	i;

	if (!list)
		return (NULL);
	len = int_list_len(list);
	arr = malloc(sizeof(*arr) * len);
	if (!arr)
		return (NULL);
	i = 0;
	while (list)
	{
		arr[i] = list->num;
		list = list->next;
		i++;
	}
	return (arr);
}

int	*int_str_to_arr(char *s)
{
	int			*arr;
	t_int_list	*list;

	list = int_list_from_str(s);
	if (!list)
		return (NULL);
	arr = int_list_to_arr(list);
	int_list_destroy(list);
	return (arr);
}