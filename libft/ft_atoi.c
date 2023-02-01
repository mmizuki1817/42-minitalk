/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:53:06 by mimatsub          #+#    #+#             */
/*   Updated: 2022/06/04 05:51:09 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	calculate(const char *str, char pn)
{
	long long	num;

	num = 0;
	while (ft_isdigit(*str))
	{
		if (pn == '+' && \
		(num > LLONG_MAX / 10 || ((*str - '0') > 7 && num == LLONG_MAX / 10)))
			return ((int)LONG_MAX);
		else if (pn == '-' && \
		(num > LLONG_MAX / 10 || ((*str - '0') > 8 && num == LLONG_MAX / 10)))
			return ((int)LONG_MIN);
		num = num * 10 + (*str - '0');
		str++;
	}
	if (pn == '-')
		num = num * (-1);
	return ((int)num);
}

int	ft_atoi(const char *str)
{
	long	num;
	char	pn;

	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	pn = '+';
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			pn = '-';
		str++;
	}
	while (*str == '0')
		str++;
	num = calculate(str, pn);
	return ((int)num);
}

/*
// LONG_MAX = +9,223,372,036,854,775,807	
// LONG_MIN = –9,223,372,036,854,775,808

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *str = "    --+--+214748364ab567";
	printf("0:%i\n", atoi(str));
	printf("0:%i\n", ft_atoi(str));

	//max
	char *s = "    +2147483647ab567";
	printf("1:%i\n", atoi(s));
	printf("1:%i\n", ft_atoi(s));

	// max 以上
	char *ss = "    +214748364712ab567";
	printf("1:%i\n", atoi(ss));
	printf("1:%i\n", ft_atoi(ss));
	
	// min
	char *s1 = " \t \n \v \f \r -2147483648";
	printf("2:%i\n", atoi(s1));
	printf("2:%i\n", ft_atoi(s1));

	// min + 1
	char *s2 = "-2147483647";
	printf("3:%i\n", atoi(s2));
	printf("3:%i\n", ft_atoi(s2));

	char *s3 = "-013 3";
	printf("4:%i\n", atoi(s3));
	printf("4:%i\n", ft_atoi(s3));

	char *s4 = "0";
	printf("5:%i\n", atoi(s4));
	printf("5:%i\n", ft_atoi(s4));

	char *s5 = "a ";
	printf("6:%i\n", atoi(s5));
	printf("6:%i\n", ft_atoi(s5));

	char *s6 = "  -a2";
	printf("7:%i\n", atoi(s6));
	printf("7:%i\n", ft_atoi(s6));

	char *s7 = " 3.54";
	printf("8:%i\n", atoi(s7));
	printf("8:%i\n", ft_atoi(s7));

	char *s8 = " - 3.54";
	printf("9:%i\n", atoi(s8));
	printf("9:%i\n", ft_atoi(s8));

	char *s9 = " -0019";
	printf("10:%i\n", atoi(s9));
	printf("10:%i\n", ft_atoi(s9));
}
*/
