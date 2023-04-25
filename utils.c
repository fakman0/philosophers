#include "philo.h"

int	ft_atoi(char *str)
{
	int	nbr;
	int	i;
	int	sign;

	nbr = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
			nbr = (nbr * 10) + (str[i++] - '0');
	}
	return (nbr * sign);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0; 
	while (num[i] != '\0')
	{
		if (num[i] < 48 || num[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
