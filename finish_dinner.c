#include "philo.h"

void	*finish_dinner(void *socrates)
{
	int			i;
	t_socrates	*data;

	data = (t_socrates *)socrates;
	while (1)
	{
		i = -1;
		while (++i < ft_atoi(data->argv[1]))
		{
			pthread_mutex_lock(data->philos[i]->last_eat_mutex);
			if (get_time() - data->philos[i]->last_eat >= ft_atoi(data->argv[2])
				&& data->philos[i]->last_eat != 0)
			{
				pthread_mutex_unlock(data->philos[i]->last_eat_mutex);
				pthread_mutex_lock(data->philos[0]->is_done_mutex);
				*(data->philos[i]->is_done) = 1;
				pthread_mutex_unlock(data->philos[0]->is_done_mutex);
				print(data->philos[i], 'd');
				return (NULL);
			}
			pthread_mutex_unlock(data->philos[i]->last_eat_mutex);
		}
	}
	return (NULL);
}

int	all_ate_control(t_philo **philos)
{
	int		i;

	i = 0;
	while (i < philos[0]->philo_count)
	{
		pthread_mutex_lock(philos[i]->last_eat_mutex);
		if (philos[i]->must_eat != 0)
		{
			pthread_mutex_unlock(philos[i]->last_eat_mutex);
			return (0);
		}
		pthread_mutex_unlock(philos[i]->last_eat_mutex);
		i++;
	}
	return (1);
}

void	*all_ate(void *data)
{
	t_socrates	*socrates;

	socrates = (t_socrates *)data;

	while (*(socrates->philos[0]->is_done) == 0)
	{
		if (all_ate_control(socrates->philos) == 1)
		{
			pthread_mutex_lock(socrates->philos[0]->is_done_mutex);
			*(socrates->philos[0]->is_done) = 1;
			pthread_mutex_unlock(socrates->philos[0]->is_done_mutex);
			return (NULL);
		}
	}
	return (NULL);
}
