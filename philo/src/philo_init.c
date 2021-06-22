#include "../includes/philo.h"

void	philo_create(t_manager *manager, int id)
{
	t_philo	*philo;

	philo = manager->philo[id];
	philo->id = id;
	philo->manager = manager;
	philo->nb_eat = 0;
	philo->alive = true;
	philo->right_fork = NULL;
	if (id > 1 && id <= manager->nb_philo)
		philo->prev_philo = manager->philo[id - 1];
	else if (id == 1)
		philo->prev_philo = manager->philo[manager->nb_philo];
	if (id > 0 && id < manager->nb_philo)
		philo->next_philo = manager->philo[id + 1];
	else if (id == manager->nb_philo)
		philo->next_philo = manager->philo[1];
	pthread_mutex_init(&philo->left_fork, NULL);
	philo->right_fork = &philo->next_philo->left_fork;
}

void	philo_spawn(t_manager *manager)
{
	int	i;

	i = 1;
	while (i <= manager->nb_philo)
	{
		pthread_create(&manager->philo[i]->pthread, NULL,
			philo_main, manager->philo[i]);
		usleep(10);
		i++;
	}
}
