#include "../includes/philo.h"

static void	take_fork(t_sys *sys, size_t id)
{
	pthread_mutex_lock(&(sys->forks[id]));
	pthread_mutex_lock(&(sys->forks[(id + 1) % sys->philo_amount]));
	msg(sys, id, TYPE_FORK);
}

static void	eat(t_sys *sys, size_t id)
{
	sys->p[id].is_eating = 1;
	sys->p[id].eat_time = get_time();
	msg(sys, id, TYPE_EAT);
	usleep(sys->time_to_eat * 1000);
	sys->p[id].is_eating = 0;
}

static void	put_fork(t_sys *sys, size_t id)
{
	pthread_mutex_unlock(&(sys->forks[id]));
	pthread_mutex_unlock(&(sys->forks[(id + 1) % sys->philo_amount]));
	msg(sys, id, TYPE_SLEEP);
	usleep(sys->time_to_sleep * 1000);
}

void	*tasks(void *sys_v)
{
	t_sys	*sys;
	size_t  id;

	sys = (t_sys *)sys_v;
	pthread_mutex_lock(&(sys->lock));
	sys->id++;
	id = sys->id;
	pthread_mutex_unlock(&(sys->lock));
	while (1)
	{
		take_fork(sys, id);
		eat(sys, id);
		put_fork(sys, id);
		msg(sys, id, TYPE_THINK);
	}
}