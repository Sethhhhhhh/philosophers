#include "../../includes/philo.h"

void    s_putnbr_fd(unsigned long int u, int fd)
{
	if (u >= 10)
	{
		s_putnbr_fd(u / 10, fd);
		s_putnbr_fd(u % 10, fd);
	}
	else
	{
		if (fd >= 0)
		{
			u += 48;
			write(fd, &u, 1);
		}
	}
}