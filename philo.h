#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				philo_id;
	pthread_t		*philo;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*print_mutex;
	__uint64_t		eat_time;
	__uint64_t		sleep_time;
	__uint64_t		think_time;
	__uint64_t		needle_eat;
	__uint64_t		needle_sleep;
	__uint64_t		time_to_die;
	__uint64_t		must_eat;
	int				eating_now;
	int				philo_count;
	int				eat_count;
}				t_philo;

//utils
int			ft_atoi(char *str);
int			ft_isnum(char *num);
//error_management
int			controls(int argc, char *argv[]);
//life_cycle
void		*life_cycle(void *nullable);
void		eating(t_philo *philo);
//init
t_philo	**init(int argc, char *argv[], int i);
void		init_data(int argc, char *argv[], t_philo *philo, int philo_id);
void		init_threads(pthread_t *threads, int philo_count, t_philo **philos);
void		init_forks(pthread_mutex_t	*mutexes, int philo_count);
void		give_forks(int i, int ph_c, t_philo **philos, pthread_mutex_t *mutexes);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		print(t_philo *philo, char opt);
void		ft_putchar_fd(char c, int fd);
//time
__uint64_t	get_time(void);
void		ft_usleep(long need_to_wait);
#endif
