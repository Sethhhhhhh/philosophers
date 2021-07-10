#include "../../includes/philo.h"

void	s_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
