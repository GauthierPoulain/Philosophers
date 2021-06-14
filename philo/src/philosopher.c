#include "../includes/philo.h"

void	create_philo(t_manager *manager, int id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		set_error(ERR_MALLOC, manager);
	manager->philo[id] = philo;
	philo->id = id;
	philo->manager = manager;
	if (pthread_mutex_init(&philo->left_fork, NULL) != 0
		|| pthread_mutex_init(&philo->right_fork, NULL) != 0)
		set_error(ERR_MUTEX, manager);
	if (id >= 1 && id <= manager->nb_philo - 1)
		philo->prev_philo = manager->philo[id - 1];
	else if (id == 0)
		philo->prev_philo = manager->philo[manager->nb_philo - 1];
	if (id >= 0 && id < manager->nb_philo - 1)
		philo->next_philo = manager->philo[id + 1];
	else if (id == manager->nb_philo - 1)
		philo->next_philo = manager->philo[0];
}

void	*philosopher(void *philo_raw)
{
	t_philo	*philo;

	philo = philo_raw;
	philo->timestamp = get_time_ms();
	print(philo, MSG_SPAWN);
	print(philo, MSG_DIED);
	return (NULL);
}

void	spawn_philos(t_manager *manager)
{
	int	i;

	i = 1;
	while (i <= manager->nb_philo)
	{
		if (pthread_create(&manager->philo[i]->pthread, NULL,
				philosopher, manager->philo[i]) != 0)
			set_error(ERR_THREAD, manager);
		i++;
	}
}
