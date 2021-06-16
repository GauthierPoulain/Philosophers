#include "../includes/philo.h"

static void	philo_die(t_philo *philo)
{
	if (philo->right_fork)
		pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
	philo_log(philo, MSG_DIED);
	philo->alive = false;
	philo->manager->die = true;
	pthread_mutex_unlock(&philo->manager->mutex_print);
}

void	*philo_monitor(void *philo_raw)
{
	t_philo	*philo;

	philo = philo_raw;
	while (philo->manager
		&& get_time_ms() - philo->last_eat < philo->manager->time_to_die
		&& (philo->manager->nb_eat == -1
			|| philo->nb_eat < philo->manager->nb_eat))
		usleep(100);
	if (philo->manager)
		philo_die(philo);
	philo->alive = false;
	return (NULL);
}
