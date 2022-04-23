/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:06:50 by aokubo            #+#    #+#             */
/*   Updated: 2022/04/24 05:05:22 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*get_next_line(int fd)
{
	char		*str;
	static char	*pre_str;
	char		*ptr_n;

	if (pre_str == NULL)
		pre_str = ft_strjoin_gnl("", "", false, false);
	pre_str = ft_read_file_gnl(pre_str, fd);
	str = ft_strjoin_gnl(pre_str, "", true, false);
	ptr_n = ft_strchr_gnl(str, '\n');
	if (ptr_n != NULL)
	{
		pre_str = ft_strjoin_gnl(ptr_n + 1, "", false, false);
		str = ft_substr_gnl(str, 0, ptr_n - str + 1);
	}
	else
		pre_str = NULL;
	return (str);
}

char	*ft_read_file_gnl(char *pre_str, int fd)
{
	ssize_t	read_size;
	char	*str_read;

	read_size = (size_t)BUFFER_SIZE;
	while (ft_strchr_gnl(pre_str, '\n') == NULL && read_size > 0)
	{
		str_read = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
		if (str_read != NULL)
			str_read[0] = '\0';
		read_size = read(fd, str_read, (size_t)BUFFER_SIZE);
		if (read_size != -1)
			str_read[read_size] = '\0';
		pre_str = ft_strjoin_gnl(pre_str, str_read, true, true);
		if (pre_str == NULL || pre_str[0] == '\0')
		{
			free(pre_str);
			return (NULL);
		}
	}
	return (pre_str);
}
