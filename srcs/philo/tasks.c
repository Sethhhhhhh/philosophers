#include "../../includes/philo.h"

void	*tasks(void *s)
{
	s_putstr_fd("Thread is created with success!\n", 1);
	pthread_exit(NULL);
}
