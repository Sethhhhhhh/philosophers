#include "../includes/philo.h"

void	clear(t_s *s)
{
	size_t	i;

	if (s->p)
	{
		i = 0;
		while (i < s->amount)
		{
			pthread_mutex_destroy(&(s->p[i].fork));
			pthread_mutex_destroy(&(s->p[i].eat_m));
			i++;
		}
		free(s->p);
	}
	pthread_mutex_destroy(&(s->mutex));
	pthread_mutex_destroy(&(s->write_m));
	pthread_mutex_destroy(&(s->event_m));
}

int	s_error(char *msg)
{
	write(2, msg, s_strlen(msg));
	return (1);
}

static char	create_threads(t_s *s)
{
	size_t	i;

	if (pthread_create(&(s->event), NULL, &event, (void *)s))
		return (0);
	pthread_detach(s->event);
	i = 0;
	while (i < s->amount)
	{
		if (pthread_create(&(s->p[i].thread), NULL, &tasks, (void *)s))
			return (0);
		pthread_detach(s->p[i].thread);
		i++;
	}
	return (1);
}

int	main(int ac, char const **av)
{
	t_s	s;

	s_bzero(&s, sizeof(t_s));
	if (ac < 5 || ac > 6)
		return (s_error("args error!\n"));
	if (!init(&s, av, ac))
	{
		clear(&s);
		return (s_error("init error!\n"));
	}
	if (s.amount == 1)
	{
		msg(&s, 0, TYPE_DIE);
		clear(&s);
		return (1);
	}
	if (!create_threads(&s))
	{
		clear(&s);
		return (s_error("threads error!\n"));
	}
	pthread_mutex_lock(&(s.event_m));
	pthread_mutex_unlock(&(s.event_m));
	clear(&s);
	return (0);
}
