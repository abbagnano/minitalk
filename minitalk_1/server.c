#include "minitalk.h"
//	t_read message;
	char	zero;
	//t_data data;

void *a;
void *b;
int x;

void	ft_usr1(int signo)
{
		printf("server recived signal from usr1 with signo:%d\n", signo);
	//exit(0);
	//pause();
	//sleep(5);
	//exit(0);
	printf("\tx:%d\n", x);
	char c;
	c = x;
	if (x == 1)
		exit(0);
	write(0, &c, 1);
	x = 0;
}


void	ft_usr2(int signo)
{
	printf("server recived signal from client usr2 with signo:%d\n", signo);
//	printf("mess: %s\n", message.line);
//	printf("zero: %s\n", zero);
	printf("x:%d\n", x);

	printf("a: %d\tb: %d\n", (int)a, (int)b);

	while (b == 0)
	{
		b = signal(SIGUSR2, ft_usr2);
			printf("while:x:%d\n", x);
			usleep(11);
		x++;
	}
//	kill(data.client_pid, SIGUSR2);
	//signal
	//exit(0);
	x++;
	
}

int	main()
{
	int	pid;


	

	//t_read *tmp;

//	message = (t_read **)malloc(sizeof(t_read *) * 1);
//	*message = NULL;
//	tmp = *message;
	pid = getpid();
//	data.server_pid = pid;
	ft_write_nbr(pid);
	write(0, "\n", 1);
	a = signal(SIGUSR1, ft_usr1);

	b = signal(SIGUSR2, ft_usr2);

//	printf("mess: %s\n", message.line);
	//printf("mess: %s\n", message->line);
// 	printf("%c\n", zero);
// 	printf("%p\n", &zero);
// //	kill(pid, SIGUSR1);
//	if (tmp)
//		printf("mess: %s\n", tmp->line);
	//sleep(900);
	pause();
	//free(zero);
//a	exit(0);

}	//printable ascii : 32 -> 126