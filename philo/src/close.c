#include "../includes/philo.h"

void	set_error(int code, t_manager *manager)
{
	if (code == ERR_ARGSNUMBER)
	{
		ft_putstr(STDERR_FILENO, "invalid args NUMBER [nb philo] [t to");
		ft_putstr(STDERR_FILENO, " die] [t to eat] [t to sleep] (nb eat)\n");
	}
	else if (code == ERR_INVALIDARG)
		ft_putstr(STDERR_FILENO, "invalid args\n");
	else if (code == ERR_MALLOC)
		ft_putstr(STDERR_FILENO, "malloc failure\n");
	else
	{
		ft_putstr(STDERR_FILENO, "undefined error, code = ");
		ft_putnbr(STDERR_FILENO, code);
		ft_putchar(STDERR_FILENO, '\n');
	}
	manager->error = true;
}

static void	delete_philos(t_manager *manager)
{
	int	i;

	i = 1;
	while (i <= manager->nb_philo)
	{
		if (manager->philo[i])
		{
			manager->philo[i]->right_fork = NULL;
		}
		i++;
	}
	i = 1;
	while (i <= manager->nb_philo)
	{
		if (manager->philo[i])
		{
			pthread_join(manager->philo[i]->pthread, NULL);
			pthread_mutex_destroy(&manager->philo[i]->left_fork);
			free(manager->philo[i]);
		}
		i++;
	}
}

void	close_philo(t_manager *manager)
{
	if (manager->philo && !manager->error)
	{
		manager->die = true;
		delete_philos(manager);
		free(manager->philo);
		manager->die = false;
		pthread_mutex_destroy(&manager->mutex_print);
	}
}
