#include "../includes/philo.h"

static char	death(t_s *s, size_t i)
{
	if (!s->p[i].is_eating && (get_time() - s->p[i].last_meal_time) > s->time_to_die)
	{
		pthread_mutex_lock(&(s->write_m));
		pthread_mutex_unlock(&(s->write_m));
		msg(s, i, TYPE_DIE);
		pthread_mutex_unlock(&(s->event_m));
		return (1);
	}
	return (0);
}

static char	must_eat(t_s *s, size_t i, size_t *must_eat_count)
{
	if (!s->p[i].must_eat_check && s->eat_amount > 0 && s->p[i].count_meals >= s->eat_amount)
	{
		(*must_eat_count)++;
		s->p[i].must_eat_check = 1;
		pthread_mutex_lock(&(s->p[i].eat_m));
		if (*must_eat_count >= s->amount)
		{
			pthread_mutex_lock(&(s->write_m));
			pthread_mutex_unlock(&(s->write_m));
			msg(s, i, TYPE_OVER);
			pthread_mutex_unlock(&(s->event_m));
			return (1);
		}
	}
	return (0);
}

void    *event(void *s_v)
{
	t_s     *s;
	size_t  i;
	size_t	must_eat_count;

	s = (t_s *)s_v;
	must_eat_count = 0;
	pthread_mutex_lock(&(s->event_m));
	while (1)
	{
		i = 0;
		while (i < s->amount)
		{
			pthread_mutex_lock(&(s->mutex));
			if (must_eat(s, i, &must_eat_count) || death(s, i))
				return ((void *)0);
			i++;
			pthread_mutex_unlock(&(s->mutex));
		}
	}
}