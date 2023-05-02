#include "philo.h"

void	print(t_philo *philo, char opt)
{
	if (philo->eating_now == 1)
	{
		pthread_mutex_lock(philo->print_mutex);
		printf("philo %d is eating now\n", philo->philo_id);
		fflush(stdout);
		philo->eating_now = 0;
		usleep(1000 * philo->needle_eat);
		pthread_mutex_unlock(philo->print_mutex);
	}
	else
	{
		printf("philo %d thinking\n", philo->philo_id);
		fflush(stdout);
		usleep(philo->needle_eat * 1000);
	}
}
