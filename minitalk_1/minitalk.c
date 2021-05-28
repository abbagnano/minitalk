#include "minitalk.h"
/*
void stampa(int signo)
{
	printf("sono stato risvegliato!!\n");
	printf("signo: %d\n", signo);
}

int main()
{ 
	int k;
	signal(SIGUSR1, stampa);
	k=sleep(100);
	printf("Valore di k: %d\n", k);
	exit(0);
}
*/
/*
void handler(int signo)
{ 
	printf ("Proc. %d: segnali %d\n", getpid(), signo);
}

int main ()
{
	
	signal(SIGUSR1, handler);
}*/

int main ()
{
	int i = 0;
	while (errno)
		printf("%d\n", errno);
}