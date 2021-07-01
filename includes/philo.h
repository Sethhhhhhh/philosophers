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
	size_t		p_amount;
	size_t		eat_amount;
	useconds_t	time_to_die;
	useconds_t	time_to_eat;
	useconds_t	time_to_sleep;
}				t_args;

typedef struct s_p
{
	size_t			id;
	size_t			eating_count;
	int				is_eating;
	
	pthread_t		thread;
	pthread_mutex_t	right_fork;
}				t_p;

typedef struct s_s
{
	t_args	args;
	t_p		*p;

	pthread_t		thread;
	pthread_mutex_t	lock;
}				t_s;

/* Functions */

int		s_error(char *msg, int ret);

void	s_putstr_fd(char *str, int fd);
void	s_putchar_fd(char c, int fd);
long	s_atoi(const char *str);
void	s_bzero(void *s, size_t n);

int		init(t_s *s, char **av);

void	*tasks(void *s);

#endif
