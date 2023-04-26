#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_philo
{
    int             philo_id; //* Pilozofların indeksi
    pthread_t       *philo;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
    long   eat_time; //* Yemek yemeye başladığı milisaniye (ekrana yazdırmak ve karşılaştırma yapmak için)
    long   sleep_time; //* uyumaya başladığı milisaniye (ekrana yazdırmak ve karşılaştırma yapmak için)
    long   think_time; //* düşünmeye yemeye başladığı milisaniye (ekrana yazdırmak ve karşılaştırma yapmak için)
    long   needle_eat; //* argüman olarak aldığımız kaç saniye yemek yemesi gerektiğini belirten süre
    long   needle_sleep; //* argüman olarak aldığımız kaç saniye uyuması gerektiğini belirten süre
    long   time_to_die;  //* argüman olarak aldığımız kaç saniye yemek yemezse öleceğini belirten süre
    long            must_eat; //* opsiyonel olarak aldığımız, tüm filozofların kaç kez yemek yedikten sonra programı bitirmemiz gerektiğini söyleyen sınır.
	int		eating_now;
}				t_philo;

//utils
int		ft_atoi(char *str);
int		ft_isnum(char *num);
//error_management
void	controls(int argc, char *argv[]);
//life_cycle
void	*life_cycle(void *nullable);
//init
t_philo	**init(int argc, char *argv[], int i);
void	init_data(int argc, char *argv[], t_philo *philo, int philo_id);
void	init_threads(pthread_t *threads, int philo_count, t_philo **philos);
void	init_forks(pthread_mutex_t	*mutexes, int philo_count);
#endif
