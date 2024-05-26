/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:53:15 by stakada           #+#    #+#             */
/*   Updated: 2024/05/26 17:22:09 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2, ssize_t s2_len)
{
	char	*res;
	char	*start;
	ssize_t	len;

	len = s2_len;
	if (s1)
		len += ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	start = res;
	while (s1 && *s1)
		*res++ = *s1++;
	while (*s2)
		*res++ = *s2++;
	*res = '\0';
	return (start);
}

char	*ft_substr_gnl(char *s, size_t len)
{
	char	*res;
	char	*res_start;

	res = (char *)malloc(sizeof(char) * (len + 2));
	if (!res)
		return (NULL);
	res_start = res;
	while (*s && *s != '\n')
		*res++ = *s++;
	*res++ = '\n';
	*res = '\0';
	return (res_start);
}

char	*ft_strdup(const char *s1)
{
	char *start;
	char *new_str;

	new_str = (char *)malloc(ft_strlen(s1) + 1);
	if (!new_str)
		return (NULL);
	start = new_str;
	while (*s1)
		*new_str++ = *s1++;
	*new_str = '\0';
	return (start);
}