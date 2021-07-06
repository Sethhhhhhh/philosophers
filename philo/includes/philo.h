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

	size_t			last_meal_time;
	size_t			count_meals;
	char			is_eating;
	char			must_eat_check;

	pthread_t		thread;
	pthread_mutex_t	fork;
	pthread_mutex_t	eat_m;
}				t_p;

typedef struct s_s
{
	size_t			id;

	size_t			amount;
	size_t			eat_amount;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;

	size_t			timestamp;

	t_p				*p;

	pthread_mutex_t	mutex;
	pthread_mutex_t	write_m;
	pthread_mutex_t	event_m;

	pthread_t		event;
}				t_s;

/*
**	Functions
*/

/* print */
void			msg(t_s *s, size_t id, char type);
char			*get_msg_type(char type);

/* utils */
void			s_putstr_fd(char *str, int fd);
void			s_putchar_fd(char c, int fd);
long			s_atoi(const char *str);
void			s_bzero(void *s, size_t n);
unsigned int	get_time(void);
void			s_putnbr_fd(unsigned long int u, int fd);
size_t			s_strlen(const char *str);

/* init */
char			init(t_s *s, char const **av, int ac);

/* tasks */
void			*tasks(void *s_v);

/* event */
void			*event(void *s_v);

#endif
