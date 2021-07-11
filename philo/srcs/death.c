#include "../includes/philo.h"

static void	check(t_s *s, size_t *i)
{
	pthread_mutex_lock(&(s->lock_m));
	if (!s->someone_died && !s->p[*i].is_eating && !s->p[*i].must_eat
		&& (get_time() - s->p[*i].last_eat_time) >= s->time_to_die)
	{
		msg(&(s->p[*i]), TYPE_DIE);
		s->someone_died = 1;
		pthread_mutex_unlock(&(s->lock_m));
		pthread_mutex_unlock(&(s->death_m));
		pthread_exit(0);
	}
	if (s->someone_died)
	{
		pthread_mutex_unlock(&(s->lock_m));
		pthread_mutex_unlock(&(s->death_m));
		pthread_exit(0);
	}
	(*i)++;
	if (*i >= s->amount && !s->someone_died)
		*i = 0;
	pthread_mutex_unlock(&(s->lock_m));
}

void	*death(void *s_v)
{
	t_s		*s;
	size_t	i;

	s = (t_s *)s_v;
	pthread_mutex_lock(&(s->death_m));
	i = 0;
	while (i < s->amount)
	{
		check(s, &i);
		usleep(100);
	}
	return ((void *)0);
}
