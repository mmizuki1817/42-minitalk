/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:44:54 by mimatsub          #+#    #+#             */
/*   Updated: 2022/06/03 22:33:34 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	li;

	li = n;
	if (li < 0)
	{
		ft_putchar_fd('-', fd);
		li = li * (-1);
	}
	if (li < 10)
		ft_putchar_fd(li + '0', fd);
	else
	{
		ft_putnbr_fd(li / 10, fd);
		ft_putnbr_fd(li % 10, fd);
	}
}
