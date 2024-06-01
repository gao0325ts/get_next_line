/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:09:49 by stakada           #+#    #+#             */
/*   Updated: 2024/06/01 12:20:22 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t  len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

void	ft_strcpy_gnl(char *dst, char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}

void	ft_strncpy_gnl(char *dst, char *src, int n)
{
	while (n-- && *src)
		*dst++ = *src++;
	if (n >= 0)
		*dst = '\0';
}

char	*ft_strdup_gnl(char *src)
{
	char    *dst;
	int     len;

	len = ft_strlen_gnl(src);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst)
		ft_strcpy_gnl(dst, src);
	return (dst);
}
