#include "../includes/philo.h"

int		main(int ac, char **av)
{	
	t_s	s;

	if (ac < 5 || ac > 6)
		return (s_error("\nError:\n    Usage: ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]\n\n", 0));

	init(&s, av);

	return (0);
}
