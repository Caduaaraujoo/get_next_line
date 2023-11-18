/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:57:32 by caredua3          #+#    #+#             */
/*   Updated: 2023/11/17 20:49:39 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*vector;
	size_t	bytes;
	size_t	i;

	i = 0;
	bytes = nmemb * size;
	if (!size || bytes / size != nmemb)
		return (malloc(0));
	vector = malloc(nmemb * size);
	if (vector == NULL)
		return (vector);
	while (i < bytes)
	{
		((unsigned char *)vector)[i] = '\0';
		i++;
	}
	return (vector);
}

t_list	*ft_lstnew(char character)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	new_list->content = character;
	new_list->next = NULL;
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

	if (lst == NULL || *lst == NULL)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		current->content = 0;
		free(current);
		current = next;
	}
	*lst = NULL;
}