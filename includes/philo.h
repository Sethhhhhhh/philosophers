#ifndef PHILO_H
# define PHILO_H

/* Libs */
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>

/* Structures */

typedef struct s_args
{
	size_t		philo_n;
	size_t		eat_n;
	useconds_t	die_t;
	useconds_t	eat_t;
	useconds_t	sleep_t;
}				t_args;

typedef struct s_p
{
	t_args	args;
}				t_p;

/* Functions */

int		s_error(char *msg, int ret);

void	s_putstr_fd(char *str, int fd);
void	s_putchar_fd(char c, int fd);

int		parse(t_args *args, char **av, int ac);

#endif
