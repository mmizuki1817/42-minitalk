/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:58:33 by mimatsub          #+#    #+#             */
/*   Updated: 2022/05/11 01:36:09 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int ch, size_t n)
{
	unsigned char	*buf;

	buf = (unsigned char *)s;
	while (n--)
		*buf++ = (unsigned char)ch;
	return (s);
}
