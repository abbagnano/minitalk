#include "minitalk.h"

//	t_read message;
	//char	zero;
	
/*
void	ft_save_message(char *str, t_read **head)
{
	t_read	*new;
	t_read	*tmp;

	new = (t_read *)malloc(sizeof(t_read) * 1);
	new->line = str;
	new->next = NULL;
	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp)
		tmp = tmp->next;
	tmp = new;
}
*/



int	main(int ac, char **av)
{
	int		server_pid;
	int x = 0;
	int y = 0;

	if (ac != 3)
	{
		ft_write("wrong args!\n");
		exit (0);
	}
//	data.client_pid = getpid();
	server_pid = ft_atoi(av[1]);
	// printf("%c\n", zero);
	// printf("%p\n", &zero);
//	zero = (char *)malloc(sizeof(char) * (ft_strlen(av[2]) + 1));
	while (av[2][x])
	{
		y = (int)av[2][x];
		printf("c: %c\tc_int: %d\ty: %d\n", av[2][x], av[2][x], y );
		while (y)
		{
			usleep(10);
			kill(server_pid, SIGUSR2);
			y--;
		}
		kill(server_pid, SIGUSR1);	
	 	x++;
	 }
	 kill(server_pid, SIGUSR2);
	 kill(server_pid, SIGUSR1);
	//zero = av[2];
//	message.line = av[2];
//	message.next = NULL;
//	ft_save_message(av[2], message);
//	signal(SIGUSR2, ft_mess_ric);
//	while (*av[2])
//	{
//		zero = *av[2];
//		kill(server_pid, SIGUSR2);
//	}
//	sleep(900);
	
	exit(0);
}