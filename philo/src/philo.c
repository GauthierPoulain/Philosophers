#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_manager	manager;

	setbuf(stderr, NULL);
	setbuf(stdout, NULL);
	manager.error = false;
	manager.die = false;
	init(&manager, argc - 1, argv + 1);
	if (!manager.error)
	{
		pthread_mutex_lock(&manager.mutex_die);
		philo_spawn(&manager);
		pthread_mutex_lock(&manager.mutex_die);
		pthread_mutex_unlock(&manager.mutex_die);
		close_philo(&manager);
	}
	ft_putstr(1, "end of simulation\n");
	return (manager.error);
}
