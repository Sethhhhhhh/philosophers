#include "../includes/philo.h"

int	s_error(char *msg, int ret)
{
	s_putstr_fd(msg, 2);
	return (ret);
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
