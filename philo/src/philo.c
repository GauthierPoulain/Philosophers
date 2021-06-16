#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_manager	manager;

	manager.error = false;
	manager.die = false;
	init(&manager, argc - 1, argv + 1);
	if (!manager.error)
	{
		philo_spawn(&manager);
		while (!manager.die)
			usleep(10);
		ft_putstr(1, "end of simulation\n");
		close_philo(&manager);
	}
	return (manager.error);
}
