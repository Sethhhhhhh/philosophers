#include "../../includes/philo.h"

void	s_putstr_fd(char *str, int fd)
{
	size_t	i;

	i = -1;
	while (str[++i])
		s_putchar_fd(str[i], fd);
}
