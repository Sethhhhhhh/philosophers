#include "../includes/philo.h"

int	s_error(char *msg, int ret)
{
	s_putstr_fd(msg, 2);
	return (ret);
}
