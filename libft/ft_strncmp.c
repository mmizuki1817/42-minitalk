/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:41:27 by mimatsub          #+#    #+#             */
/*   Updated: 2022/05/13 06:53:44 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*buf1;
	unsigned char	*buf2;

	buf1 = (unsigned char *)s1;
	buf2 = (unsigned char *)s2;
	while (n--)
	{
		if (*buf1 != *buf2 || *buf1 == '\0' || *buf2 == '\0')
			return (*buf1 - *buf2);
		buf1++;
		buf2++;
	}
	return (0);
}
