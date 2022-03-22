/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:35:36 by aokubo            #+#    #+#             */
/*   Updated: 2022/03/16 17:43:44 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include<unistd.h>
# include<stdlib.h>
# include<stdbool.h>

typedef struct s_list_gnl
{
	int					fd;
	char				*content;
	struct s_list_gnl	*next;
	struct s_list_gnl	*prev;
}	t_list_gnl;

char		*get_next_line(int fd);
char		*ft_strchr_gnl(const char *s, int c);
size_t		ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin_gnl(char *s1, char *s2, bool del1, bool del2);
char		*ft_substr_gnl(char *s, unsigned int start, size_t len);
t_list_gnl	*ft_lstnew_gnl(int fd, void *content);
t_list_gnl	*ft_lstfd_gnl(t_list_gnl *lst, int fd);
void		ft_lstdel_gnl(t_list_gnl *lst, t_list_gnl **lst_begin);
ssize_t		ft_read_file_gnl(t_list_gnl *lst_fd, t_list_gnl **lst);

#endif
