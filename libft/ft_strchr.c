/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:52:14 by mimatsub          #+#    #+#             */
/*   Updated: 2022/01/30 18:52:14 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;
	size_t	len;

	tmp = (char *)s;
	len = ft_strlen(tmp) + 1;
	while (len-- > 0)
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp++;
	}
	return (NULL);
}
