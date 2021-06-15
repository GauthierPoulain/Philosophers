#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_manager	*manager;

	setbuf(stderr, NULL);
	setbuf(stdout, NULL);
	manager = init(argc - 1, argv + 1);
	philo_spawn(manager);
	close_philo(EXIT_SUCCESS, manager);
}
