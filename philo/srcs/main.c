#include "../includes/philo.h"

void	s_usleep(unsigned int time_in_ms)
{
	unsigned int	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}

void	clear(t_s *s)
{
	size_t	i;

	if (s->p && s->amount > 0)
	{
		i = 0;
		while (i < s->amount)
		{
			pthread_mutex_destroy(&(s->forks[i]));
			i++;
		}
		free(s->forks);
		free(s->p);
		pthread_mutex_destroy(&(s->death_m));
		pthread_mutex_destroy(&(s->lock_m));
		pthread_mutex_destroy(&(s->write_m));
	}
}

int	s_error(char *msg)
{
	s_putstr_fd(msg, 2);
	return (1);
}

static char	create_threads(t_s *s)
{
	size_t	i;

	if (pthread_create(&(s->death), NULL, &death, (void *)(s)))
		return (0);
	pthread_detach(s->death);
	i = -1;
	while (++i < s->amount)
	{
		if (pthread_create(&(s->p[i].thread),
				NULL, &tasks, (void *)(&(s->p[i]))))
			return (0);
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
		return (s_error("args error!\n"));
	if (!init(&s, av, ac))
	{
		clear(&s);
		return (s_error("init error!\n"));
	}
	if (!create_threads(&s))
	{
		clear(&s);
		return (s_error("threads error!\n"));
	}
	pthread_mutex_lock(&(s.death_m));
	pthread_mutex_unlock(&(s.death_m));
	s_usleep(5);
	clear(&s);
	return (0);
}
