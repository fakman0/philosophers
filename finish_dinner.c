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