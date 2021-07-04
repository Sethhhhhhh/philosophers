#include "../includes/philo.h"

int	s_error(char *msg, int ret)
{
	s_putstr_fd(msg, 2);
	return (ret);
}

char	*get_msg_type(int type)
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

void	msg(t_sys *sys, size_t id, int type)
{
	pthread_mutex_lock(&(sys->lock));
	s_putnbr_fd((get_time() - sys->start_time), 1);
	s_putchar_fd(' ', 1);
	s_putnbr_fd((id), 1);
	s_putstr_fd(get_msg_type(type), 1);
	pthread_mutex_unlock(&(sys->lock));
}

void	print_config(t_sys *sys)
{
	printf("\n----------- CONFIG -----------\n");
	printf("number of philosophers: %zu\n", sys->philo_amount);
	printf("time to die: %u\n", sys->time_to_die);
	printf("time to eat: %u\n", sys->time_to_eat);
	printf("time to sleep: %u\n", sys->time_to_sleep);
	if (sys->eat_amount > 0)
		printf("number of times each philosopher must eat: %zu\n", sys->eat_amount);
	printf("------------------------------\n\n");
}
