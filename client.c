#include "minitalk.h"

void	ft_send_char(int y, int server_pid)
{
	while (y)
	{
		usleep(3);
		kill(server_pid, SIGUSR2);
		usleep(3);
		y--;
	}
}

int	main(int ac, char **av)
{
	int		server_pid;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (ac != 3)
		ft_exit("wrong args!\n");
	server_pid = ft_atoi(av[1]);
	while (av[2][x])
	{
		y = (int)av[2][x];
		ft_send_char(y, server_pid);
		usleep(3);
		kill(server_pid, SIGUSR1);
		usleep(3);
		x++;
	}
	usleep(1);
	kill(server_pid, SIGUSR1);
	exit(0);
}
