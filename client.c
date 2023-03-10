/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:20:40 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/03 13:09:29 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

static void	error_print(char *s)
{
	ft_printf("%s", s);
	exit(1);
}

static void	send_string(pid_t pid, char *s)
{
	int					bit;
	unsigned long long	j;

	bit = 0;
	j = 0;
	while (s[j] != '\0')
	{
		usleep(50);
		if ((s[j] >> bit & 0x01) == 1)
		{
			if (kill(pid, SIGUSR1) < 0)
				error_print("kill error\n");
		}	
		else
		{
			if (kill(pid, SIGUSR2) < 0)
				error_print("kill error\n");
		}
		bit++;
		if (bit == 8)
		{
			j++;
			bit = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (argc != 3 || !ft_strlen(argv[2]))
		error_print("missing command-line argment\n");
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (ft_isdigit(argv[1][i]) == 0)
			error_print("invalid pid, put posositive integer\n");
		i++;
	}
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid < 1)
		error_print("invalid pid\n");
	send_string(pid, argv[2]);
	return (EXIT_SUCCESS);
}
