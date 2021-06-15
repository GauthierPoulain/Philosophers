#include "../includes/philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	philo->timestamp = get_time_ms();
	philo_log(philo, MSG_FORK);
	pthread_mutex_lock(philo->right_fork);
	philo->timestamp = get_time_ms();
	philo_log(philo, MSG_FORK);
	philo->timestamp = get_time_ms();
	philo_log(philo, MSG_EAT);
	usleep(philo->manager->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_sleep(t_philo *philo)
{
	philo->timestamp = get_time_ms();
	philo_log(philo, MSG_SLEEP);
	usleep(philo->manager->time_to_sleep * 1000);
}

void	*philo_main(void *philo_raw)
{
	t_philo	*philo;

	philo = philo_raw;
	philo->timestamp = get_time_ms();
	philo_log(philo, MSG_SPAWN);
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (NULL);
}
