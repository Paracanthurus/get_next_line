/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:06:50 by aokubo            #+#    #+#             */
/*   Updated: 2022/04/24 05:04:31 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char				*str;
	static t_list_gnl	*lst;
	t_list_gnl			*lst_fd;
	char				*ptr_n;

	if (lst == NULL)
		lst = ft_lstnew_gnl(fd, ft_strjoin_gnl("", "", false, false));
	lst_fd = ft_lstfd_gnl(lst, fd);
	if (ft_read_file_gnl(lst_fd, &lst) == -1)
		return (NULL);
	str = ft_strjoin_gnl(lst_fd->content, "", true, false);
	ptr_n = ft_strchr_gnl(str, '\n');
	if (ptr_n != NULL)
	{
		lst_fd->content = ft_strjoin_gnl(ptr_n + 1, "", false, false);
		str = ft_substr_gnl(str, 0, ptr_n - str + 1);
	}
	else
		lst_fd->content = NULL;
	return (str);
}

t_list_gnl	*ft_lstfd_gnl(t_list_gnl *lst, int fd)
{
	t_list_gnl	*new_lst;

	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (lst->fd == fd)
			return (lst);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	new_lst = ft_lstnew_gnl(fd, ft_strjoin_gnl("", "", false, false));
	if (new_lst == NULL)
		return (NULL);
	lst->next = new_lst;
	new_lst->prev = lst;
	return (new_lst);
}

ssize_t	ft_read_file_gnl(t_list_gnl *lst_fd, t_list_gnl **lst)
{
	ssize_t	read_size;
	char	*str_read;

	if (lst_fd == NULL)
		return (-1);
	read_size = (size_t)BUFFER_SIZE;
	while (ft_strchr_gnl(lst_fd->content, '\n') == NULL && read_size > 0)
	{
		str_read = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
		if (str_read != NULL)
			str_read[0] = '\0';
		read_size = read(lst_fd->fd, str_read, (size_t)BUFFER_SIZE);
		if (read_size != -1)
			str_read[read_size] = '\0';
		lst_fd->content = ft_strjoin_gnl(lst_fd->content, str_read, true, true);
		if (lst_fd->content == NULL || lst_fd->content[0] == '\0')
		{
			ft_lstdel_gnl(lst_fd, lst);
			return (-1);
		}
	}
	return (read_size);
}

t_list_gnl	*ft_lstnew_gnl(int fd, void *content)
{
	t_list_gnl	*new_lst;

	new_lst = (t_list_gnl *)malloc(sizeof(t_list_gnl));
	if (new_lst == NULL)
	{
		free(content);
		return (NULL);
	}
	new_lst->fd = fd;
	new_lst->content = content;
	new_lst->next = NULL;
	new_lst->prev = NULL;
	return (new_lst);
}

void	ft_lstdel_gnl(t_list_gnl *lst, t_list_gnl **lst_begin)
{
	t_list_gnl	*next_lst;
	t_list_gnl	*prev_lst;

	if (lst == NULL)
		return ;
	next_lst = lst->next;
	prev_lst = lst->prev;
	free(lst->content);
	free(lst);
	if (next_lst != NULL)
		next_lst->prev = prev_lst;
	if (prev_lst != NULL)
		prev_lst->next = next_lst;
	else
		*lst_begin = next_lst;
}
