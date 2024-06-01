/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:50:30 by stakada           #+#    #+#             */
/*   Updated: 2024/06/01 12:30:32 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_nl(char *str)
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

char	*join_read(char *s1, char *s2)
{
	char	*res;
	int		len1;
	int		len2;

	len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	if (s1)
	{
		ft_strcpy_gnl(res, s1);
		free(s1);
	}
	if (s2)
		ft_strcpy_gnl(res + len1, s2);
	res[len1 + len2] = '\0';
	return (res);
}

char	*divide_string(char **store)
{
	char	*output;
	char	*new_store;
	int		nl;
	int		len;

	nl = find_nl(*store);
	if (nl == -1)
		len = ft_strlen_gnl(*store);
	else
		len = nl;
	output = (char *)malloc(sizeof(char) * (len + 2));
	if (!output)
		return (NULL);
	ft_strncpy_gnl(output, *store, len + 1);
	output[len + 1] = '\0';
	if (nl != -1)
		new_store = ft_strdup_gnl(*store + nl + 1);
	free(*store);
	if (nl == -1)
		*store = NULL;
	else
		*store = new_store;
	return (output);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*buf;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(store), store = NULL, NULL);
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
	if (bytes < 0 || (bytes == 0 && (!store || !*store)))
		return (free(store), store = NULL, NULL);
	return (divide_string(&store));
}

// TODO size_tで返ってきたlenをintで渡しているところ修正
// TODO divide_string : str?cpyにまとめる→strlcpy?