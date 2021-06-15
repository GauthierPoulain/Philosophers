#include "../includes/philo.h"

void	philo_die(t_philo *philo)
{
	philo->manager->die = true;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(&philo->manager->mutex_die);
	philo->timestamp = get_time_ms();
	philo_log(philo, MSG_DIED);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	philo->timestamp = get_time_ms();
	philo_log(philo, MSG_FORK);
	if (!philo->right_fork)
	{
		pthread_mutex_unlock(&philo->left_fork);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	philo->timestamp = get_time_ms();
	philo_log(philo, MSG_FORK);
	philo->nb_eat++;
	philo->timestamp = get_time_ms();
	philo_log(philo, MSG_EAT);
	usleep(philo->manager->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_sleep(t_philo *philo)
{
	philo->timestamp = get_time_ms();
	philo_log(philo, MSG_SLEEP);
	usleep(philo->manager->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	philo->timestamp = get_time_ms();
	philo_log(philo, MSG_THINK);
}

void	*philo_monitor(void *philo_raw)
{
	t_philo	*philo;

	philo = philo_raw;
	while (get_time_ms() - philo->last_eat < philo->manager->time_to_die)
		;
	philo_die(philo);
	return (NULL);
}

void	*philo_main(void *philo_raw)
{
	t_philo	*philo;

	philo = philo_raw;
	if (pthread_create(&philo->monitor.pthread, NULL, philo_monitor, philo) != 0)
		philo_die(philo);
	philo->timestamp = get_time_ms();
	philo->last_eat = get_time_ms();
	philo_log(philo, MSG_SPAWN);
	while (!philo->manager->die && (philo->manager->nb_eat == -1
		|| philo->nb_eat < philo->manager->nb_eat))
	{
		if (!philo->manager->die)
			philo_eat(philo);
		if (!philo->manager->die)
			philo_sleep(philo);
		if (!philo->manager->die)
			philo_think(philo);
	}
	pthread_join(philo->monitor.pthread, NULL);
	return (NULL);
}
