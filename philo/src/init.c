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
		manager->philo[i] = malloc(sizeof(t_philo));
		if (!manager->philo[i])
			set_error(ERR_MALLOC, manager);
		i++;
	}
	i = 1;
	while (i <= manager->nb_philo)
		philo_create(manager, i++);
}

static void	set_values(t_manager *manager, char *argv[])
{
	manager->philo = NULL;
	manager->nb_philo = ft_atoi(argv[0]);
	manager->nb_forks = manager->nb_philo;
	manager->time_to_die = ft_atoi(argv[1]);
	manager->time_to_eat = ft_atoi(argv[2]);
	manager->time_to_sleep = ft_atoi(argv[3]);
	manager->nb_eat = -1;
	if (argv[4])
		manager->nb_eat = ft_atoi(argv[4]);
}

void	init(t_manager *manager, int argc, char *argv[])
{
	if (argc < 4 || argc > 5)
		return (set_error(ERR_ARGSNUMBER, manager));
	else if (!check_args(argv))
		return (set_error(ERR_INVALIDARG, manager));
	set_values(manager, argv);
	pthread_mutex_init(&manager->mutex_print, NULL);
	pthread_mutex_init(&manager->mutex_die, NULL);
	manager->philo = malloc(sizeof(t_philo) * (manager->nb_philo + 1));
	if (!manager->philo)
		return (set_error(ERR_MALLOC, manager));
	init_philos(manager);
}
