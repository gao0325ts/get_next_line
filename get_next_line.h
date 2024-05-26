/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:50:50 by stakada           #+#    #+#             */
/*   Updated: 2024/05/26 18:08:04 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

// TODO 提出前に消す
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

// TODO 提出前に更新
char	*get_next_line(int fd);
char	*divide_string(char **s_str);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2, ssize_t s2_len);
char	*ft_substr_gnl(char *s, size_t len);
char	*ft_strdup(const char *s1);

#endif