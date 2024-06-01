/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:53:15 by stakada           #+#    #+#             */
/*   Updated: 2024/06/01 16:02:40 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	len;

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

void	ft_strncpy_gnl(char *dst, char *src, size_t n)
{
	while (n-- && *src)
		*dst++ = *src++;
	*dst = '\0';
}

char	*ft_strdup_gnl(char *src)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * (ft_strlen_gnl(src) + 1));
	if (!new)
		return (NULL);
	ft_strcpy_gnl(new, src);
	return (new);
}
