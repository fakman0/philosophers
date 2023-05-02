#include "philo.h"

void	eat(t_philo *philo)
{
	if (philo->philo_id % 2 == 1)
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
		philo->eating_now = 1;
		philo->eat_count++;
	}
	else
	{	
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
		philo->eating_now = 1;
		philo->eat_count++;
	}
	print(philo, 'a');
	usleep(1000 * philo->needle_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*life_cycle(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	eat(philo);
	
}
