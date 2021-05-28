#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>


/*
typedef struct s_read
{
	char			*line;
	struct s_read	*next;
}	t_read;
*/
/*
typedef struct s_data
{
	int		server_pid;
	int		client_pid;
	char	*mess;
}	t_data;

*/
//extern t_read message;
/*
extern t_data data;
t_data data;
*/

extern char zero;
//const char *zero;
//char zero = '_';
/*	utils.c		*/
int		ft_atoi(char *str);
int		ft_strlen(char *s);
void	ft_write(char	*s);
void	ft_write_nbr(int pid);

#endif
