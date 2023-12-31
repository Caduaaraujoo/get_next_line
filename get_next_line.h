/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:38:00 by caredua3          #+#    #+#             */
/*   Updated: 2023/11/17 21:39:42 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif

typedef struct s_list
{
	char			content;
	struct s_list	*next;
}					t_list;
char				*get_next_line(int fd);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize_or_size_newline(t_list *lst);
void				ft_lstclear(t_list **lst);
t_list				*ft_lstnew(char character);
#endif
