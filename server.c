#include "minitalk.h"

int		g_x = 0;
char	g_c;

void	ft_usr1(int signo)
{
	if (g_x)
	{
		g_c = g_x;
		g_x = 0;
		write(1, &g_c, 1);
	}
	else
	{
		(void)signo;
		write(1, "\n", 1);
		sleep(600);
	}
}

void	ft_usr2(int signo)
{
	g_x++;
	(void)signo;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_write_nbr(pid);
	write(0, "\n", 1);
	signal(SIGUSR1, ft_usr1);
	signal(SIGUSR2, ft_usr2);
	while (1)
		pause();
}	
