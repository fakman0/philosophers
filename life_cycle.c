#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	ft_usleep(philo->needle_eat);
	print(philo, 'e');
	pthread_mutex_lock(philo->last_eat_mutex);
	philo->last_eat = get_time();
	philo->must_eat--;
	pthread_mutex_unlock(philo->last_eat_mutex);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	*life_cycle(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (philo->philo_id % 2 == 0)
	{
		print(philo, 't');
		ft_usleep(1);
	}
	pthread_mutex_lock(philo->is_done_mutex);
	while (1 && !*(philo->is_done))
	{
		pthread_mutex_unlock(philo->is_done_mutex);
		eating(philo);
		print(philo, 't');
		ft_usleep(philo->needle_sleep);
		print(philo, 's');
		pthread_mutex_lock(philo->is_done_mutex);
	}
	pthread_mutex_unlock(philo->is_done_mutex);
	return (NULL);
}
