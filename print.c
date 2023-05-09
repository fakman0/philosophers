#include "philo.h"

void	print(t_philo *philo, char opt)
{
	pthread_mutex_lock(philo->print_mutex);
	if (opt == 'e')
	{
		printf("philo %d has taken forks\n", philo->philo_id);
		printf("philo %d is eating now\n", philo->philo_id);
		philo->eating_now = 0;
	}
	else if (opt == 't')
		printf("philo %d is thinking now\n", philo->philo_id);
	else if (opt == 's')
		printf("philo %d is sleeping now\n", philo->philo_id);
	pthread_mutex_unlock(philo->print_mutex);
}
