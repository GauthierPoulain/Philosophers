#include "../includes/philo.h"

static bool	check_threads_alive(t_manager *manager)
{
	int	i;

	i = 1;
	while (i <= manager->nb_philo)
	{
		if (manager->philo[i]->alive)
			return (true);
		i++;
	}
	return (false);
}

int	main(int argc, char *argv[])
{
	t_manager	manager;

	manager.error = false;
	manager.die = false;
	init(&manager, argc - 1, argv + 1);
	if (!manager.error)
	{
		philo_spawn(&manager);
		while (!manager.die && (manager.nb_eat == -1
				|| (manager.nb_eat != -1 && check_threads_alive(&manager))))
			usleep(10);
		close_philo(&manager);
	}
	return (manager.error);
}
