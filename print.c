#include "philo.h"

void	print(t_philo *philo, char opt)
{
	__uint64_t	time;

	pthread_mutex_lock(philo->print_mutex);
	time = get_time() - philo->now;
	if (opt == 'e')
	{
		printf("%llu-philo %d has taken left forks\n", time, philo->philo_id);
		printf("%llu-philo %d has taken right forks\n", time, philo->philo_id);
		printf("%llu-philo %d is eating now\n", time, philo->philo_id);
		philo->eating_now = 0;
	}
	else if (opt == 't')
		printf("%llu-philo %d is thinking now\n", time, philo->philo_id);
	else if (opt == 's')
		printf("%llu-philo %d is sleeping now\n", time, philo->philo_id);
	else if (opt == 'd')
		printf("%llu-philo %d is dead\n", time, philo->philo_id);
	pthread_mutex_unlock(philo->print_mutex);
}
