/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:19:47 by mimatsub          #+#    #+#             */
/*   Updated: 2022/05/30 21:20:32 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (c == '\0' || s[0] == '\0')
	{
		if (c == '\0' && s[0] == '\0')
			return (0);
		return (1);
	}
	while (s[i] == c)
		i++;
	if (s[i] != '\0')
		count++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static char	**m_free(char **p, size_t size)
{
	while (size--)
	{
		free(p[size]);
		p[size] = NULL;
	}
	free(p);
	p = NULL;
	return (NULL);
}

static char	**p_malloc(char **p, size_t size, size_t len)
{
	p[size] = (char *)malloc(sizeof(char) * (len + 1));
	if (!p[size])
		return (m_free(p, size));
	return (p);
}

static char	**split_cpy(char const *s, char c, char **p)
{
	size_t	len;
	size_t	size;

	size = 0;
	while (*s != '\0')
	{
		len = 0;
		while (*s != c && *s != '\0')
		{
			s++;
			len++;
		}
		if (len != 0)
		{
			p = p_malloc(p, size, len);
			if (p == NULL)
				return (NULL);
			ft_strlcpy(p[size++], s - len, len + 1);
		}
		while (*s == c && c != '\0')
			s++;
	}
	p[size] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**p;

	if (!s)
		return (NULL);
	count = count_word(s, c);
	p = (char **)malloc(sizeof(char *) * (count + 1));
	if (!p)
		return (NULL);
	return (split_cpy(s, c, p));
}

/*
#include <stdio.h>
int main(void)
{
	char *s = "\0aaa\0bbb";
	char **p = ft_split(s, '\0');
	printf("%s", *p);
	free(p);
	
}*/
