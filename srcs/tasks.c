#include "../includes/philo.h"

static void	take_fork(t_s *s, size_t id)
{
	pthread_mutex_lock(&(s->p[id].fork));
	pthread_mutex_lock(&(s->p[(id + 1) % s->amount].fork));
	msg(s, id, TYPE_FORK);
}

static void	eat(t_s *s, size_t id)
{
	msg(s, id, TYPE_EAT);
	pthread_mutex_lock(&(s->mutex));
	s->p[id].is_eating = 1;
	s->p[id].last_meal_time = get_time();
	(s->p[id].count_meals)++;
	if (s->p[id].count_meals > s->eat_amount)
	{
		usleep(s->time_to_die);
	}
	pthread_mutex_unlock(&(s->mutex));
	usleep(s->time_to_eat * 1000);
	pthread_mutex_lock(&(s->mutex));
	s->p[id].is_eating = 0;
	pthread_mutex_unlock(&(s->mutex));
}

static void	put_fork(t_s *s, size_t id)
{
	pthread_mutex_unlock(&(s->p[id].fork));
	pthread_mutex_unlock(&(s->p[(id + 1) % s->amount].fork));
	msg(s, id, TYPE_SLEEP);
	usleep(s->time_to_sleep * 1000);
}

void	*tasks(void *s_v)
{
	t_s				*s;
	size_t			id;

	s = (t_s *)s_v;
	pthread_mutex_lock(&(s->mutex));
	s->id++;
	id = s->id;
	pthread_mutex_unlock(&(s->mutex));
	while (1)
	{
		take_fork(s, id);
		eat(s, id);
		put_fork(s, id);
		msg(s, id, TYPE_THINK);
	}
	return (void *)0;
}