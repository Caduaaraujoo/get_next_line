/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:57:32 by caredua3          #+#    #+#             */
/*   Updated: 2023/11/15 20:34:57 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*j;

	j = s;
	i = 0;
	while (i < n)
	{
		j[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

t_list	*ft_lstnew(char character)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(1 * sizeof(t_list));
	ft_memset(new_list, '\0', 1 * sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	new_list->content = character;
	return (new_list);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

int	ft_lstsize_or_size_newline(t_list *lst)
{
	int		size;
	t_list	*current;

	size = 0;
	current = lst;
	while (current)
	{
		if (current->content == '\n')
			return (size + 1);
		current = current->next;
		size++;
	}
	return (size);
}

void	ft_lstclear(t_list **lst)
{
	t_list *current;
	t_list *next;

	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}