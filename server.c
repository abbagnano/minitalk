/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:13:50 by fgradia           #+#    #+#             */
/*   Updated: 2021/05/28 17:13:52 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_byte	g_byte;

void	ft_write_nbr(int pid)
{
	char	q;

	if (pid / 10 != 0)
		ft_write_nbr(pid / 10);
	q = (pid % 10) + 48;
	write(1, &q, 1);
}

void	ft_usr(int signo)
{
	if (signo == SIGUSR2)
		g_byte.c |= (1 << g_byte.bit);
	else if (signo == SIGUSR1)
		g_byte.c |= (0 << g_byte.bit);
	g_byte.bit++;
	if (g_byte.bit == 8)
	{
		write(1, &g_byte.c, 1);
		g_byte.bit = 0;
		g_byte.c = '\0';
	}
}

int	main(void)
{
	int	pid;

	g_byte.bit = 0;
	g_byte.c = '\0';
	pid = getpid();
	ft_write_nbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, ft_usr);
	signal(SIGUSR2, ft_usr);
	while (1)
		pause();
}	
