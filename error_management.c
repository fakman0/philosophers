#include "philo.h"

void	controls(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		exit(printf("Error!\nWrong number of arguments"));
	while (argv[i])
	{
		if (!ft_isnum(argv[i]))
			exit(printf("Error!\nYour arguments must be number"));
		i++;
	}
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) < 1)
		exit(printf("Error!\nWrong number of philosophers"));
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		exit(printf("Error!\nArguments must be minimum 60ms"));
	if (ft_atoi(argv[1]) == 1)
	{
		printf("Philo 1, took the right fork\n");
		printf("Error! Philo 1 didn't get the left fork\n");
		usleep(ft_atoi(argv[2]) * 1000);
		exit(printf("Philo 1 is dead"));
	}
}
