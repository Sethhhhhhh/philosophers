#include "../includes/philo.h"

void	clear(t_s *s)
{
	size_t	i;

	if (!s->p)
	{
		i = 0;
		while (i < s->amount)
		{
			pthread_mutex_destroy(&(s->p[i].fork));
			i++;
		}
		free(s->p);
	}
	pthread_mutex_destroy(&(s->write_m));
}

int	s_error(char *msg)
{
	write(2, msg, s_strlen(msg));
	return (1);
}

static char	create_threads(t_s *s)
{
	size_t	i;

	if (pthread_create(&(s->event), NULL, &event, (void *)(s)))
		return (0);
	pthread_detach(s->event);
	i = -1;
	while (++i < s->amount)
	{
		if (pthread_create(&(s->p[i].thread), NULL, &tasks, (void *)(&(s->p[i]))))
			return (0);
		usleep(1000);
	}
	i = -1;
	while (++i < s->amount)
		if (pthread_join(s->p[i].thread, NULL))
			return (0);
	return (1);
}

int	main(int ac, char const **av)
{
	t_s	s;

	if (ac < 5 || ac > 6)
		return (s_error("s error!\n"));
	if (!init(&s, av, ac))
	{
		clear(&s);
		return (s_error("init error!\n"));
	}
	if (!create_threads(&s))
	{
		clear(&s);
		return (0);
	}
	clear(&s);
	return (0);
}
