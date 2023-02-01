/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 03:06:05 by mimatsub          #+#    #+#             */
/*   Updated: 2022/06/05 02:29:06 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*front(char *s, const char *set)
{
	while (*s != '\0' && ft_strchr(set, *s))
		s++;
	return (s);
}

static char	*end(char *s, const char *set)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(s);
	tmp = s + len - 1;
	while (len-- > 0 && ft_strchr(set, *tmp))
		tmp--;
	return (tmp);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp;
	char	*s;

	s = (char *)s1;
	if (!s || !set)
		return (NULL);
	s = front(s, set);
	if (!s)
		return (NULL);
	tmp = end(s, set);
	return (ft_substr(s, 0, tmp - s + 1));
}

/*
#include <stdio.h>
int main(void)
{
	char *s = "hello";
	printf("hell:%s\n", ft_strtrim(s, "o"));
	printf("hell:%s\n", strtrim(s, "o"));

	printf("hello:%s\n", ft_strtrim(s, "\0"));
	printf("hello:%s\n", strtrim(s, "\0"));

	printf("():%s\n", ft_strtrim("\0", "\0"));
	printf("():%s\n", strtrim("\0", "\0"));
}
*/