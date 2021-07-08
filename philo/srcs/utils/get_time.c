#include "../../includes/philo.h"

unsigned int	get_time(struct timeval	*tv)
{
	if (gettimeofday(tv, NULL))
		return (0);
	return ((tv->tv_sec * 1000) + (tv->tv_usec / 1000));
}
