#include "philo.h"

t_philo	**init(int argc, char *argv[], int i)
{
	t_philo			**philos;
	pthread_t		*threads;
	pthread_mutex_t	*mutexes;

	philos = malloc(sizeof(t_philo *) * ft_atoi(argv[1]));
	init_forks(mutexes, ft_atoi(argv[1]));
	while (i < ft_atoi(argv[1]))
	{
		philos[i] = malloc(sizeof(t_philo));
		init_data(argc, argv, philos[i], i);
		philos[i]->philo = &threads[i];
		if (i != ft_atoi(argv[1]) - 1)
		{
			philos[i]->r_fork = &mutexes[i];
			philos[i]->l_fork = &mutexes[i + 1];
		}
		else
		{
			philos[i]->r_fork = &mutexes[i];
			philos[i]->l_fork = &mutexes[0];
		}
		i++;
	}
	init_threads(threads, ft_atoi(argv[1]), philos);
	return (philos);
}

void	init_data(int argc, char *argv[], t_philo *philo, int philo_id)
{
	long	time_to_die;
	long	needle_eat;
	long	needle_sleep;
	long	must_eat;

	philo->philo_id = philo_id;
	philo->time_to_die = ft_atoi(argv[2]);
	philo->needle_eat = ft_atoi(argv[3]);
	philo->needle_sleep = ft_atoi(argv[4]);
	philo->must_eat = -1;
	philo->eat_time = 0;
	philo->think_time = 0;
	philo->sleep_time = 0;
	philo->eating_now = 0;
	if (argc == 6)
		philo->must_eat = ft_atoi(argv[5]);
}

void	init_threads(pthread_t *threads, int philo_count, t_philo **philos)
{
	int	i;

	threads = malloc(sizeof(pthread_t) * philo_count);
	i = 0;
	while (i < philo_count)
	{
		if (pthread_create(&threads[i], NULL, life_cycle, philos[i]))
			exit(printf("Error!\ncannot create threads"));
		i++;
	}
}

void	init_forks(pthread_mutex_t	*mutexes, int philo_count)
{
	int	i;

	mutexes = malloc(sizeof(pthread_mutex_t) * philo_count);
	i = 0;
	while (i < philo_count)
	{
		if (pthread_mutex_init(&mutexes[i], NULL))
			exit(printf("Error!\ncannot create mutex"));
		i++;
	}
}
