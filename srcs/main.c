#include "../includes/philo.h"

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
	
	if (ac < 2 || ac > 6)
		return (0);
	if (!init(&s, av, ac))
		return (0);
	if (!create_threads(&s))
		return (0);
	pthread_mutex_lock(&(s.event_m));
	pthread_mutex_unlock(&(s.event_m));
	return (0);
}