#include "../includes/philo.h"

static void	philo_die(t_philo *philo, bool print)
{
	if (print)
	{
		philo_log(philo, MSG_DIED);
		philo->manager->die = true;
	}
	if (philo->right_fork)
		pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
	philo->alive = false;
	if (print)
		pthread_mutex_unlock(&philo->manager->mutex_print);
}

void	*philo_monitor(void *philo_raw)
{
	t_philo		*philo;
	bool		since;
	bool		eat;

	philo = philo_raw;
	while (1)
	{
		since = get_time_ms() - philo->last_eat < philo->manager->time_to_die;
		eat = (philo->manager->nb_eat == -1
				|| philo->nb_eat < philo->manager->nb_eat);
		if (!since)
		{
			if (philo->manager)
				philo_die(philo, true);
			return (NULL);
		}
		else if (!eat)
		{
			if (philo->manager)
				philo_die(philo, false);
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}
