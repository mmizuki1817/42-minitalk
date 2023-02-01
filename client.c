/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:20:40 by mimatsub          #+#    #+#             */
/*   Updated: 2023/01/31 23:40:30 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

/*void	send_eot(pid_t pid)
{
	int	count;

	count = 0;
	while (count < 8)
	{
		usleep(50);
		if (count == 2)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		count++;
	}
}*/

void	send_string(pid_t pid, char *s)
{
	int					bit; //0~8
	unsigned long long	j;

	bit = 0;
	j = 0;
	while (s[j] != '\0')
	{
		usleep(50);
		if ((s[j] >> bit & 0x01) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		if (bit == 8)
		{
			j++;
			bit = 0;
		}
	}
	//send_eot(pid);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (argc != 3 || !ft_strlen(argv[2])) //error //2つ目の条件必要？他にもエラー条件ある？
	{
		ft_printf("missing command-line argment");
		exit (1);
	}
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (ft_isdigit(argv[1][i]) == 0)
		{
			ft_printf("invalid pid, put integer");
			exit (1);
		}
		i++;
	}
	pid = (pid_t)atoi(argv[1]); //pidを数値に
	/*
	pid=0; for i in {1..100000}; do; :&  if [ $! -lt $pid ]; then; echo "Min pid: $! " ; echo "Max pid: $pid"; break; fi; pid=$!; done
	=>Min=100, Max=99998 @Guacamole
	*/
	if (pid < 100 || pid > 99998)
	{
		ft_printf("invalid pid");
		exit(1);
	}
	send_string(pid, argv[2]);
	return (EXIT_SUCCESS);
}
