#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo	**philos;

	controls(argc, argv);
	philos = init(argc, argv, 0);
	sleep(100);
	return (0);
}
