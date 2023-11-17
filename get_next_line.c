/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:39:34 by caredua3          #+#    #+#             */
/*   Updated: 2023/11/16 20:44:10 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	adjust_list_head(t_list **l_gnl)
{
	t_list	*temp;

	while (*l_gnl && (*l_gnl)->content != '\n')
	{
		temp = *l_gnl;
		*l_gnl = (*l_gnl)->next;
		free(temp);
	}
	if (*l_gnl && (*l_gnl)->content == '\n')
	{
		temp = *l_gnl;
		*l_gnl = (*l_gnl)->next;
		free(temp);
	}
}

static void	form_setence_from_list(t_list **l_gnl, char **string_read)
{
	t_list	*current;
	int		index;

	current = *l_gnl;
	index = 0;
	*string_read = (char *)malloc(ft_lstsize_or_size_newline(*l_gnl) + 1
			* sizeof(char));
	ft_memset(*string_read, '\0', ft_lstsize_or_size_newline(*l_gnl) + 1);
	while (current)
	{
		if (current->content == '\n')
		{
			(*string_read)[index] = current->content;
			return ;
		}
		(*string_read)[index] = current->content;
		index++;
		current = current->next;
	}
}

static void	initial_and_allocations_list(t_list **l_gnl, char *buffer,
		char **string_read)
{
	t_list	*current;

	while (*buffer)
		ft_lstadd_back(l_gnl, ft_lstnew(*buffer++));
	current = *l_gnl;
	while (current->next)
	{
		if (current->content == '\n')
		{
			form_setence_from_list(l_gnl, string_read);
			if (current->next && current->next->content)
			{
				adjust_list_head(l_gnl);
				break ;
			}
			else
				ft_lstclear(l_gnl);
		}
		current = current->next;
	}
}

char	*get_next_line(int fd)
{
	int				bytes_read;
	char			*string_read;
	char			*buffer;
	static t_list	*l_gnl;

	bytes_read = 0;
	string_read = NULL;
	while (1)
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
		ft_memset(buffer, '\0', BUFFER_SIZE + 1);
		if (fd == -1)
		{
			free(buffer);
			return (NULL);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (bytes_read == 0 && ft_lstsize_or_size_newline(l_gnl) > 0)
		{
			form_setence_from_list(&l_gnl, &string_read);
			ft_lstclear(&l_gnl);
			free(buffer);
			return (string_read);
		}
		if (bytes_read == 0)
		{
			free(buffer);
			return (NULL);
		}
		initial_and_allocations_list(&l_gnl, buffer, &string_read);
		free(buffer);
		if (string_read)
			break ;
	}
	return (string_read);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("arquivo1.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		printf("%s", str);
		free(str);
	}
	close(fd); // Feche o arquivo após a leitura
	return (0);
}
