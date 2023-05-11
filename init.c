#include "philo.h"

t_philo	**init(int argc, char *argv[], int i, int *is_done)
{
	t_philo			**philos;
	pthread_t		*threads;
	pthread_mutex_t	*mutexes;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	last_eat_mutex;

	threads = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	mutexes = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	philos = malloc(sizeof(t_philo *) * ft_atoi(argv[1]));
	pthread_mutex_init(&print_mutex, NULL);
	pthread_mutex_init(&last_eat_mutex, NULL);
	init_mutexes(mutexes, ft_atoi(argv[1]), philos, ft_atoi(argv[1]));
	while (i < ft_atoi(argv[1]))
	{
		init_data(argc, argv, philos[i], i);
		philos[i]->philo = &threads[i];
		philos[i]->print_mutex = &print_mutex;
		philos[i]->last_eat_mutex = &last_eat_mutex;
		philos[i]->is_done = is_done;
		i++;
	}
	init_threads(threads, ft_atoi(argv[1]), philos, argv);
	return (philos);
}

void	init_data(int argc, char *argv[], t_philo *philo, int philo_id)
{
	long	time_to_die;
	long	needle_eat;
	long	needle_sleep;
	long	must_eat;

	philo->philo_id = philo_id;
	philo->philo_count = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->needle_eat = ft_atoi(argv[3]);
	philo->needle_sleep = ft_atoi(argv[4]);
	philo->must_eat = -1;
	philo->last_eat = 0;
	philo->eating_now = 0;
	philo->now = get_time();
	if (argc == 6)
		philo->must_eat = ft_atoi(argv[5]);
}

void	init_threads(pthread_t *thread, int p_count, t_philo **philos, char **a)
{
	int			i;
	pthread_t	dead_check;
	t_socrates	*socrates;

	i = 0;
	socrates = malloc(sizeof(t_socrates));
	socrates->argv = a;
	socrates->philos = philos;
	while (i < p_count)
	{
		pthread_create(&thread[i], NULL, life_cycle, philos[i]); // philos'a erişiyor
		i++;
	}
	pthread_create(&dead_check, NULL, finish_dinner, socrates); //socrates'ten philos'a erişiyor data race oluyor. thread ile yapma mainden öldüğünü kontrol et.
	i = 0;
	while (i < p_count)
	{
		pthread_join(*(philos[i]->philo), NULL);
		i++;
	}
	pthread_join(dead_check, NULL);
}

void	init_mutexes(pthread_mutex_t *mutex, int ph_c, t_philo **ph, int i)
{
	pthread_mutex_t	*last_eat_mutexes;

	last_eat_mutexes = malloc(sizeof(pthread_mutex_t));
	while (i-- > 0)
	{
		pthread_mutex_init(&last_eat_mutexes[i], NULL);
		pthread_mutex_init(&mutex[i], NULL);
	}
	while (i++ < ph_c)
	{
		ph[i] = malloc(sizeof(t_philo));
		ph[i]->last_eat_mutex = &last_eat_mutexes[i];
		if (i != ph_c - 1)
		{
			ph[i]->r_fork = &(mutex[i]);
			ph[i]->l_fork = &(mutex[i + 1]);
		}
		else
		{
			ph[i]->r_fork = &(mutex[i]);
			ph[i]->l_fork = &(mutex[0]);
		}
	}
}
