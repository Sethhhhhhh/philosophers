#include "../includes/philo.h"

static char	init_mutex(t_s *s)
{
	if (pthread_mutex_init(&(s->write_m), NULL))
		return (0);
	return (1);
}

static char	init_philosophers(t_s *s)
{
	size_t	i;

	s->p = (t_p *) malloc(sizeof(t_p) * s->amount);
	if (!s->p)
		return (0);
	i = 0;
	while (i < s->amount)
	{
		s->p[i].id = i;
		s->p[i].is_death = 0;
		s->p[i].s = s;
		s->p[i].is_eating = 0;
		s->p[i].count_eat = 0;
		s->p[i].last_eat_time = 0;
		if (pthread_mutex_init(&(s->p[i].fork), NULL))
			return (0);
		i++;
	}
	return (1);
}

static char	set_arg(size_t *get, char const **av, int id)
{
	int	n;

	n = s_atoi(av[id]);
	if (n <= 0)
		return (0);
	(*get) = (size_t)n;
	return (1);
}

static char	set_args(t_s *s, char const **av, int ac)
{
	if (!set_arg(&(s->amount), av, 1))
		return (0);
	if (!set_arg(&(s->time_to_die), av, 2))
		return (0);
	if (!set_arg(&(s->time_to_eat), av, 3))
		return (0);
	if (!set_arg(&(s->time_to_sleep), av, 4))
		return (0);
	if (ac == 6)
	{
		if (!set_arg(&(s->eat_amount), av, 5))
			return (0);
	}
	else
		s->eat_amount = 0;
	s->start_time = get_time(&(s->tv));
	s->someone_died = 0;
	s->must_eat = 0;
	return (1);
}

char	init(t_s *s, char const **av, int ac)
{
	s->p = NULL;
	if (!set_args(s, av, ac))
		return (0);
	if (!init_philosophers(s))
		return (0);
	if (!init_mutex(s))
		return (0);
	return (1);
}
