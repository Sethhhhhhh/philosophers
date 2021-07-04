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

#define TYPE_EAT 0
#define TYPE_SLEEP 1
#define TYPE_FORK 2
#define TYPE_THINK 3
#define TYPE_DIE 4
#define TYPE_OVER 5

/*
**	Structures
*/

typedef struct s_p
{
	size_t		id;

	int				is_eating;
	int				is_death;
	unsigned int	eat_time;

	pthread_t		thread;
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
	pthread_mutex_t	*forks;
}				t_sys;

/*
**	Functions
*/

/* print */
int				s_error(char *msg, int ret);
void			print_config(t_sys *sys);
char			*get_msg_type(int type);
void			msg(t_sys *sys, size_t id, int type);

/* utils */
void			s_putstr_fd(char *str, int fd);
void			s_putchar_fd(char c, int fd);
long			s_atoi(const char *str);
void			s_bzero(void *s, size_t n);
unsigned int	get_time(void);
void    		s_putnbr_fd(unsigned long int u, int fd);

/* init */
int				init(t_sys *sys, char const **av, int ac);

/* tasks */
void    		*tasks(void *sys_v);

#endif
