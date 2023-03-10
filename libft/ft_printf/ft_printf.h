/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:44:22 by mimatsub          #+#    #+#             */
/*   Updated: 2023/01/31 23:29:32 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

size_t	ft_putstr_fd_printf(char *s);

size_t	ft_putchar_fd_printf(int c);

size_t	ft_put_base(unsigned long long num, char c, int base, size_t count);

size_t	ft_treat_int(int i);

size_t	ft_treat_base(unsigned int num, char c);

size_t	ft_treat_point(unsigned long long p);

int		ft_printf(const char *input, ...);

#endif
