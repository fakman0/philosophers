#include "philo.h"

int	finish_dinner(t_philo **philos, char **argv)
{
	int			i;
	int			p_count;

	p_count = ft_atoi(argv[1]);
	while (1)
	{
		i = -1;
		while (++i < p_count)
		{
			pthread_mutex_lock(philos[i]->last_eat_mutex);
			if (get_time() - philos[i]->last_eat >= ft_atoi(argv[2])
				&& philos[i]->last_eat != 0)
			{
				pthread_mutex_unlock(philos[i]->last_eat_mutex);
				ft_usleep(1);
				*(philos[i]->is_done) = 1;
				print(philos[i], 'd');
				return (1);
			}
			pthread_mutex_unlock(philos[i]->last_eat_mutex);
		}
	}
	return (1);
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
	i = 0;
	if (finish_dinner(philos, argv) == 1)
		write(1,"tamam",5);
	return (0);
}
