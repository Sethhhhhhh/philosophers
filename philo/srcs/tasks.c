#include "../includes/philo.h"

static void	take_fork(t_p *p)
{
	if (p->s->someone_died || (p->last_eat_time > 0
		&& (get_time(&(p->tv)) - p->last_eat_time) > p->s->time_to_die))
	{
		pthread_exit(0);
	}
	pthread_mutex_lock(&(p->fork));
	if (p->s->someone_died || (p->last_eat_time > 0
		&& (get_time(&(p->tv)) - p->last_eat_time) > p->s->time_to_die))
	{
		pthread_mutex_unlock(&(p->fork));
		pthread_exit(0);
	}
	msg(p, TYPE_FORK);
	pthread_mutex_lock(&(p->s->p[(p->id + 1) % p->s->amount].fork));
	if (p->s->someone_died || (p->last_eat_time > 0
		&& (get_time(&(p->tv)) - p->last_eat_time) > p->s->time_to_die))
	{
		pthread_mutex_unlock(&(p->fork));
		pthread_mutex_unlock(&(p->s->p[(p->id + 1) % p->s->amount].fork));
		pthread_exit(0);
	}
	msg(p, TYPE_FORK);
}

static void	eat(t_p *p)
{
	msg(p, TYPE_EAT);
	p->is_eating = 1;
	(p->count_eat)++;
	p->last_eat_time = get_time(&(p->tv));
	usleep(1000 * p->s->time_to_eat);
	if (p->s->eat_amount > 0 && p->count_eat >= p->s->eat_amount)
	{
		pthread_mutex_unlock(&(p->fork));
		pthread_mutex_unlock(&(p->s->p[(p->id + 1) % p->s->amount].fork));
		pthread_exit(0);
	}
}

static void	put_fork(t_p *p)
{
	pthread_mutex_unlock(&(p->fork));
	pthread_mutex_unlock(&(p->s->p[(p->id + 1) % p->s->amount].fork));
	p->is_eating = 0;

	if (p->s->someone_died || (p->last_eat_time > 0
		&& (get_time(&(p->tv)) - p->last_eat_time) > p->s->time_to_die))
		pthread_exit(0);
	msg(p, TYPE_SLEEP);
	usleep(1000 * p->s->time_to_sleep);
}

void	*tasks(void *p_s)
{
	t_p				*p;

	p = (t_p *)p_s;
	while (!p->is_death)
	{
		take_fork(p);
		eat(p);
		put_fork(p);
		if (p->s->someone_died || (p->last_eat_time > 0
			&& (get_time(&(p->tv)) - p->last_eat_time) > p->s->time_to_die))
			pthread_exit(0);
		msg(p, TYPE_THINK);
	}
	pthread_exit(0);
}
