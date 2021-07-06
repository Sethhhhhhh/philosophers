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

void	msg(t_s *s, size_t id, char type)
{
	pthread_mutex_lock(&(s->write_m));
	s_putnbr_fd(get_time() - s->timestamp, 1);
	s_putchar_fd(' ', 1);
	s_putnbr_fd((id + 1), 1);
	s_putstr_fd(get_msg_type(type), 1);
	pthread_mutex_unlock(&(s->write_m));
}
