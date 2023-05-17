#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo		**philos;
	int			is_done;

	is_done = 0;
	if (!controls(argc, argv))
	{
		printf("Error!\n");
		return (0);
	}
	philos = init(argc, argv, 0, &is_done);
	return (0);
	destroy(philos);
}
