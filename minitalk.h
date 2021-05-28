#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(char *str);
int		ft_strlen(char *s);
void	ft_exit(char *s);
void	ft_write_nbr(int pid);

#endif
