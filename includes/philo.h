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

typedef struct s_p
{
	size_t		id;

	int				is_eating;
	int				is_death;
	unsigned int	eat_time;

	pthread_t		thread;
	pthread_mutex_t	fork;
}				t_p;

typedef struct s_sys
{
	size_t			id;

	size_t			philo_amount;
	size_t			eat_amount;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;

	unsigned int	start_time;

	t_p				*p;
	pthread_mutex_t	lock;
}				t_sys;

/* Functions */

int		s_error(char *msg, int ret);
void	print_config(t_sys *sys);

void	s_putstr_fd(char *str, int fd);
void	s_putchar_fd(char c, int fd);
long	s_atoi(const char *str);
void	s_bzero(void *s, size_t n);

int		init(t_sys *sys, char const **av, int ac);

#endif
