#include "../includes/philo.h"

static int	create_threads(t_sys *sys)
{
	size_t	i;

	i = 0;
	while (i < sys->philo_amount)
	{
		if (pthread_create(&(sys->p[i].thread), NULL, &tasks, (void *)sys))
			return (0);
		i++;
	}
	i = 0;
	while (i < sys->philo_amount)
	{
		if (pthread_join(sys->p[i].thread, NULL))
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char const **av)
{
	t_sys	sys;

	if (!init(&sys, av, ac))
		return (0);
	if (!create_threads(&sys))
		return (0);

	// print_config(&sys);
	return (0);
}