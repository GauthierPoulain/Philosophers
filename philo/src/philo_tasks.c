#include "../includes/philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	philo_log(philo, MSG_FORK);
	if (philo->right_fork)
		pthread_mutex_lock(philo->right_fork);
	else
		return ;
	philo_log(philo, MSG_FORK);
	philo->nb_eat++;
	philo->last_eat = get_time_ms();
	philo_log(philo, MSG_EAT);
	if (philo->manager)
		usleep(philo->manager->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->left_fork);
	if (philo->right_fork)
		pthread_mutex_unlock(philo->right_fork);
	else
		return ;
}

void	philo_sleep(t_philo *philo)
{
	philo_log(philo, MSG_SLEEP);
	if (philo->manager)
		usleep(philo->manager->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	philo_log(philo, MSG_THINK);
}

void	*philo_main(void *philo_raw)
{
	t_philo	*philo;

	philo = philo_raw;
	philo->timestamp = get_time_ms();
	philo->last_eat = get_time_ms();
	philo->alive = true;
	pthread_create(&philo->monitor.pthread, NULL, philo_monitor, philo);
	if (PRINT_SPAWN)
		philo_log(philo, MSG_SPAWN);
	while (philo->alive && !philo->manager->die)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	pthread_join(philo->monitor.pthread, NULL);
	return (NULL);
}
