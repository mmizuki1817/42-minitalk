/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:00:11 by mimatsub          #+#    #+#             */
/*   Updated: 2022/06/08 03:17:45 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (n == 0 || buf1 == buf2)
		return (buf1);
	s1 = (unsigned char *)buf1;
	s2 = (unsigned char *)buf2;
	while (n--)
	{
		*s1++ = *s2++;
	}
	return (buf1);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	printf("%s", (char *)ft_memcpy(NULL, NULL, 2)); //NULL
    printf("%s", memcpy(NULL, NULL, 2)); //NULL
}   
*/
