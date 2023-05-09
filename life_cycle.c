#include "philo.h"

void	eating(t_philo *philo)
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
	while (1)
	{
		eating(philo);
		sleeping(philo); //thinking sadece çatalları devrettiğimizi belli eden bir yazı
		thinking(philo);
	}
	return (NULL);
}
