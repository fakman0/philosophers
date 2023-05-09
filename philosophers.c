#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo	**philos;

	if (!controls(argc, argv))
	{
		printf("Error!\n");
		return (0);
	}
	philos = init(argc, argv, 0);
	while (1)
	{
		//Yemek yemeye başladıklarında, düşünmeye başladıklarında, uyumaya başladıklarında 
	}
	sleep(100);
	return (0);
}
