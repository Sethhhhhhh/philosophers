#include "../includes/philo.h"

void	*event(void *s_v)
{
	t_s     *s;
    size_t  i;
    size_t  count_must;

	s = (t_s *)s_v;
	while (!s->someone_died && !s->must_eat)
	{
        i = 0;
        count_must = 0;
        while (i < s->amount)
        {
            if (!s->someone_died && s->p[i].last_eat_time > 0 && get_time(&(s->tv)) - s->p[i].last_eat_time > s->time_to_die)
            {
                msg(&(s->p[i]), TYPE_DIE);
                s->someone_died = 1;
            }
            else if (s->eat_amount > 0 && !s->someone_died && s->p[i].count_eat >= s->eat_amount)
            {
                count_must++;
                if (count_must >= s->amount)
                {
                    s->must_eat = 1;
                    pthread_mutex_lock(&(s->write_m));
                    s_putstr_fd(get_msg_type(TYPE_OVER), 1);
                    pthread_mutex_unlock(&(s->write_m));
                }
            }
            i++;
        }
	}
	pthread_exit(0);
}
