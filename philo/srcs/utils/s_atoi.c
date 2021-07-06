#include "../../includes/philo.h"

long	s_atoi(const char *str)
{
	long	i;
	long	neg;
	long	sum;

	i = 0;
	neg = 1;
	sum = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = (sum * 10) + (str[i] - 48);
		i++;
	}
	return (sum * neg);
}
