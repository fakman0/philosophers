#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(long need_to_wait)
{
	long	start_time;
	long	finish_time;

	start_time = get_time();
	while (1)
	{
		finish_time = get_time();
		if ((finish_time - start_time) >= need_to_wait)
			break ;
	}
}
