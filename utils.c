#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	tot;

	tot = 0;
	while (*str >= '0' && *str <= '9')
		tot = tot * 10 + *str++ - 48;
	return (tot);
}

int	ft_strlen(char *s)
{
	int	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

void	ft_exit(char *s)
{
	int	y;

	y = 0;
	while (s[y])
		y++;
	write(0, s, y);
	exit(0);
}

void	ft_write_nbr(int pid)
{
	char	q;

	if (pid / 10 != 0)
		ft_write_nbr(pid / 10);
	q = (pid % 10) + 48;
	write(0, &q, 1);
}
