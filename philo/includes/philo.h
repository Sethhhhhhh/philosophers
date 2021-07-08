#ifndef PHILO_H
# define PHILO_H

/*
**	Libs
*/

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>

/*
**	Defines
*/

# define TYPE_EAT 0
# define TYPE_SLEEP 1
# define TYPE_FORK 2
# define TYPE_THINK 3
# define TYPE_DIE 4
# define TYPE_OVER 5

/*
**	Structures
*/

typedef struct s_p
{
	size_t			id;
	size_t			last_eat_time;
	size_t			count_eat;

	char			is_eating;
	char			is_death;

	pthread_t		thread;
	pthread_mutex_t	fork;

	struct timeval	tv;
	struct s_s		*s;
}				t_p;

typedef struct s_s
{
	size_t			amount;
	size_t			eat_amount;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;

	char			someone_died;
	char			must_eat;

	pthread_mutex_t	write_m;

	pthread_t		event;

	struct timeval	tv;
	t_p				*p;
}				t_s;

/*
**	Functions
*/

/* print */
char			*get_msg_type(char type);
void			msg(t_p *p, char type);

/* utils */
void			s_putstr_fd(char *str, int fd);
void			s_putchar_fd(char c, int fd);
long			s_atoi(const char *str);
void			s_bzero(void *s, size_t n);
unsigned int	get_time(struct timeval *tv);
void			s_putnbr_fd(unsigned long int u, int fd);
size_t			s_strlen(const char *str);

/* init */
char			init(t_s *s, char const **av, int ac);

/* tasks */
void			*tasks(void *p_v);

/* event */
void			*event(void *s_v);

#endif
