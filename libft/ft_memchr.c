/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:52:57 by mimatsub          #+#    #+#             */
/*   Updated: 2022/05/11 01:33:29 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	unsigned char	*s;

	s = (unsigned char *)buf;
	while (n--)
	{
		if (*s == (unsigned char)ch)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
