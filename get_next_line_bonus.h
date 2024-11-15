/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:25:44 by stakada           #+#    #+#             */
/*   Updated: 2024/11/15 20:19:53 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

typedef struct s_list
{
	int				fd;
	char			*store;
	struct s_list	*next;
}					t_list;

# include <stdlib.h>
# include <unistd.h>

char				*get_next_line(int fd);
char				*join_string(char *s1, char *s2);
char				*ft_strdup(char *s);
size_t				ft_strlen(char *s);
char				*ft_strchr(const char *s, int c);

#endif