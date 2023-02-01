/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:49:24 by mimatsub          #+#    #+#             */
/*   Updated: 2022/06/05 02:30:19 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

int		ft_isalpha(int ch);

int		ft_isdigit(int ch);

int		ft_isalnum(int ch);

int		ft_isascii(int ch);

int		ft_isprint(int ch);

size_t	ft_strlen(const char *s);

void	*ft_memset(void *s, int ch, size_t n);

void	ft_bzero(void *s, size_t n);

void	*ft_memcpy(void *buf1, const void *buf2, size_t n);

void	*ft_memmove(void *buf1, const void *buf2, size_t n);

size_t	ft_strlcpy(char *dst, const char *src, size_t n);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

int		ft_toupper(int c);

int		ft_tolower(int c);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

void	*ft_memchr(const void *buf, int ch, size_t n);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		ft_memcmp(const void *buf1, const void *buf2, size_t n);

char	*ft_strnstr(const char *big, const char *little, size_t len);

int		ft_atoi(const char *str);

void	*ft_calloc(size_t n, size_t size);

char	*ft_strdup(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strtrim(char const *s1, char const *set);

char	**ft_split(char const *s, char c);

char	*ft_itoa(int n);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

#endif
