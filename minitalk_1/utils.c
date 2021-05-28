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
	int	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

void	ft_write(char	*s)
{
	int	x;

	x = 0;
	while (s[x])
		x++;
	write(0, s, x);
}

void	ft_write_nbr(int pid)
{
	char	c;

    if(pid / 10 != 0)
        ft_write_nbr(pid / 10);
	c = (pid % 10) + 48;
	write(0, &c, 1);
//	printf("pid: %d\n", pid);
}
