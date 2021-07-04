#include "../includes/philo.h"

int	main(int ac, char const **av)
{
	t_sys	sys;

	if (!init(&sys, av, ac))
		return (0);
	
	print_config(&sys);
	return (0);
}