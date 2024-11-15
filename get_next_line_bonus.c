/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:28:29 by stakada           #+#    #+#             */
/*   Updated: 2024/11/15 21:22:35 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_line(char *s)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (!s[len])
		return (ft_strdup(s));
	line = (char *)malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_remain_str(char *s)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i] || (s[i] == '\n' && !s[i + 1]))
	{
		free(s);
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!new)
		return (NULL);
	j = 0;
	while (s[i + 1])
	{
		new[j] = s[i + 1];
		i++;
		j++;
	}
	new[j] = '\0';
	free(s);
	return (new);
}

static char	*read_and_store(int fd, char *store)
{
	char	*buf;
	ssize_t	bytes;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			free(store);
			return (NULL);
		}
		buf[bytes] = '\0';
		if (bytes == 0)
			break ;
		store = join_string(store, buf);
		if (ft_strchr(store, '\n'))
			break ;
	}
	free(buf);
	return (store);
}

static t_list	*find_current_fd(t_list **lst, int fd)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->store = NULL;
	new->next = *lst;
	*lst = new;
	return (new);
}

void	free_current_fd(t_list **lst, int fd)
{
	t_list	*current;
	t_list	*prev;

	if (!lst || !*lst)
		return ;
	current = *lst;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd)
		{
			if (prev)
				prev->next = current->next;
			else
				*lst = current->next;
			free(current->store);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	t_list			*current;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current = find_current_fd(&lst, fd);
	if (!current)
		return (NULL);
	current->store = read_and_store(fd, current->store);
	if (!current->store)
	{
		free_current_fd(&lst, fd);
		return (NULL);
	}
	line = get_line(current->store);
	current->store = get_remain_str(current->store);
	if (!current->store)
		free_current_fd(&lst, fd);
	return (line);
}
