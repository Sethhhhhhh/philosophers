#include "../includes/philo.h"

static char	init_mutex(t_s *s)
{
	if (pthread_mutex_init(&(s->mutex), NULL))
		return (0);
	if (pthread_mutex_init(&(s->write_m), NULL))
		return (0);
	if (pthread_mutex_init(&(s->event_m), NULL))
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
		s->p[i].is_eating = 0;
		s->p[i].last_meal_time = get_time();
		s->p[i].count_meals = 0;
		s->p[i].must_eat_check = 0;
		if (pthread_mutex_init(&(s->p[i].fork), NULL))
			return (0);
		if (pthread_mutex_init(&(s->p[i].eat_m), NULL))
			return (0);
		i++;
	}
	return (1);
}

static char	set_args(t_s *s, char const **av, int ac)
{
	s->amount = s_atoi(av[1]);
	s->time_to_die = s_atoi(av[2]);
	s->time_to_eat = s_atoi(av[3]);
	s->time_to_sleep = s_atoi(av[4]);
	if (ac == 6)
		s->eat_amount = s_atoi(av[5]);
	else
		s->eat_amount = 0;
	if (s->amount <= 0 || s->time_to_die <= 0
		|| s->time_to_eat <= 0 || s->time_to_sleep <= 0)
		return (0);
	return (1);
}

char	init(t_s *s, char const **av, int ac)
{
	if (!set_args(s, av, ac))
		return (0);
	s->timestamp = get_time();
	s->id = -1;
	if (!init_philosophers(s) || !init_mutex(s))
		return (0);
	return (1);
}