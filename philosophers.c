#include "philo.h"

void	*finish_dinner(void *socrates)
{
	int			i;
	int			time;
	int			p_count;
	t_socrates	*data;

	data = (t_socrates *)socrates;
	p_count = ft_atoi(data->argv[1]);
	while (1)
	{
		i = -1;
		while (++i < p_count)
		{
			pthread_mutex_lock(data->philos[i]->last_eat_mutex);
			if (get_time() - data->philos[i]->last_eat >= ft_atoi(data->argv[2])
				&& data->philos[i]->last_eat != 0)
			{
				pthread_mutex_unlock(data->philos[i]->last_eat_mutex);
				ft_usleep(1);
				*(data->philos[i]->is_done) = 1;
				print(data->philos[i], 'd');
				return (NULL);
			}
			pthread_mutex_unlock(data->philos[i]->last_eat_mutex);
		}
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_philo		**philos;
	pthread_t	dead_check;
	int			i;
	int			is_done;

	is_done = 0;
	if (!controls(argc, argv))
	{
		printf("Error!\n");
		return (0);
	}
	philos = init(argc, argv, 0, &is_done);
	return (0);
}
