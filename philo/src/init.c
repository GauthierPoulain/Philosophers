#include "../includes/philo.h"

static bool	check_args(char *argv[])
{
	while (*argv)
	{
		if (!is_digits(*argv) || check_int_overflow(*argv)
			|| ft_atoi(*argv) < 0)
			return (false);
		argv++;
	}
	return (true);
}

static void	init_philos(t_manager *manager)
{
	int	i;

	i = 1;
	while (i <= manager->nb_philo)
	{
		create_philo(manager, i);
		i++;
	}
}

static void	set_values(t_manager *manager, char *argv[])
{
	manager->philo = NULL;
	manager->nb_philo = ft_atoi(argv[0]);
	manager->nb_forks = manager->nb_philo;
	manager->time_to_die = ft_atoi(argv[1]);
	manager->time_to_eat = ft_atoi(argv[2]);
	manager->time_to_sleep = ft_atoi(argv[3]);
	manager->nb_eat = 0;
	if (argv[4])
		manager->nb_eat = ft_atoi(argv[4]);
}

t_manager	*init(int argc, char *argv[])
{
	t_manager	*manager;

	manager = NULL;
	if (argc < 3 || argc > 4)
		set_error(ERR_ARGSNUMBER, manager);
	else if (!check_args(argv))
		set_error(ERR_INVALIDARG, manager);
	manager = malloc(sizeof(t_manager));
	if (!manager)
		set_error(ERR_MALLOC, manager);
	set_values(manager, argv);
	if (pthread_mutex_init(&manager->mutex_print, NULL) != 0)
		set_error(ERR_MUTEX, manager);
	manager->philo = malloc(sizeof(t_philo *) * (manager->nb_philo + 1));
	if (!manager->philo)
		set_error(ERR_MALLOC, manager);
	init_philos(manager);
	return (manager);
}
