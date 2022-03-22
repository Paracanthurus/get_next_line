/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:35:36 by aokubo            #+#    #+#             */
/*   Updated: 2022/03/16 17:36:01 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include<unistd.h>
# include<stdlib.h>
# include<stdbool.h>

char	*get_next_line(int fd);
char	*ft_strchr_gnl(const char *s, int c);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin_gnl(char *s1, char *s2, bool del1, bool del2);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*ft_read_file_gnl(char *pre_str, int fd);

#endif
