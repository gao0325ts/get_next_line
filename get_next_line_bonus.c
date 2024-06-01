/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:37:44 by stakada           #+#    #+#             */
/*   Updated: 2024/06/01 17:17:46 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	find_nl(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*join_read(char *store, char *buf)
{
	char	*res;
	size_t	store_len;
	size_t	buf_len;

	store_len = ft_strlen_gnl(store);
	buf_len = ft_strlen_gnl(buf);
	res = (char *)malloc(sizeof(char) * (store_len + buf_len + 1));
	if (!res)
		return (NULL);
	if (store)
	{
		ft_strcpy_gnl(res, store);
		free(store);
	}
	if (buf)
		ft_strcpy_gnl(&res[store_len], buf);
	return (res);
}

char	*divide_string(char **store)
{
	char	*output;
	char	*new_store;
	ssize_t	nl;
	size_t	len;

	nl = find_nl(*store);
	if (nl == -1)
		len = ft_strlen_gnl(*store);
	else
		len = nl + 1;
	output = (char *)malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	ft_strncpy_gnl(output, *store, len);
	if (nl != -1)
		new_store = ft_strdup_gnl(&(*store)[nl + 1]);
	free(*store);
	*store = NULL;
	if (nl != -1)
		*store = new_store;
	return (output);
}

char	*get_next_line(int fd)
{
	static char	*store[OPEN_MAX];
	char		*buf;
	ssize_t		bytes;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buf[bytes] = '\0';
		store[fd] = join_read(store[fd], buf);
		if (find_nl(store[fd]) >= 0)
			break ;
	}
	free(buf);
	if (bytes < 0 || !store[fd] || !*store[fd])
		return (free(store[fd]), store[fd] = NULL, NULL);
	return (divide_string(&store[fd]));
}
