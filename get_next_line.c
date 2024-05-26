/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:50:30 by stakada           #+#    #+#             */
/*   Updated: 2024/05/26 19:04:12 by stakada          ###   ########.fr       */
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
			return (1);
		i++;
	}
	return (0);
}

char	*join_read(char *s1, char *s2, ssize_t s2_len)
{
	char	*res;
	char	*res_start;
    ssize_t	len;

	// res = NULL;
    len = s2_len + 1;
    if (s1)
        len += ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * len);
	res_start = res;
	while (s1 && *s1)
		*res++ = *s1++;
	while (*s2)
		*res++ = *s2++;
	*res = '\0';
	return (res_start);
}

char	*output_str(char *readstr)
{
	char	*output;
	int		i;

	i = 0;
	if (!readstr)
		return (NULL);
    while (readstr[i] && readstr[i] != '\n')
        i++;
	output = (char *)malloc(sizeof(char) * (ft_strlen(readstr) + 2));
	if (!output)
	{
		free(output);
		return (NULL);
	}
    
	output[i] = '\0';
	return (output);
}

char	*substr_gnl(char *str, int nl)
{
	char	*res;
	int		i;

	// char *start;
	i = 0;
	if (!str || nl <= 0)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!res)
	{
		free(res);
		return (NULL);
	}
	// start = res;
	while (str[nl + i + 1])
	{
		res[i] = str[nl + i + 1];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char *store;
	char *buf = NULL;
	char *readstr = NULL;
	char *line = NULL;
	// int nl = 0;
	ssize_t len = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (store)
	{
		readstr = ft_strdup(store);
		free(store);
	}
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
	{
		free(buf);
		return (NULL);
	}
	while (1)
	{
		len = read(fd, buf, BUFFER_SIZE);
		// buf[BUFFER_SIZE] = '\0';
		if (len == -1)
		{
			free(buf);
			return (NULL);
		}
		if (len == 0)
			break ;
		readstr = join_read(readstr, buf, len);
		if (!readstr)
		{
			free(readstr);
			return (NULL);
		}
		// nl = find_nl(readstr);
		// if (nl >= 0)
		// 	break ;
        if (find_nl(readstr))
            break ;
	}
	free(buf);
	if (len == 0 && !readstr)
	{
		free(readstr);
		return (NULL);
	}
	line = output_str(readstr);
	store = substr_gnl(readstr);
	free(readstr);
	return (line);
}
