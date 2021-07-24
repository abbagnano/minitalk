/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:13:29 by fgradia           #+#    #+#             */
/*   Updated: 2021/05/28 17:13:33 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	tot;

	tot = 0;
	while (*str >= '0' && *str <= '9')
		tot = tot * 10 + *str++ - 48;
	return (tot);
}

void	ft_exit(char *s)
{
	int	y;

	y = 0;
	while (s[y])
		y++;
	write(1, s, y);
	exit(0);
}

void	ft_send_char(char c, int server_pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		usleep(5);
		if (c % 2)
			kill(server_pid, SIGUSR2);
		else if (c % 2 == 0)
			kill(server_pid, SIGUSR1);
		usleep(5);
		c /= 2;
		bit++;
	}
}

int	main(int ac, char **av)
{
	int		server_pid;
	int		x;

	x = 0;
	if (ac != 3)
		ft_exit("wrong args!\n");
	server_pid = ft_atoi(av[1]);
	while (av[2][x])
	{
		usleep(5);
		ft_send_char(av[2][x], server_pid);
		x++;
	}
	usleep(5);
	ft_send_char('\n', server_pid);
	exit(0);
}
