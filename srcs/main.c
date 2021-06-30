#include "../includes/philo.h"

int		main(int ac, char **av)
{	
	t_p	p;

	if (ac < 2)
	s_error("\nError:\n    Usage: ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]\n\n", 0);
	return (0);
}
