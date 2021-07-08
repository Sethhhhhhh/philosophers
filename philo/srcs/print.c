#include "../includes/philo.h"

char	*get_msg_type(char type)
{
	if (type == TYPE_EAT)
		return (" is eating\n");
	else if (type == TYPE_SLEEP)
		return (" is sleeping\n");
	else if (type == TYPE_FORK)
		return (" has taken a fork\n");
	else if (type == TYPE_THINK)
		return (" is thinking\n");
	else if (type == TYPE_DIE)
		return (" died\n");
	else if (type == TYPE_OVER)
		return ("All the philosophers had eat enough.\n");
}

void	msg(t_p *p, char type)
{
    pthread_mutex_lock(&(p->s->write_m));
	if (p->s->someone_died)
	{
		pthread_mutex_unlock(&(p->s->write_m));
		return ;
	}
	s_putnbr_fd(get_time(&(p->tv)) - p->s->start_time, 1);
	s_putchar_fd(' ', 1);
	s_putnbr_fd((p->id + 1), 1);
	s_putstr_fd(get_msg_type(type), 1);
	pthread_mutex_unlock(&(p->s->write_m));
}
