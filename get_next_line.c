/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:50:30 by stakada           #+#    #+#             */
/*   Updated: 2024/06/01 15:42:22 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	find_nl(char *str)
{
	int	i;

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
	static char	*store;
	char		*buf;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
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
		store = join_read(store, buf);
		if (find_nl(store) >= 0)
			break ;
	}
	free(buf);
	if (bytes < 0 || !store || !*store)
		return (free(store), store = NULL, NULL);
	return (divide_string(&store));
}
