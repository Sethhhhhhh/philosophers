#include "../../includes/philo.h"

static int	init_philosophers(t_s *s)
{
	size_t	i;

	i = 0;
	while (i < s->args.p_amount)
	{
		s_bzero(&(s->p[i]), sizeof(t_p));
		s->p[i].id = i;
		if (pthread_mutex_init(&(s->p[i].right_fork), NULL))
			return (0);
		pthread_mutex_lock(&(s->p[i].right_fork));
		pthread_create(&(s->p[i].thread), NULL, tasks, &(s));
		usleep(1000);
		i++;
	}
	return (1);
}

int	init(t_s *s, char **av)
{
	s->args.p_amount = s_atoi(av[1]);
	s->args.time_to_eat = s_atoi(av[2]);
	s->args.time_to_die = s_atoi(av[3]);
	s->args.time_to_sleep = s_atoi(av[4]);
	if (av[5])
		s->args.eat_amount = s_atoi(av[5]);
	s->p = (t_p *) malloc(sizeof(t_p) * s->args.p_amount);
	if (!s->p)
		return (s_error("Malloc failed.", 0));
	init_philosophers(s);
	return (1);
}
