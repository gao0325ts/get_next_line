/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:38:35 by stakada           #+#    #+#             */
/*   Updated: 2024/06/01 12:16:56 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

// TODO 提出前に更新
char	*get_next_line(int fd);
int		find_nl(char *str);
char	*join_read(char *s1, char *s2);
char	*divide_string(char **store);
size_t	ft_strlen_gnl(const char *s);
void	ft_strcpy_gnl(char *dst, char *src);
void	ft_strncpy_gnl(char *dst, char *src, int n);
char	*ft_strdup_gnl(char *src);

#endif