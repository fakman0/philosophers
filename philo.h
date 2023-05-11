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
	pthread_mutex_t	*last_eat_mutex;
	__uint64_t		last_eat;
	__uint64_t		needle_eat;
	__uint64_t		needle_sleep;
	__uint64_t		time_to_die;
	__uint64_t		must_eat;
	int				eating_now;
	int				philo_count;
	int				eat_count;
	uint64_t		now;
	pthread_t		*dead_check;
	int				*is_done;
}				t_philo;

typedef struct s_socrates
{
	struct s_philo	**philos;
	char			**argv;
}			t_socrates;

//utils
int			ft_atoi(char *str);
int			ft_isnum(char *num);
//error_management
int			controls(int argc, char *argv[]);
//life_cycle
void		*life_cycle(void *nullable);
void		eating(t_philo *philo);
//init
t_philo		**init(int argc, char *argv[], int i, int *is_done);
void		init_data(int argc, char *argv[], t_philo *philo, int philo_id);
void		init_threads(pthread_t *t, int p_c, t_philo **philos);
void		init_mutexes(pthread_mutex_t *mutex, int ph_c, t_philo **ph, int i);
void		give_forks(int i, int ph_c, t_philo **ps, pthread_mutex_t *m);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		print(t_philo *philo, char opt);
void		ft_putchar_fd(char c, int fd);
//time
__uint64_t	get_time(void);
void		ft_usleep(uint64_t need_to_wait);
//main
int			finish_dinner(t_philo **philos, char **argv);
#endif
