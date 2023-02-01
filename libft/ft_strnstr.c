/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:52:32 by mimatsub          #+#    #+#             */
/*   Updated: 2022/06/06 04:04:14 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;
	size_t	len_big;

	if (!big && little && len == 0)
		return (NULL);
	len_big = ft_strlen(big);
	len_little = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	if (len == 0 || len_big < len_little)
		return (NULL);
	while (*big && len >= len_little)
	{
		if (ft_strncmp(big, little, len_little) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}

/*
#include <stdio.h>
int main(void)
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";

	// printf("%s\n", ft_strnstr(haystack, "a", -1));
	// printf("%s\n", ft_strnstr(haystack, "c", -1));
	// printf("%s\n", ft_strnstr(haystack, "aaabc", 5));
	// printf("%s\n", ft_strnstr(haystack, "abcd", 9));
	// printf("%s\n", ft_strnstr(haystack, "a", 1));

	//printf("%sa", ft_strnstr(NULL, "he", 1)); //segfa
	// printf("%sb", strnstr(NULL, "he", 1)); //segfa

	// printf("%sc", ft_strnstr(NULL, "he", 0)); //null
	// printf("%sd", strnstr(NULL, "he", 0)); //null

	//printf("%se", ft_strnstr("he", NULL, 2)); //segfa
	// printf("%sf", strnstr("he", NULL, 2)); //segfa


	// printf("%se", ft_strnstr("he", NULL, 5)); //segfa
	// printf("%sf", strnstr("he", NULL, 5)); //segfa

	// printf("%sg", ft_strnstr("he", NULL, 0)); //segfa
	// printf("%sh", strnstr("he", NULL, 0)); //segfa

	// printf("%si", ft_strnstr(NULL, NULL, 5)); //segfa
	// printf("%sj", strnstr(NULL, NULL, 5)); //segfa


	// printf("%sk", ft_strnstr(NULL, NULL, 0)); //segfa
	// printf("%sl", strnstr(NULL, NULL, 0)); //segfa
}
*/