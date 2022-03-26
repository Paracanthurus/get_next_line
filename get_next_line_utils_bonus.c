/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokubo <aokubo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 02:02:04 by aokubo            #+#    #+#             */
/*   Updated: 2022/03/26 15:23:41 by aokubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

char	*ft_strchr_gnl(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	if (dstsize > 0)
	{
		while (src[len] != '\0' && len < dstsize - 1)
		{
			dst[len] = src[len];
			len++;
		}
		dst[len] = '\0';
	}
	while (src[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin_gnl(char *s1, char *s2, bool del1, bool del2)
{
	char	*str;
	size_t	len_1;
	size_t	len_2;

	str = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		len_1 = 0;
		while (s1[len_1] != '\0')
			len_1++;
		len_2 = 0;
		while (s2[len_2] != '\0')
			len_2++;
		str = (char *)malloc(sizeof(char) * (len_1 + len_2 + 1));
		if (str != NULL)
		{
			ft_strlcpy_gnl(str, s1, len_1 + len_2 + 1);
			ft_strlcpy_gnl(&str[len_1], s2, len_2 + 1);
		}
	}
	if (del1)
		free(s1);
	if (del2)
		free(s2);
	return (str);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size_s;

	if (s == NULL)
		return (NULL);
	size_s = 0;
	while (s[size_s] != '\0')
		size_s++;
	if (len > size_s || start > size_s - len)
	{
		if (start < size_s)
			len = size_s - start;
		else
			len = 0;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		free(s);
		return (NULL);
	}
	ft_strlcpy_gnl(str, &s[start], len + 1);
	free(s);
	return (str);
}
