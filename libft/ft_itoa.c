/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:59:15 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/01 22:48:55 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(long long n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count++;
		n = n * (-1);
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*buffer;
	int			count;
	long long	li;

	li = (long long)n;
	count = count_digit(li);
	buffer = (char *)malloc(sizeof(char) * (count + 1));
	if (buffer == NULL)
		return (NULL);
	buffer[count--] = '\0';
	if (n < 0)
	{
		li = li * (-1);
		buffer[0] = '-';
	}
	if (li == 0)
		buffer[0] = '0';
	while (li > 0)
	{
		buffer[count--] = (char)((li % 10) + '0');
		li = li / 10;
	}
	return (buffer);
}
