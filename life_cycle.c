#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	print(philo, 'e');
	ft_usleep(philo->needle_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	thinking(t_philo *philo)
{
	print(philo, 't');
}

void	sleeping(t_philo *philo)
{
	print(philo, 's');
	ft_usleep(philo->needle_sleep);
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
	while (1)
	{
		eating(philo);
		thinking(philo);
		sleeping(philo);
	}
	return (NULL);
}
