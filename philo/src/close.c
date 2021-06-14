#include "../includes/philo.h"

void	set_error(int code, t_manager *manager)
{
	if (code == ERR_ARGSNUMBER)
		ft_putstr(STDERR_FILENO,
			"invalid args NUMBER [nb philo] [t to die] [t to eat] (nb eat)\n");
	else if (code == ERR_INVALIDARG)
		ft_putstr(STDERR_FILENO, "invalid args\n");
	else if (code == ERR_MALLOC)
		ft_putstr(STDERR_FILENO, "malloc failure\n");
	else if (code == ERR_MUTEX)
		ft_putstr(STDERR_FILENO, "mutex failure\n");
	else if (code == ERR_THREAD)
		ft_putstr(STDERR_FILENO, "thread failure\n");
	else
	{
		ft_putstr(STDERR_FILENO, "undefined error, code = ");
		ft_putnbr(STDERR_FILENO, code);
		ft_putchar(STDERR_FILENO, '\n');
	}
	close_philo(EXIT_FAILURE, manager);
}

static void	delete_philos(t_manager *manager)
{
	int	i;

	i = 1;
	while (i <= manager->nb_philo)
	{
		if (manager->philo[i])
		{
			pthread_join(manager->philo[i]->pthread, NULL);
			pthread_mutex_destroy(&manager->philo[i]->left_fork);
			pthread_mutex_destroy(&manager->philo[i]->right_fork);
			free(manager->philo[i]);
		}
		i++;
	}
}

void	close_philo(int code, t_manager *manager)
{
	if (manager)
	{
		if (manager->philo)
		{
			delete_philos(manager);
			free(manager->philo);
		}
		free(manager);
	}
	exit(code);
}
