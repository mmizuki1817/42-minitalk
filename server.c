/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:19:20 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/03 13:07:18 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

typedef struct s_msg{
	int	i;
	int	bit;
}	t_msg;

static void	handle_signal(int signal)
{
	static t_msg	msg;

	if (signal == SIGUSR1)
		msg.i |= (0x01 << msg.bit);
	msg.bit++;
	if (msg.bit == 8)
	{
		write(1, &msg.i, 1);
		msg.bit = 0;
		msg.i = 0;
	}
}

int	main(void)
{
	struct sigaction	act;
	pid_t				pid;

	pid = getpid();
	ft_printf("%i\n", (int)pid);
	sigemptyset(&act.sa_mask);
	act.sa_handler = handle_signal;
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
