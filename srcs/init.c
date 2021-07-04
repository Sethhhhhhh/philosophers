#include "../includes/philo.h"

static int	init_philosopher(t_p *p, size_t id)
{
	p->id = id;
	p->is_eating = 0;
	p->eat_time = 0;
	p->is_eating = 0;
	if (pthread_mutex_init(&(p->fork), NULL))
		return (0);
	return (1);
}

int	init(t_sys *sys, char const **av, int ac)
{
	size_t	i;

	if (ac < 2 || ac > 6)
		return (s_error("args problem!", 0));
	sys->philo_amount = s_atoi(av[1]);
	sys->time_to_die = s_atoi(av[2]);
	sys->time_to_eat = s_atoi(av[3]);
	sys->time_to_sleep = s_atoi(av[4]);
	if (ac == 6)
		sys->eat_amount = s_atoi(av[5]);
	else
		sys->eat_amount = 0;

	sys->p = (t_p *) malloc(sizeof(t_p) * sys->philo_amount);
	if (!sys->p)
		return (0);
	i = 0;
	while (i < sys->philo_amount)
	{
		if (!init_philosopher(sys->p, i))
			return (0);
		i++;
	}
	if (pthread_mutex_init(&(sys->lock), NULL))
		return (0);
	return (1);
}