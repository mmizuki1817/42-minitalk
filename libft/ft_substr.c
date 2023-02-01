/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:26:52 by mimatsub          #+#    #+#             */
/*   Updated: 2022/06/05 02:29:24 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	s_len;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start + 1)
		return (ft_strdup(""));
	while (start-- > 0)
		s++;
	s_len = ft_strlen(s);
	if (s_len <= len)
		return (ft_strdup(s));
	else
	{
		p = (char *)malloc(sizeof(char) * (len + 1));
		if (p == NULL)
			return (NULL);
		ft_strlcpy(p, s, (len + 1));
	}
	return (p);
}

/*
#include <stdio.h>
int main(void)
{
	char *s = "123456";
	printf("(null):%s\n", ft_substr(s, 100, 200));
	printf("malloc 6, 23456:%s\n", ft_substr(s, 1, 100));
	printf("malloc 2, 23:%s\n", ft_substr(s, 1, 2));
}
*/