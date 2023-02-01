/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:38:39 by mimatsub          #+#    #+#             */
/*   Updated: 2022/05/13 06:53:02 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (n == 0 || buf1 == buf2)
		return (buf1);
	s1 = (unsigned char *)buf1;
	s2 = (unsigned char *)buf2;
	if (s1 > s2)
	{
		while (n--)
			s1[n] = s2[n];
	}
	else
		ft_memcpy(buf1, buf2, n);
	return (buf1);
}
